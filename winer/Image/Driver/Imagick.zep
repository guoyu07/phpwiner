namespace Winer\Image\Driver;
use Winer\Image;

class Imagick {
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
    public function __construct(imgname = null) {
    	if strlen(imgname) {
			this->open(imgname);
    	}
    }

    /**
     * 打开一张图像
     * @param  string imgname 图像路径
     */
    public function open(imgname){
        // 检测图像文件
        if (!is_file(imgname)) {
        	throw new \Exception("不存在的图像文件");
        }

        // 销毁已存在的图像
        if (empty(this->img) == false) {
        	this->img->destroy();
        }

        // 载入图像
        let this->img = new \Imagick(realpath(imgname));

        //设置图像信息
        let this->info = [
            "width"  : this->img->getImageWidth(),
            "height" : this->img->getImageHeight(),
            "type"   : strtolower(this->img->getImageFormat()),
            "mime"   : this->img->getImageMimeType()
        ];
    }

    /**
     * 保存图像
     * @param  string  imgname   图像保存名称
     * @param  string  type      图像类型
     * @param  integer quality   JPEG图像质量      
     * @param  boolean interlace 是否对JPEG类型图像设置隔行扫描
     */
    public function save(imgname, type = null, quality = 80, boolean interlace = true){
        if(empty(this->img)) {
        	throw new \Exception("没有可以被保存的图像资源");
        }
        // 设置图片类型
        if(is_null(type)){
            let type = this->info["type"];
        } else {
            let type = strtolower(type);
            this->img->setImageFormat(type);
        }
        // JPEG图像设置隔行扫描
        if("jpeg" == type || "jpg" == type){
            this->img->setImageInterlaceScheme(1);
        }
        // 设置图像质量
        this->img->setImageCompressionQuality(quality); 
        // 去除图像配置信息
        this->img->stripImage();
        // 保存图像
        let imgname = realpath(dirname(imgname)) . "/" . basename(imgname); //强制绝对路径
        if ("gif" == type) {
            this->img->writeImages(imgname, true);
        } else {
            this->img->writeImage(imgname);
        }
    }

