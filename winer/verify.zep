/**
 * 验证码。
 * -- 注意：本文件中取SESSION的位置，请替换成自己框架的方法。
 * @see http://document.thinkphp.cn/manual_3_2.html#verify
 */

namespace Winer;

class Verify {

    protected config =	[
        "seKey"     :  "winer_Verify",   // 验证码加密密钥
        "codeSet"   :  ["2","3","4","5","6","7","8","a","b","c","d","e","f","h","i","j","k","m","n","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","J","K","L","M","N","P","Q","R","T","U","V","W","X","Y"], // 验证码字符集合"
        "expire"    :  1800,            // 验证码过期时间（s）
        "useImgBg"  :  false,           // 使用背景图片 
        "fontSize"  :  25,              // 验证码字体大小(px)
        "angle"     :  0,				// 验证码角度。
        "useCurve"  :  false,           // 是否画混淆曲线
        "imageH"    :  100,             // 验证码图片高度
        "imageW"    :  100,             // 验证码图片宽度
        "length"    :  5,               // 验证码位数
        "fontttf"   :  "",              // 验证码字体，不设置随机获取
        "bg"        :  [243, 251, 254], // 背景颜色
        "reset"     :  true             // 验证成功后是否重置
    ];

    private _image   = NULL;     // 验证码图片实例
    private _color   = NULL;     // 验证码字体颜色

    /**
     * 架构方法 设置参数
     * @access public     
     * @param array config 配置参数
     */    
    public function __construct(array config = []) {
        let this->config = array_merge(this->config, config);
    }

    /**
     * 验证验证码是否正确
     * @access public
     * @param string code 用户验证码
     * @param string id 验证码标识     
     * @return bool 用户验证码是否正确
     */
    public function check(string code, string id = "") -> boolean {
    	var key;
        let key = this->authcode(this->config["seKey"]) . id;
        // 验证码不能为空
        var secode;
        let secode = _SESSION[key];
        if (empty(code) || empty(secode)) {
            return false;
        }
        // session 过期
        if (time() - secode["verify_time"] > this->config["expire"]) {
            unset(_SESSION[key]);
            return false;
        }
        if (this->authcode(strtoupper(code)) == secode["verify_code"]) {
            if (this->config["reset"]) {
                unset(_SESSION[key]);
            }
            return true;
        }
        return false;
    }

    /**
     * 输出验证码并把验证码的值保存的session中
     * 验证码保存到session的格式为： array("verify_code" => "验证码值", "verify_time" => "验证码创建时间");
     * @access public     
     * @param string id 要生成验证码的标识
     * @param string ttfPath 字体路径。
     * @param string bgPath 验证码背景图片路径。
     * @return void
     */
    public function entry(string id = "", string ttfPath = "", string bgPath = "") {
        // 图片宽(px)
        if (!this->config["imageW"]) {
        	let this->config["imageW"] = this->config["length"] * this->config["fontSize"] * 1.5 + this->config["length"] * this->config["fontSize"] / 2;
        }
        // 图片高(px)
        if (this->config["imageH"]) {
        	let this->config["imageH"] = this->config["fontSize"] * 2.5;
        }
        // 建立一幅 this->imageW x this->imageH 的图像
        let this->_image = imagecreate(this->config["imageW"], this->config["imageH"]); 
        // 设置背景
        imagecolorallocate(this->_image, this->config["bg"][0], this->config["bg"][1], this->config["bg"][2]); 

        // 验证码字体随机颜色
        let this->_color = imagecolorallocate(this->_image, mt_rand(1, 150), mt_rand(1, 150), mt_rand(1, 150));
        // 验证码字体
        let this->config["fontttf"] = ttfPath;

        if(this->config["useImgBg"]) {
            this->_background(bgPath);
        }
        if (this->config["useCurve"]) {
            // 绘干扰线
            this->_writeCurve();
        }

        // 绘验证码
        var code = []; // 验证码
        var codeNX = 0; // 验证码第N个字符的左边距
        int i = 0;
        var _len;
    	while i < this->config["length"] {
    		var _rand;
    		let _len = count(this->config["codeSet"]) - 1;
    		let _rand = mt_rand(0, _len);
    		let code[i] = this->config["codeSet"][_rand];
            let codeNX  = i * mt_rand(this->config["fontSize"]*1.2, this->config["fontSize"]*1.4);
            imagettftext(this->_image, this->config["fontSize"], this->config["angle"], codeNX, this->config["fontSize"]*1.6, this->_color, this->config["fontttf"], code[i]);
            let i++;
    	}

        // 保存验证码
        var key;
        let key    = this->authcode(this->config["seKey"]);
        let code   = this->authcode(strtoupper(implode("", code)));
        var secode = [];
        let secode["verify_code"] = code; 		// 把校验码保存到session
        let secode["verify_time"] = time();  	// 验证码创建时间

        let _SESSION[key.id] = secode;

        header("Cache-Control: private, max-age=0, no-store, no-cache, must-revalidate");
        header("Cache-Control: post-check=0, pre-check=0", false);		
        header("Pragma: no-cache");
        header("content-type: image/png");

        // 输出图像
        imagepng(this->_image);
        imagedestroy(this->_image);
    }

