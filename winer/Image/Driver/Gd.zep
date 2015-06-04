// Gd库封装不支持GIF格式图片。
namespace Winer\Image\Driver;

use Winer\Image;

class Gd {
    /**
     * 图像资源对象
     * @var resource
     */
    private img;

    /**
     * 图像信息，包括width,height,type,mime,size
     * @var array
     */
    private info;

    /**
     * 构造方法，可用于打开一张图像
     * @param string imgname 图像路径
     */
    public function __construct(string imgname = null) {
    	if strlen(imgname) > 0 {
    		this->open(imgname);
    	}
    }

    /**
     * 打开一张图像
     * @param  string imgname 图像路径
     */
    public function open(imgname){
        // 检测图像文件
        if !is_file(imgname) {
        	throw new \Exception("不存在的图像文件");
        }

        // 获取图像信息
        var info;
        let info = getimagesize(imgname);

        // 检测图像合法性
        if (false === info || (IMAGETYPE_GIF === info[2] && empty(info["bits"]))) {
            throw new \Exception("非法图像文件");
        }

        // 设置图像信息
        let this->info = [
            "width"  : info[0],
            "height" : info[1],
            "type"   : image_type_to_extension(info[2], false),
            "mime"   : info["mime"]
        ];

        // 销毁已存在的图像
        if !empty(this->img) {
        	imagedestroy(this->img);
        }

        // 打开图像
    	var fun;
        let fun = "imagecreatefrom" . this->info["type"];
        let this->img = {fun}(imgname);
    }

    /**
     * 保存图像
     * @param  string  imgname   图像保存名称
     * @param  string  type      图像类型
     * @param  integer quality   图像质量     
     * @param  boolean interlace 是否对JPEG类型图像设置隔行扫描
     */
    public function save(string imgname, type = null, quality = 80, boolean interlace = true) {
        if (empty(this->img)) {
        	throw new \Exception("没有可以被保存的图像资源");
        }

        // 自动获取图像类型
        if (is_null($type)) {
            let type = this->info["type"];
        } else {
            let type = strtolower(type);
        }
        // 保存图像
        if ("jpeg" == type || "jpg" == type) {
            // JPEG图像设置隔行扫描
            imageinterlace(this->img, interlace);
            imagejpeg(this->img, imgname, quality);
        } else {
        	var fun;
            let fun = "image" . type;
            {fun}(this->img, imgname);
        }
    }