    /**
     * 返回图像宽度
     * @return integer 图像宽度
     */
    public function width(){
        if (empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return this->info["width"];
    }

    /**
     * 返回图像高度
     * @return integer 图像高度
     */
    public function height(){
        if (empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return this->info["height"];
    }

    /**
     * 返回图像类型
     * @return string 图像类型
     */
    public function type() {
        if (empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return this->info["type"];
    }

    /**
     * 返回图像MIME类型
     * @return string 图像MIME类型
     */
    public function mime(){
        if (empty(this->img)) {
        	throw new \Exception("没有指定图像资源");
        }
        return this->info["mime"];
    }

    /**
     * 返回图像尺寸数组 0 - 图像宽度，1 - 图像高度
     * @return array 图像尺寸
     */
    public function size(){
        if (empty(this->img)) {
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
    public function crop(w, h, x = 0, y = 0, width = null, height = null){
        if(empty(this->img)) {
        	throw new \Exception("没有可以被裁剪的图像资源");
        }
        // 设置保存尺寸
        if (empty(width)) {
        	let width = w;
        }
        if (empty(height)) {
        	let height = h;
        }
        this->_crop(w, h, x, y, width, height);
    }

    /* 裁剪图片，内部调用 */
    private function _crop(w, h, x, y, width, height, img = null){
    	if(is_null(img)) {
    		let img = this->img;
    	}

        // 裁剪
        var info;
        let info = this->info;
        if(x != 0 || y != 0 || w != info["width"] || h != info["height"]){
            img->cropImage(w, h, x, y);
            img->setImagePage(w, h, 0, 0); // 调整画布和图片一致
        }
        
        // 调整大小
        if (w != width || h != height) {
            img->sampleImage(width, height);
        }

        // 设置缓存尺寸
        let this->info["width"]  = w;
        let this->info["height"] = h;
    }

    /**
     * 生成缩略图
     * @param  integer width  缩略图最大宽度
     * @param  integer height 缩略图最大高度
     * @param  integer type   缩略图裁剪类型
     */
    public function thumb(width, height, type = Image::IMAGE_THUMB_SCALE) {
        if (empty(this->img)) {
        	throw new \Exception("没有可以被缩略的图像资源");
        }

        // 原图宽度和高度
        var w;
        var h;
        var y = 0;
        var x = 0;
        let w = this->info["width"];
        let h = this->info["height"];

        /* 计算缩略图生成的必要参数 */
        var scale;
        switch (type) {
            /* 等比例缩放 */
            case Image::IMAGE_THUMB_SCALE:
                // 原图尺寸小于缩略图尺寸则不进行缩略
                if(w < width && h < height) {
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
                if (w < width && h < height) {
                    let scale = 1;
                } else {
                    let scale = min(width/w, height/h);
                }
                // 设置缩略图的坐标及宽度和高度
                var neww;
                var newh;
                var posx;
                var posy;
                let neww = w * scale;
                let newh = h * scale;
                let posx = (width  - w * scale)/2;
                let posy = (height - h * scale)/2;

                // 创建一张新图像
                var newimg;
                let newimg = new \Imagick();
                newimg->newImage(width, height, "white", this->info["type"]);

                if ("gif" == this->info["type"]) {
                	var imgs;
                	var img;
                	var image;
                    let imgs = this->img->coalesceImages();
                    let img  = new \Imagick();
                    this->img->destroy(); // 销毁原图

                    // 循环填充每一帧
                    do {
                        // 填充图像
                        let image = this->inside_fill(newimg, posx, posy, neww, newh, imgs);
                        img->addImage(image);
                        img->setImageDelay(imgs->getImageDelay());
                        img->setImagePage(width, height, 0, 0);
                        image->destroy(); // 销毁零时图片
                    } while (imgs->nextImage());

                    // 压缩图片
                    this->img->destroy();
                    let this->img = img->deconstructImages();
                    imgs->destroy(); // 销毁零时图片
                    img->destroy(); // 销毁零时图片
                } else {
                    // 填充图像
                    let img = this->inside_fill(newimg, posx, posy, neww, newh);
                    // 销毁原图
                    this->img->destroy();
                    let this->img = img;
                }

                // 设置新图像属性
                let this->info["width"]  = width;
                let this->info["height"] = height;
                return;

            /* 固定 */
            case Image::IMAGE_THUMB_FIXED:
                break;

            default:
            	throw new \Exception("不支持的缩略图裁剪类型");
        }
        /* 裁剪图像 */
        this->crop(w, h, x, y, width, height);
    }

    /* 填充指定图像，内部使用 */
    private function inside_fill(newimg, posx, posy, neww, newh, img = null) {
    	if (is_null(img)) {
        	let img = this->img;
        }
        /* 将指定图片绘入空白图片 */
        var draw;
        var image;
        let draw = new \ImagickDraw();
        draw->composite(img->getImageCompose(), posx, posy, neww, newh, img);
        // 暂时未找到替换的方法。
        let image = clone newimg;
        image->drawImage(draw);
        draw->destroy();
        return image;
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
        if (!is_file(source)) {
        	throw new \Exception("水印图像不存在");
        }

        // 创建水印图像资源
        var water;
        var info;
        let water = new \Imagick(realpath(source));
        let info  = [water->getImageWidth(), water->getImageHeight()];

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
                if (is_array(locate)) {
                	let x = locate[0];
                	let y = locate[1];
                } else {
                	throw new \Exception("不支持的水印位置类型");
                }
        }

        // 创建绘图资源
        var draw;
        let draw = new \ImagickDraw();
        draw->composite(water->getImageCompose(), x, y, info[0], info[1], water);
        
        if ("gif" == this->info["type"]) {
        	var img;
            let img = this->img->coalesceImages();
            this->img->destroy(); // 销毁原图

            do{
                // 添加水印
                img->drawImage(draw);
            } while (img->nextImage());

            // 压缩图片
            let this->img = img->deconstructImages();
            img->destroy(); // 销毁零时图片

        } else {
            // 添加水印
            this->img->drawImage(draw);
        }

        // 销毁水印资源
        draw->destroy();
        water->destroy();
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
    public function text(text, font, size, color = "#00000000", locate = Image::IMAGE_WATER_SOUTHEAST, offset = 0, angle = 0){
        // 资源检测
        if (empty(this->img)) {
        	throw new \Exception("没有可以被写入文字的图像资源");
        }
        if (!is_file(font)) {
        	throw new \Exception("不存在的字体文件：{font}");
        }

        // 获取颜色和透明度
        var value;
        var alp;
        var col;
        if (is_array(color)) {
            let color = array_map("dechex", color);
            // 未解决带引用的变量问题。
            for value in color {
            	let value = str_pad(value, 2, "0", STR_PAD_LEFT);
            }
            let color = "#" . implode("", color);
        } elseif(!is_string(color) || 0 !== strpos(color, "#")) {
        	throw new \Exception("错误的颜色值");
        }
        let col = substr(color, 0, 7);
        let alp = strlen(color) == 9 ? substr(color, -2) : 0;
        

        //获取文字信息
        var draw;
        let draw = new \ImagickDraw();
        draw->setFont(realpath(font));
        draw->setFontSize(size);
        draw->setFillColor(col);
        draw->setFillAlpha(1-hexdec(alp)/127);
        draw->setTextAntialias(true);
        draw->setStrokeAntialias(true);
        
        var metrics;
        let metrics = this->img->queryFontMetrics(draw, text);

        /* 计算文字初始坐标和尺寸 */
        var x = 0.0;
        var y = 0.0;
        var w;
        var h;
        let y = floatval(metrics["ascender"]);
        let w = metrics["textWidth"];
        let h = metrics["textHeight"];

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
                let y += this->info["height"] - h;
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
        if(is_array(offset)){
            let offset = array_map("intval", offset);
            let ox = locate[0];
            let oy = locate[1];
        } else{
            let offset = intval(offset);
            let ox = offset;
            let oy = offset;
        }

        /* 写入文字 */
        if("gif" == this->info["type"]){
        	var img;
            let img = this->img->coalesceImages();
            this->img->destroy(); // 销毁原图
            do{
                img->annotateImage(draw, x + ox, y + oy, angle, text);
            } while (img->nextImage());

            // 压缩图片
            let this->img = img->deconstructImages();
            img->destroy(); // 销毁零时图片
        } else {
            this->img->annotateImage(draw, x + ox, y + oy, angle, text);
        }
        draw->destroy();
    }

    /**
     * 析构方法，用于销毁图像资源
     */
    public function __destruct() {
	    if (empty(this->img) == false) {
	    	this->img->destroy();
	    }
    }
}