    /** 
     * 画一条由两条连在一起构成的随机正弦函数曲线作干扰线(你可以改成更帅的曲线函数) 
     *      
     *      高中的数学公式咋都忘了涅，写出来
     *		正弦型函数解析式：y=Asin(ωx+φ)+b
     *      各常数值对函数图像的影响：
     *        A：决定峰值（即纵向拉伸压缩的倍数）
     *        b：表示波形在Y轴的位置关系或纵向移动距离（上加下减）
     *        φ：决定波形与X轴位置关系或横向移动距离（左加右减）
     *        ω：决定周期（最小正周期T=2π/∣ω∣）
     *
     */
    private function _writeCurve() {
        var px = 0;
        var py = 0;
        var a;
        var b;
        var f;
        var t;
        var w;
        var px1;
        var px2;

        // 曲线前部分
        let a = mt_rand(1, this->config["imageH"]/2);                  			// 振幅
        let b = mt_rand(-this->config["imageH"]/4, this->config["imageH"]/4);   // Y轴方向偏移量
        let f = mt_rand(-this->config["imageH"]/4, this->config["imageH"]/4);   // X轴方向偏移量
        let t = mt_rand(this->config["imageH"], this->config["imageW"]*2);  	// 周期
        let w = (2* M_PI)/t;

        let px1 = 0;  // 曲线横坐标起始位置
        let px2 = floatval(mt_rand(intval(this->config["imageW"]/2), intval(this->config["imageW"] * 0.8)));  // 曲线横坐标结束位置

		let px = px2;
		var i;
		while px <= px2 {
			let px = px + 1;
			if (w != 0) {
                let py = floatval(a * sin(w*px + f)+ b + this->config["imageH"] / 2);  // y = Asin(ωx+φ) + b
                let i = (int) (this->config["fontSize"]/5);
                while (i > 0) {	
                    imagesetpixel(this->_image, px + i , py + i, this->_color);  // 这里(while)循环画像素点比imagettftext和imagestring用字体大小一次画出（不用这while循环）性能要好很多				
                    let i--;
                }
            }
		}
        
        // 曲线后部分
        let a = mt_rand(1, this->config["imageH"]/2);                  			// 振幅
        let f = mt_rand(-this->config["imageH"]/4, this->config["imageH"]/4);   // X轴方向偏移量
        let t = mt_rand(this->config["imageH"], this->config["imageW"]*2);  	// 周期
        let w = (2* M_PI)/t;		
        let b = py - a * sin(w*px + f) - this->config["imageH"]/2;
        let px1 = px2;
        let px2 = this->config["imageW"];

		let px = px1;
		while px <= px2 {
			let px = px + 1;
			if (w != 0) {
                let py = a * sin(w * px + f) + b + this->config["imageH"] / 2;  // y = Asin(ωx+φ) + b
                let i  = (int) (this->config["fontSize"] / 5);
                while (i > 0) {			
                    imagesetpixel(this->_image, px + i, py + i, this->_color);	
                    let i--;
                }
            }
		}
    }

    /**
     * 绘制背景图片
     * 注：如果验证码输出图片比较大，将占用比较多的系统资源
     * @param string bgPath 验证背景图片路径。
     */
    private function _background(string bgPath = "") {
        var data;
		let data = getimagesize(bgPath);
		var width;
		var height;
		let width  = data[0];
		let height = data[1];
        // Resample
        var bgImage;
        let bgImage = imagecreatefromjpeg(bgPath);
        imagecopyresampled(this->_image, bgImage, 0, 0, 0, 0, this->config["imageW"], this->config["imageH"], width, height);
        imagedestroy(bgImage);
    }

    /* 加密验证码 */
    private function authcode(str) -> string {
    	var key;
        let key = substr(md5(this->config["seKey"]), 5, 8);
        let str = substr(md5(str), 8, 10);
        return md5(key . str);
    }
}