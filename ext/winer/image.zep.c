
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * 图片处理驱动类，可配置图片处理库
 * 目前支持GD库和imagick
 * @see http://document.thinkphp.cn/manual_3_2.html#image
 */
ZEPHIR_INIT_CLASS(Winer_Image) {

	ZEPHIR_REGISTER_CLASS(Winer, Image, winer, image, winer_image_method_entry, 0);

	/**
	 * 图片资源
	 * @var resource
	 */
	zend_declare_property_null(winer_image_ce, SL("img"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/* 驱动相关常量定义 */
	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_GD"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_IMAGICK"), 2 TSRMLS_CC);

	/* 缩略图相关常量定义 */
	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_THUMB_SCALE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_THUMB_FILLED"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_THUMB_CENTER"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_THUMB_NORTHWEST"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_THUMB_SOUTHEAST"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_THUMB_FIXED"), 6 TSRMLS_CC);

	/* 水印相关常量定义 */
	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_NORTHWEST"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_NORTH"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_NORTHEAST"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_WEST"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_CENTER"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_EAST"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_SOUTHWEST"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_SOUTH"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(winer_image_ce, SL("IMAGE_WATER_SOUTHEAST"), 9 TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造方法，用于实例化一个图片处理对象
 * @param string $type 要使用的类库，默认使用GD库
 */
PHP_METHOD(Winer_Image, __construct) {

	zend_class_entry *_3;
	zval *imgname = NULL, *class_name = NULL, *_0;
	zval *t_param = NULL, *imgname_param = NULL, *_1, *_2 = NULL;
	int t, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &t_param, &imgname_param);

	if (!t_param) {
		t = 1;
	} else {
		t = zephir_get_intval(t_param);
	}
	if (!imgname_param) {
		ZEPHIR_INIT_VAR(imgname);
		ZVAL_EMPTY_STRING(imgname);
	} else {
		zephir_get_strval(imgname, imgname_param);
	}


	if (t == 1) {
		ZEPHIR_INIT_VAR(class_name);
		ZVAL_STRING(class_name, "Gd", 1);
	} else if (t == 2) {
		ZEPHIR_INIT_NVAR(class_name);
		ZVAL_STRING(class_name, "Imagick", 1);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不支持的图片处理库类型", "winer/image.zep", 50);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "winer\\Image\\Driver\\", class_name);
	ZEPHIR_CPY_WRT(class_name, _0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fetch_safe_class(_2, class_name);
	_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_1, _3);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, imgname);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("img"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 打开一幅图像
 * @param string imgname 图片路径
 * @return Object 当前图片处理库对象
 */
PHP_METHOD(Winer_Image, open) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *imgname_param = NULL, *_0;
	zval *imgname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &imgname_param);

	zephir_get_strval(imgname, imgname_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "open", NULL, imgname);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 保存图片
 * @param string  imgname 图片保存名称
 * @param string  type    图片类型
 * @param integer quality 图像质量      
 * @param boolean interlace 是否对JPEG类型图片设置隔行扫描
 * @return Object 当前图片处理库对象
 */
PHP_METHOD(Winer_Image, save) {

	zend_bool interlace;
	int quality, ZEPHIR_LAST_CALL_STATUS;
	zval *imgname_param = NULL, *t = NULL, *quality_param = NULL, *interlace_param = NULL, *_0, *_1;
	zval *imgname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &imgname_param, &t, &quality_param, &interlace_param);

	zephir_get_strval(imgname, imgname_param);
	if (!t) {
		t = ZEPHIR_GLOBAL(global_null);
	}
	if (!quality_param) {
		quality = 80;
	} else {
		quality = zephir_get_intval(quality_param);
	}
	if (!interlace_param) {
		interlace = 1;
	} else {
		interlace = zephir_get_boolval(interlace_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, quality);
	ZEPHIR_CALL_METHOD(NULL, _0, "save", NULL, imgname, t, _1, (interlace ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 返回图片宽度
 * @return integer 图片宽度
 */
PHP_METHOD(Winer_Image, width) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "width", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回图片高度
 * @return integer 图片高度
 */
PHP_METHOD(Winer_Image, height) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "height", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回图像类型
 * @return string 图片类型
 */
PHP_METHOD(Winer_Image, type) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "type", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回图像MIME类型
 * @return string 图像MIME类型
 */
PHP_METHOD(Winer_Image, mime) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "mime", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回图像尺寸数组 0 - 图片宽度，1 - 图片高度
 * @return array 图片尺寸
 */
PHP_METHOD(Winer_Image, size) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "size", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 裁剪图片
 * @param  integer w      裁剪区域宽度
 * @param  integer h      裁剪区域高度
 * @param  integer x      裁剪区域x坐标
 * @param  integer y      裁剪区域y坐标
 * @param  integer width  图片保存宽度
 * @param  integer height 图片保存高度
 * @return Object         当前图片处理库对象
 */
PHP_METHOD(Winer_Image, crop) {

	zval *w_param = NULL, *h_param = NULL, *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6;
	int w, h, x, y, width, height, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 4, &w_param, &h_param, &x_param, &y_param, &width_param, &height_param);

	w = zephir_get_intval(w_param);
	h = zephir_get_intval(h_param);
	if (!x_param) {
		x = 0;
	} else {
		x = zephir_get_intval(x_param);
	}
	if (!y_param) {
		y = 0;
	} else {
		y = zephir_get_intval(y_param);
	}
	if (!width_param) {
		width = 0;
	} else {
		width = zephir_get_intval(width_param);
	}
	if (!height_param) {
		height = 0;
	} else {
		height = zephir_get_intval(height_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, w);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, h);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, x);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, y);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, width);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, height);
	ZEPHIR_CALL_METHOD(NULL, _0, "crop", NULL, _1, _2, _3, _4, _5, _6);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 生成缩略图
 * @param  integer width  缩略图最大宽度
 * @param  integer height 缩略图最大高度
 * @param  integer t      缩略图裁剪类型
 * @return Object         当前图片处理库对象
 */
PHP_METHOD(Winer_Image, thumb) {

	zval *width_param = NULL, *height_param = NULL, *t_param = NULL, *_0, *_1, *_2, *_3;
	int width, height, t, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &width_param, &height_param, &t_param);

	width = zephir_get_intval(width_param);
	height = zephir_get_intval(height_param);
	if (!t_param) {
		t = 1;
	} else {
		t = zephir_get_intval(t_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, width);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, height);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, t);
	ZEPHIR_CALL_METHOD(NULL, _0, "thumb", NULL, _1, _2, _3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 添加水印
 * @param  string  source 水印图片路径
 * @param  integer locate 水印位置
 * @param  integer alpha  水印透明度
 * @return Object          当前图片处理库对象
 */
PHP_METHOD(Winer_Image, water) {

	int locate, alpha, ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *locate_param = NULL, *alpha_param = NULL, *_0, *_1, *_2;
	zval *source = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &source_param, &locate_param, &alpha_param);

	zephir_get_strval(source, source_param);
	if (!locate_param) {
		locate = 9;
	} else {
		locate = zephir_get_intval(locate_param);
	}
	if (!alpha_param) {
		alpha = 80;
	} else {
		alpha = zephir_get_intval(alpha_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, locate);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, alpha);
	ZEPHIR_CALL_METHOD(NULL, _0, "water", NULL, source, _1, _2);
	zephir_check_call_status();
	RETURN_THIS();

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
 * @return Object          当前图片处理库对象
 */
PHP_METHOD(Winer_Image, text) {

	int locate, offset, angle, ZEPHIR_LAST_CALL_STATUS;
	zval *color = NULL;
	zval *text, *font, *size, *color_param = NULL, *locate_param = NULL, *offset_param = NULL, *angle_param = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 4, &text, &font, &size, &color_param, &locate_param, &offset_param, &angle_param);

	if (!color_param) {
		ZEPHIR_INIT_VAR(color);
		ZVAL_STRING(color, "#00000000", 1);
	} else {
		zephir_get_strval(color, color_param);
	}
	if (!locate_param) {
		locate = 9;
	} else {
		locate = zephir_get_intval(locate_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}
	if (!angle_param) {
		angle = 0;
	} else {
		angle = zephir_get_intval(angle_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, locate);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, offset);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, angle);
	ZEPHIR_CALL_METHOD(NULL, _0, "text", NULL, text, font, size, color, _1, _2, _3);
	zephir_check_call_status();
	RETURN_THIS();

}