    /**
     * 返回图像宽度
     * @return integer 图像宽度
     */
    public function width() {
        if(empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return this->info["width"];
    }

    /**
     * 返回图像高度
     * @return integer 图像高度
     */
    public function height(){
        if(empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return this->info["height"];
    }

    /**
     * 返回图像类型
     * @return string 图像类型
     */
    public function type(){
        if(empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return this->info["type"];
    }

    /**
     * 返回图像MIME类型
     * @return string 图像MIME类型
     */
    public function mime(){
        if(empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return this->info["mime"];
    }

    /**
     * 返回图像尺寸数组 0 - 图像宽度，1 - 图像高度
     * @return array 图像尺寸
     */
    public function size(){
        if(empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return [this->info["width"], this->info["height"]];
    }

    /**
     * 裁剪图像
     * @param  integer w      裁剪区域宽度
     * @param  integer h      裁剪区域高度
     * @param  integer x      裁剪区域x坐标
     * @param  integer y      裁剪区域y坐标
     * @param  integer width  图像保存宽度
     * @param  integer height 图像保存高度
     */
    public function crop(w, h, x = 0, y = 0, width = null, height = null) {
        if (empty(this->img)) {
        	throw new \Exception("没有可以被裁剪的图像资源");
        }

        // 设置保存尺寸
        if empty(width) {
        	let width = w;
        }
        if empty($height) {
        	let height = h;
        }

		var img;
		var color;
        do {
            // 创建新图像
            let img = imagecreatetruecolor(width, height);
            // 调整默认颜色
            let color = imagecolorallocate(img, 255, 255, 255);
            imagefill(img, 0, 0, $color);
            // 裁剪
            imagecopyresampled(img, this->img, 0, 0, x, y, width, height, w, h);
            imagedestroy(this->img); // 销毁原图
            // 设置新图像
            let this->img = img;
        } while(false);

        let this->info["width"]  = width;
        let this->info["height"] = height;
    }

    /**
     * 生成缩略图
     * @param  integer width  缩略图最大宽度
     * @param  integer height 缩略图最大高度
     * @param  integer type   缩略图裁剪类型
     */
    public function thumb(width, height, int type = Image::IMAGE_THUMB_SCALE){
        if (empty(this->img)) {
        	throw new \Exception("没有可以被缩略的图像资源");
        }

        // 原图宽度和高度
        var w;
        var h;
        var x = 0;
        var y = 0;
        let w = this->info["width"];
        let h = this->info["height"];

        /* 计算缩略图生成的必要参数 */
        var scale;
        switch (type) {
            /* 等比例缩放 */
            case Image::IMAGE_THUMB_SCALE:
                // 原图尺寸小于缩略图尺寸则不进行缩略
                if (w < width && h < height) {
                	return;
                }
                // 计算缩放比例
                let scale = min(width/w, height/h);

                // 设置缩略图的坐标及宽度和高度
                let width  = w * scale;
                let height = h * scale;
                break;

            /* 居中裁剪 */
            case Image::IMAGE_THUMB_CENTER:
                // 计算缩放比例
                let scale = max(width/w, height/h);
                // 设置缩略图的坐标及宽度和高度
                let w = width/scale;
                let h = height/scale;
                let x = (this->info["width"] - w)/2;
                let y = (this->info["height"] - h)/2;
                break;

            /* 左上角裁剪 */
            case Image::IMAGE_THUMB_NORTHWEST:
                // 计算缩放比例
                let scale = max(width/w, height/h);

                // 设置缩略图的坐标及宽度和高度
                let w = width/scale;
                let h = height/scale;
                break;

            /* 右下角裁剪 */
            case Image::IMAGE_THUMB_SOUTHEAST:
                // 计算缩放比例
                let scale = max(width/w, height/h);
                // 设置缩略图的坐标及宽度和高度
                let w = width/scale;
                let h = height/scale;
                let x = this->info["width"] - w;
                let y = this->info["height"] - h;
                break;

            /* 填充 */
            case Image::IMAGE_THUMB_FILLED:
                // 计算缩放比例
                if (w < width && h < $height){
                    let scale = 1;
                } else {
                    let scale = min(width/w, height/h);
                }

                // 设置缩略图的坐标及宽度和高度
                var neww, newh, posx, posy;
                let neww = w * scale;
                let newh = h * scale;
                let posx = (width  - w * scale)/2;
                let posy = (height - h * scale)/2;

                do {
                    // 创建新图像
                    var img;
                    let img = imagecreatetruecolor(width, height);
                    // 调整默认颜色
                    var color;
                    let color = imagecolorallocate(img, 255, 255, 255);
                    imagefill(img, 0, 0, $color);
                    // 裁剪
                    imagecopyresampled(img, this->img, posx, posy, x, y, neww, newh, w, h);
                    imagedestroy(this->img); // 销毁原图
                    let this->img = img;
                } while(false);
                
                let this->info["width"]  = width;
                let this->info["height"] = height;
                return;

            /* 固定 */
            case Image::IMAGE_THUMB_FIXED:
                let x = 0;
                let y = 0;
                break;

            default:
            	throw new \Exception("不支持的缩略图裁剪类型");
        }

        /* 裁剪图像 */
        this->crop(w, h, x, y, width, height);
    }

    /**
     * 添加水印
     * @param  string  source 水印图片路径
     * @param  integer locate 水印位置
     * @param  integer alpha  水印透明度
     */
    public function water(source, locate = Image::IMAGE_WATER_SOUTHEAST, alpha = 80) {
        // 资源检测
        if (empty(this->img)) {
        	throw new \Exception("没有可以被添加水印的图像资源");
        }
        if(!is_file(source)) {
        	throw new \Exception("水印图像不存在");
        }

        //获取水印图像信息
        var info;
        let info = getimagesize($source);
        if (false === info || (IMAGETYPE_GIF === info[2] && empty(info["bits"]))) {
        	throw new \Exception("非法水印文件");
        }

        // 创建水印图像资源
        var fun;
        var water;
        let fun = "imagecreatefrom" . image_type_to_extension(info[2], false);
        let water  = {fun}($source);

        // 设定水印图像的混色模式
        imagealphablending(water, true);

        /* 设定水印位置 */
        var x;
        var y;
        switch (locate) {
            /* 右下角水印 */
            case Image::IMAGE_WATER_SOUTHEAST:
                let x = this->info["width"] - info[0];
                let y = this->info["height"] - info[1];
                break;

            /* 左下角水印 */
            case Image::IMAGE_WATER_SOUTHWEST:
                let x = 0;
                let y = this->info["height"] - info[1];
                break;

            /* 左上角水印 */
            case Image::IMAGE_WATER_NORTHWEST:
                let x = 0;
                let y = 0;
                break;

            /* 右上角水印 */
            case Image::IMAGE_WATER_NORTHEAST:
                let x = this->info["width"] - info[0];
                let y = 0;
                break;

            /* 居中水印 */
            case Image::IMAGE_WATER_CENTER:
                let x = (this->info["width"] - info[0])/2;
                let y = (this->info["height"] - info[1])/2;
                break;

            /* 下居中水印 */
            case Image::IMAGE_WATER_SOUTH:
                let x = (this->info["width"] - info[0])/2;
                let y = this->info["height"] - info[1];
                break;

            /* 右居中水印 */
            case Image::IMAGE_WATER_EAST:
                let x = this->info["width"] - info[0];
                let y = (this->info["height"] - info[1])/2;
                break;

            /* 上居中水印 */
            case Image::IMAGE_WATER_NORTH:
                let x = (this->info["width"] - info[0])/2;
                let y = 0;
                break;

            /* 左居中水印 */
            case Image::IMAGE_WATER_WEST:
                let x = 0;
                let y = (this->info["height"] - info[1])/2;
                break;

            default:
                /* 自定义水印坐标 */
                if(is_array(locate)){
                	let x = locate[0];
                	let y = locate[1];
                } else {
                	throw new \Exception("不支持的水印位置类型");
                }
        }

        do{
            // 添加水印
            var src;
            var color;
            let src = imagecreatetruecolor(info[0], info[1]);
            // 调整默认颜色
            let color = imagecolorallocate(src, 255, 255, 255);
            imagefill(src, 0, 0, color);

            imagecopy(src, this->img, 0, 0, x, y, info[0], info[1]);
            imagecopy(src, water, 0, 0, 0, 0, info[0], info[1]);
            imagecopymerge(this->img, src, x, y, 0, 0, info[0], info[1], alpha);

            // 销毁零时图片资源
            imagedestroy(src);
        } while(false);

        //销毁水印资源
        imagedestroy(water);
    }

    /**
     * 图像添加文字
     * @param  string  text   添加的文字
     * @param  string  font   字体路径
     * @param  integer size   字号
     * @param  string  color  文字颜色
     * @param  integer locate 文字写入位置
     * @param  integer offset 文字相对当前位置的偏移量
     * @param  integer angle  文字倾斜角度
     */
    public function text(text, font, size, color = "#00000000", locate = Image::IMAGE_WATER_SOUTHEAST, offset = 0, angle = 0) {
        // 资源检测
        if (empty(this->img)) {
        	throw new \Exception("没有可以被写入文字的图像资源");
        }
        if (!is_file($font)) {
        	throw new \Exception("不存在的字体文件：" . font);
        }

        // 获取文字信息
        var info;
        var minx;
        var maxx;
        var miny;
        var maxy;
        let info = imagettfbbox(size, angle, font, text);
        let minx = min(info[0], info[2], info[4], info[6]); 
        let maxx = max(info[0], info[2], info[4], info[6]); 
        let miny = min(info[1], info[3], info[5], info[7]); 
        let maxy = max(info[1], info[3], info[5], info[7]); 

        /* 计算文字初始坐标和尺寸 */
        var x;
        var y;
        var w;
        var h;
        let x = floatval(minx);
        let y = floatval(abs(miny));
        let w = maxx - minx;
        let h = maxy - miny;

        /* 设定文字位置 */
        switch (locate) {
            /* 右下角文字 */
            case Image::IMAGE_WATER_SOUTHEAST:
                let x += this->info["width"]  - w;
                let y += this->info["height"] - h;
                break;

            /* 左下角文字 */
            case Image::IMAGE_WATER_SOUTHWEST:
                let y += this->info["height"] - h;
                break;

            /* 左上角文字 */
            case Image::IMAGE_WATER_NORTHWEST:
                // 起始坐标即为左上角坐标，无需调整
                break;

            /* 右上角文字 */
            case Image::IMAGE_WATER_NORTHEAST:
                let x += this->info["width"] - w;
                break;

            /* 居中文字 */
            case Image::IMAGE_WATER_CENTER:
                let x += floatval((this->info["width"]  - w)/2);
                let y += floatval((this->info["height"] - h)/2);
                break;

            /* 下居中文字 */
            case Image::IMAGE_WATER_SOUTH:
                let x += floatval((this->info["width"] - w)/2);
                let y += floatval(this->info["height"] - h);
                break;

            /* 右居中文字 */
            case Image::IMAGE_WATER_EAST:
                let x += this->info["width"] - w;
                let y += floatval((this->info["height"] - h)/2);
                break;

            /* 上居中文字 */
            case Image::IMAGE_WATER_NORTH:
                let x += floatval((this->info["width"] - w)/2);
                break;

            /* 左居中文字 */
            case Image::IMAGE_WATER_WEST:
                let y += floatval((this->info["height"] - h)/2);
                break;

            default:
                /* 自定义文字坐标 */
                var posx;
                var posy;
                if(is_array(locate)){
                	let posx = locate[0];
                	let posy = locate[1];
                    let x += posx;
                    let y += posy;
                } else {
                	throw new \Exception("不支持的文字位置类型");
                }
        }

        /* 设置偏移量 */
        var ox;
        var oy;
        if (is_array(offset)) {
            let offset = array_map("intval", offset);
            let ox = offset[0];
            let oy = offset[1];
        } else{
            let offset = intval(offset);
            let ox = offset;
            let oy = offset;
        }

        /* 设置颜色 */
        if(is_string(color) && 0 === strpos(color, "#")){
            let color = str_split(substr(color, 1), 2);
            let color = array_map("hexdec", color);
            if (empty(color[3]) || color[3] > 127) {
                let color[3] = 0;
            }
        } elseif (!is_array(color)) {
        	throw new \Exception("错误的颜色值");
        }

        do {
            /* 写入文字 */
            var col;
            let col = imagecolorallocatealpha(this->img, color[0], color[1], color[2], color[3]);
            imagettftext(this->img, size, angle, x + ox, y + oy, col, font, text);
        } while(false);
    }

    /**
     * 析构方法，用于销毁图像资源
     */
    public function __destruct() {
    	if (empty(this->img) == false) {
    		imagedestroy(this->img);
    	}
    }
}