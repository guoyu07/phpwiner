
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Winer_Image_Driver_Imagick) {

	ZEPHIR_REGISTER_CLASS(Winer\\Image\\Driver, Imagick, winer, image_driver_imagick, winer_image_driver_imagick_method_entry, 0);

	/**
	 * 图像资源对象
	 * @var resource
	 */
	zend_declare_property_null(winer_image_driver_imagick_ce, SL("img"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 图像信息，包括width,height,type,mime,size
	 * @var array
	 */
	zend_declare_property_null(winer_image_driver_imagick_ce, SL("info"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造方法，可用于打开一张图像
 * @param string imgname 图像路径
 */
PHP_METHOD(Winer_Image_Driver_Imagick, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *imgname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &imgname);

	if (!imgname) {
		imgname = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_fast_strlen_ev(imgname)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "open", NULL, imgname);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 打开一张图像
 * @param  string imgname 图像路径
 */
PHP_METHOD(Winer_Image_Driver_Imagick, open) {

	zval *_7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL;
	zval *imgname, *_0 = NULL, *_2, *_3, *_4, *_5 = NULL, *_8 = NULL, *_9, *_10, *_11, *_12, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &imgname);



	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, imgname);
	zephir_check_call_status();
	if (!zephir_is_true(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不存在的图像文件", "winer/Image/Driver/Imagick.zep", 34);
		return;
	}
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_2) == 0) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _3, "destroy", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_5, "realpath", &_6, imgname);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("img"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	array_init_size(_7, 6);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_8, _3, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&_7, SL("width"), &_8, PH_COPY | PH_SEPARATE);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_8, _9, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&_7, SL("height"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_10);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_8, _11, "getimageformat", NULL);
	zephir_check_call_status();
	zephir_fast_strtolower(_10, _8);
	zephir_array_update_string(&_7, SL("type"), &_10, PH_COPY | PH_SEPARATE);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_13, _12, "getimagemimetype", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&_7, SL("mime"), &_13, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("info"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 保存图像
 * @param  string  imgname   图像保存名称
 * @param  string  type      图像类型
 * @param  integer quality   JPEG图像质量      
 * @param  boolean interlace 是否对JPEG类型图像设置隔行扫描
 */
PHP_METHOD(Winer_Image_Driver_Imagick, save) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool interlace, _4;
	zval *imgname = NULL, *type = NULL, *quality = NULL, *interlace_param = NULL, *_0, *_1, *_2 = NULL, _3, _5, *_6, *_7 = NULL, *_9 = NULL, *_11, _12, *_13, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &imgname, &type, &quality, &interlace_param);

	ZEPHIR_SEPARATE_PARAM(imgname);
	if (!type) {
		ZEPHIR_CPY_WRT(type, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(type);
	}
	if (!quality) {
		ZEPHIR_INIT_VAR(quality);
		ZVAL_LONG(quality, 80);
	}
	if (!interlace_param) {
		interlace = 1;
	} else {
		interlace = zephir_get_boolval(interlace_param);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被保存的图像资源", "winer/Image/Driver/Imagick.zep", 63);
		return;
	}
	if (Z_TYPE_P(type) == IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(type);
		zephir_array_fetch_string(&type, _1, SL("type"), PH_NOISY, "winer/Image/Driver/Imagick.zep", 67 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_2);
		zephir_fast_strtolower(_2, type);
		ZEPHIR_CPY_WRT(type, _2);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "setimageformat", NULL, type);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "jpeg", 0);
	_4 = ZEPHIR_IS_EQUAL(&_3, type);
	if (!(_4)) {
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "jpg", 0);
		_4 = ZEPHIR_IS_EQUAL(&_5, type);
	}
	if (_4) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_LONG(_2, 1);
		ZEPHIR_CALL_METHOD(NULL, _1, "setimageinterlacescheme", NULL, _2);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "setimagecompressionquality", NULL, quality);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _6, "stripimage", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "dirname", &_8, imgname);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_9, "realpath", &_10, _7);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	zephir_basename(_2, imgname TSRMLS_CC);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_VSV(_11, _9, "/", _2);
	ZEPHIR_CPY_WRT(imgname, _11);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "gif", 0);
	if (ZEPHIR_IS_EQUAL(&_12, type)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_14);
		ZVAL_BOOL(_14, 1);
		ZEPHIR_CALL_METHOD(NULL, _13, "writeimages", NULL, imgname, _14);
		zephir_check_call_status();
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "writeimage", NULL, imgname);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回图像宽度
 * @return integer 图像宽度
 */
PHP_METHOD(Winer_Image_Driver_Imagick, width) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Imagick.zep", 95);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 97 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * 返回图像高度
 * @return integer 图像高度
 */
PHP_METHOD(Winer_Image_Driver_Imagick, height) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Imagick.zep", 106);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 108 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * 返回图像类型
 * @return string 图像类型
 */
PHP_METHOD(Winer_Image_Driver_Imagick, type) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Imagick.zep", 117);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("type"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 119 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * 返回图像MIME类型
 * @return string 图像MIME类型
 */
PHP_METHOD(Winer_Image_Driver_Imagick, mime) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Imagick.zep", 128);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("mime"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 130 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * 返回图像尺寸数组 0 - 图像宽度，1 - 图像高度
 * @return array 图像尺寸
 */
PHP_METHOD(Winer_Image_Driver_Imagick, size) {

	zval *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Imagick.zep", 139);
		return;
	}
	array_init_size(return_value, 3);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, _1, SL("width"), PH_NOISY, "winer/Image/Driver/Imagick.zep", 141 TSRMLS_CC);
	zephir_array_fast_append(return_value, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(_2);
	zephir_array_fetch_string(&_2, _3, SL("height"), PH_NOISY, "winer/Image/Driver/Imagick.zep", 141 TSRMLS_CC);
	zephir_array_fast_append(return_value, _2);
	RETURN_MM();

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
PHP_METHOD(Winer_Image_Driver_Imagick, crop) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *w, *h, *x = NULL, *y = NULL, *width = NULL, *height = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 4, &w, &h, &x, &y, &width, &height);

	if (!x) {
		ZEPHIR_INIT_VAR(x);
		ZVAL_LONG(x, 0);
	}
	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}
	if (!width) {
		ZEPHIR_CPY_WRT(width, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(width);
	}
	if (!height) {
		ZEPHIR_CPY_WRT(height, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(height);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被裁剪的图像资源", "winer/Image/Driver/Imagick.zep", 155);
		return;
	}
	if (ZEPHIR_IS_EMPTY(width)) {
		ZEPHIR_CPY_WRT(width, w);
	}
	if (ZEPHIR_IS_EMPTY(height)) {
		ZEPHIR_CPY_WRT(height, h);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_crop", &_1, w, h, x, y, width, height);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/* 裁剪图片，内部调用 */
PHP_METHOD(Winer_Image_Driver_Imagick, _crop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _1, _2, _4, _8;
	zval *w, *h, *x, *y, *width, *height, *img = NULL, *_0, *info = NULL, *_3, *_5, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &w, &h, &x, &y, &width, &height, &img);

	if (!img) {
		ZEPHIR_CPY_WRT(img, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(img);
	}


	if (Z_TYPE_P(img) == IS_NULL) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(img, _0);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(info, _0);
	_1 = !ZEPHIR_IS_LONG(x, 0);
	if (!(_1)) {
		_1 = !ZEPHIR_IS_LONG(y, 0);
	}
	_2 = _1;
	if (!(_2)) {
		zephir_array_fetch_string(&_3, info, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 176 TSRMLS_CC);
		_2 = !ZEPHIR_IS_EQUAL(w, _3);
	}
	_4 = _2;
	if (!(_4)) {
		zephir_array_fetch_string(&_5, info, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 176 TSRMLS_CC);
		_4 = !ZEPHIR_IS_EQUAL(h, _5);
	}
	if (_4) {
		ZEPHIR_CALL_METHOD(NULL, img, "cropimage", NULL, w, h, x, y);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZVAL_LONG(_6, 0);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_CALL_METHOD(NULL, img, "setimagepage", NULL, w, h, _6, _7);
		zephir_check_call_status();
	}
	_8 = !ZEPHIR_IS_EQUAL(w, width);
	if (!(_8)) {
		_8 = !ZEPHIR_IS_EQUAL(h, height);
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(NULL, img, "sampleimage", NULL, width, height);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "width", 1);
	zephir_update_property_array(this_ptr, SL("info"), _6, w TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_STRING(_7, "height", 1);
	zephir_update_property_array(this_ptr, SL("info"), _7, h TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 生成缩略图
 * @param  integer width  缩略图最大宽度
 * @param  integer height 缩略图最大高度
 * @param  integer type   缩略图裁剪类型
 */
PHP_METHOD(Winer_Image_Driver_Imagick, thumb) {

	zephir_fcall_cache_entry *_20 = NULL, *_22 = NULL, *_23 = NULL;
	double posx, posy;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_19 = NULL;
	zend_bool _3;
	zval *width = NULL, *height = NULL, *type = NULL, *_0, *w = NULL, *h = NULL, *y = NULL, *x = NULL, *_1, *_2, *scale = NULL, *_4 = NULL, *_5 = NULL, *_8, *_9, *_10 = NULL, *_11, *_12 = NULL, *neww, *newh, _13 = zval_used_for_init, *newimg, *_14 = NULL, *_15, *imgs = NULL, *img = NULL, *image = NULL, *_16, *_17, *_18 = NULL, *_21 = NULL, *_24, *_25 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &width, &height, &type);

	ZEPHIR_SEPARATE_PARAM(width);
	ZEPHIR_SEPARATE_PARAM(height);
	if (!type) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_LONG(type, 1);
	}
	ZEPHIR_INIT_VAR(y);
	ZVAL_LONG(y, 0);
	ZEPHIR_INIT_VAR(x);
	ZVAL_LONG(x, 0);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被缩略的图像资源", "winer/Image/Driver/Imagick.zep", 199);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(w);
	zephir_array_fetch_string(&w, _1, SL("width"), PH_NOISY, "winer/Image/Driver/Imagick.zep", 207 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(h);
	zephir_array_fetch_string(&h, _2, SL("height"), PH_NOISY, "winer/Image/Driver/Imagick.zep", 208 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(type, 1)) {
			_3 = ZEPHIR_LT(w, width);
			if (_3) {
				_3 = ZEPHIR_LT(h, height);
			}
			if (_3) {
				RETURN_MM_NULL();
			}
			ZEPHIR_INIT_VAR(_4);
			div_function(_4, width, w TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5);
			div_function(_5, height, h TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&scale, "min", &_6, _4, _5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(width);
			mul_function(width, w, scale TSRMLS_CC);
			ZEPHIR_INIT_NVAR(height);
			mul_function(height, h, scale TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 3)) {
			ZEPHIR_INIT_LNVAR(_4);
			div_function(_4, width, w TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_5);
			div_function(_5, height, h TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&scale, "max", &_7, _4, _5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(w);
			div_function(w, width, scale TSRMLS_CC);
			ZEPHIR_INIT_NVAR(h);
			div_function(h, height, scale TSRMLS_CC);
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_9, _8, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 236 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_10);
			sub_function(_10, _9, w TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			ZVAL_DOUBLE(x, zephir_safe_div_zval_long(_10, 2 TSRMLS_CC));
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_9, _11, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 237 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_12);
			sub_function(_12, _9, h TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_DOUBLE(y, zephir_safe_div_zval_long(_12, 2 TSRMLS_CC));
			break;
		}
		if (ZEPHIR_IS_LONG(type, 4)) {
			ZEPHIR_INIT_LNVAR(_4);
			div_function(_4, width, w TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_5);
			div_function(_5, height, h TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&scale, "max", &_7, _4, _5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(w);
			div_function(w, width, scale TSRMLS_CC);
			ZEPHIR_INIT_NVAR(h);
			div_function(h, height, scale TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 5)) {
			ZEPHIR_INIT_LNVAR(_4);
			div_function(_4, width, w TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_5);
			div_function(_5, height, h TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&scale, "max", &_7, _4, _5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(w);
			div_function(w, width, scale TSRMLS_CC);
			ZEPHIR_INIT_NVAR(h);
			div_function(h, height, scale TSRMLS_CC);
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_9, _8, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 258 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			sub_function(x, _9, w TSRMLS_CC);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_9, _11, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 259 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			sub_function(y, _9, h TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 2)) {
			_3 = ZEPHIR_LT(w, width);
			if (_3) {
				_3 = ZEPHIR_LT(h, height);
			}
			if (_3) {
				ZEPHIR_INIT_NVAR(scale);
				ZVAL_LONG(scale, 1);
			} else {
				ZEPHIR_INIT_LNVAR(_4);
				div_function(_4, width, w TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_5);
				div_function(_5, height, h TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&scale, "min", &_6, _4, _5);
				zephir_check_call_status();
			}
			ZEPHIR_INIT_VAR(neww);
			mul_function(neww, w, scale TSRMLS_CC);
			ZEPHIR_INIT_VAR(newh);
			mul_function(newh, h, scale TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_13);
			mul_function(&_13, w, scale TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			sub_function(_10, width, &_13 TSRMLS_CC);
			posx = zephir_safe_div_zval_long(_10, 2 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_13);
			mul_function(&_13, h, scale TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_12);
			sub_function(_12, height, &_13 TSRMLS_CC);
			posy = zephir_safe_div_zval_long(_12, 2 TSRMLS_CC);
			ZEPHIR_INIT_VAR(newimg);
			object_init_ex(newimg, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, newimg, "__construct", NULL);
			zephir_check_call_status();
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_9, _8, SL("type"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 283 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_14);
			ZVAL_STRING(_14, "white", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, newimg, "newimage", NULL, width, height, _14, _9);
			zephir_check_temp_parameter(_14);
			zephir_check_call_status();
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_15, _11, SL("type"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 285 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_13);
			ZVAL_STRING(&_13, "gif", 0);
			if (ZEPHIR_IS_EQUAL(&_13, _15)) {
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(&imgs, _16, "coalesceimages", NULL);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(img);
				object_init_ex(img, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
				ZEPHIR_CALL_METHOD(NULL, img, "__construct", NULL);
				zephir_check_call_status();
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(NULL, _17, "destroy", NULL);
				zephir_check_call_status();
				do {
					ZEPHIR_INIT_NVAR(_14);
					ZVAL_DOUBLE(_14, posx);
					ZEPHIR_INIT_NVAR(_18);
					ZVAL_DOUBLE(_18, posy);
					ZEPHIR_CALL_METHOD(&image, this_ptr, "inside_fill", &_19, newimg, _14, _18, neww, newh, imgs);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, img, "addimage", &_20, image);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_21, imgs, "getimagedelay", NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, img, "setimagedelay", &_22, _21);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(_14);
					ZVAL_LONG(_14, 0);
					ZEPHIR_INIT_NVAR(_18);
					ZVAL_LONG(_18, 0);
					ZEPHIR_CALL_METHOD(NULL, img, "setimagepage", &_23, width, height, _14, _18);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, image, "destroy", NULL);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_21, imgs, "nextimage", NULL);
					zephir_check_call_status();
				} while (zephir_is_true(_21));
				_24 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(NULL, _24, "destroy", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25, img, "deconstructimages", NULL);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("img"), _25 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, imgs, "destroy", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, img, "destroy", NULL);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(_14);
				ZVAL_DOUBLE(_14, posx);
				ZEPHIR_INIT_NVAR(_18);
				ZVAL_DOUBLE(_18, posy);
				ZEPHIR_CALL_METHOD(&img, this_ptr, "inside_fill", &_19, newimg, _14, _18, neww, newh);
				zephir_check_call_status();
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(NULL, _16, "destroy", NULL);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("img"), img TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(_14);
			ZVAL_STRING(_14, "width", 1);
			zephir_update_property_array(this_ptr, SL("info"), _14, width TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_18);
			ZVAL_STRING(_18, "height", 1);
			zephir_update_property_array(this_ptr, SL("info"), _18, height TSRMLS_CC);
			RETURN_MM_NULL();
		}
		if (ZEPHIR_IS_LONG(type, 6)) {
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不支持的缩略图裁剪类型", "winer/Image/Driver/Imagick.zep", 326);
		return;
	} while(0);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "crop", NULL, w, h, x, y, width, height);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/* 填充指定图像，内部使用 */
PHP_METHOD(Winer_Image_Driver_Imagick, inside_fill) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *newimg, *posx, *posy, *neww, *newh, *img = NULL, *_0, *draw, *image, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 1, &newimg, &posx, &posy, &neww, &newh, &img);

	if (!img) {
		ZEPHIR_CPY_WRT(img, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(img);
	}


	if (Z_TYPE_P(img) == IS_NULL) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(img, _0);
	}
	ZEPHIR_INIT_VAR(draw);
	object_init_ex(draw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, draw, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, img, "getimagecompose", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, draw, "composite", NULL, _1, posx, posy, neww, newh, img);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(image);
	if (zephir_clone(image, newimg TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, image, "drawimage", NULL, draw);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, draw, "destroy", NULL);
	zephir_check_call_status();
	RETURN_CCTOR(image);

}

/**
 * 添加水印
 * @param  string  source 水印图片路径
 * @param  integer locate 水印位置
 * @param  integer alpha  水印透明度
 */
PHP_METHOD(Winer_Image_Driver_Imagick, water) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zval *source, *locate = NULL, *alpha = NULL, *_0, *_1 = NULL, *water, *info, *_3 = NULL, *_5 = NULL, *x = NULL, *y = NULL, *_6, *_7, *_8, *_9, *_10 = NULL, *_11, *draw, *_12, _13, *img = NULL, *_14, *_15 = NULL, *_16 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &source, &locate, &alpha);

	if (!locate) {
		ZEPHIR_INIT_VAR(locate);
		ZVAL_LONG(locate, 9);
	}
	if (!alpha) {
		ZEPHIR_INIT_VAR(alpha);
		ZVAL_LONG(alpha, 80);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被添加水印的图像资源", "winer/Image/Driver/Imagick.zep", 358);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, source);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "水印图像不存在", "winer/Image/Driver/Imagick.zep", 361);
		return;
	}
	ZEPHIR_INIT_VAR(water);
	object_init_ex(water, zephir_get_internal_ce(SS("imagick") TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_3, "realpath", &_4, source);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, water, "__construct", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(info);
	array_init_size(info, 3);
	ZEPHIR_CALL_METHOD(&_5, water, "getimagewidth", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(info, _5);
	ZEPHIR_CALL_METHOD(&_5, water, "getimageheight", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(info, _5);
	do {
		if (ZEPHIR_IS_LONG(locate, 9)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _6, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 376 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 376 TSRMLS_CC);
			ZEPHIR_INIT_VAR(x);
			sub_function(x, _7, _8 TSRMLS_CC);
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _9, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 377 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 377 TSRMLS_CC);
			ZEPHIR_INIT_VAR(y);
			sub_function(y, _7, _8 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 7)) {
			ZEPHIR_INIT_NVAR(x);
			ZVAL_LONG(x, 0);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _6, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 383 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 383 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			sub_function(y, _7, _8 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 1)) {
			ZEPHIR_INIT_NVAR(x);
			ZVAL_LONG(x, 0);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_LONG(y, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 3)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _6, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 394 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 394 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			sub_function(x, _7, _8 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_LONG(y, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 5)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _6, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 400 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 400 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_10);
			sub_function(_10, _7, _8 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			ZVAL_DOUBLE(x, zephir_safe_div_zval_long(_10, 2 TSRMLS_CC));
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _9, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 401 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 401 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_11);
			sub_function(_11, _7, _8 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_DOUBLE(y, zephir_safe_div_zval_long(_11, 2 TSRMLS_CC));
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 8)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _6, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 406 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 406 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			sub_function(_10, _7, _8 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			ZVAL_DOUBLE(x, zephir_safe_div_zval_long(_10, 2 TSRMLS_CC));
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _9, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 407 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 407 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			sub_function(y, _7, _8 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 6)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _6, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 412 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 412 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			sub_function(x, _7, _8 TSRMLS_CC);
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _9, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 413 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 413 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			sub_function(_10, _7, _8 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_DOUBLE(y, zephir_safe_div_zval_long(_10, 2 TSRMLS_CC));
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 2)) {
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _6, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 418 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 418 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			sub_function(_10, _7, _8 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			ZVAL_DOUBLE(x, zephir_safe_div_zval_long(_10, 2 TSRMLS_CC));
			ZEPHIR_INIT_NVAR(y);
			ZVAL_LONG(y, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 4)) {
			ZEPHIR_INIT_NVAR(x);
			ZVAL_LONG(x, 0);
			_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_7, _6, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 425 TSRMLS_CC);
			zephir_array_fetch_long(&_8, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 425 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			sub_function(_10, _7, _8 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_DOUBLE(y, zephir_safe_div_zval_long(_10, 2 TSRMLS_CC));
			break;
		}
		if (Z_TYPE_P(locate) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(x);
			zephir_array_fetch_long(&x, locate, 0, PH_NOISY, "winer/Image/Driver/Imagick.zep", 431 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(y);
			zephir_array_fetch_long(&y, locate, 1, PH_NOISY, "winer/Image/Driver/Imagick.zep", 432 TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不支持的水印位置类型", "winer/Image/Driver/Imagick.zep", 434);
			return;
		}
	} while(0);

	ZEPHIR_INIT_VAR(draw);
	object_init_ex(draw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, draw, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, water, "getimagecompose", NULL);
	zephir_check_call_status();
	zephir_array_fetch_long(&_7, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 441 TSRMLS_CC);
	zephir_array_fetch_long(&_8, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 441 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, draw, "composite", NULL, _5, x, y, _7, _8, water);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_12, _6, SL("type"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 443 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "gif", 0);
	if (ZEPHIR_IS_EQUAL(&_13, _12)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&img, _9, "coalesceimages", NULL);
		zephir_check_call_status();
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _14, "destroy", NULL);
		zephir_check_call_status();
		do {
			ZEPHIR_CALL_METHOD(NULL, img, "drawimage", NULL, draw);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15, img, "nextimage", NULL);
			zephir_check_call_status();
		} while (zephir_is_true(_15));
		ZEPHIR_CALL_METHOD(&_16, img, "deconstructimages", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("img"), _16 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, img, "destroy", NULL);
		zephir_check_call_status();
	} else {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _6, "drawimage", NULL, draw);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, water, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Winer_Image_Driver_Imagick, text) {

	HashTable *_10;
	HashPosition _9;
	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS, _28;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL, *_14 = NULL, *_17 = NULL, *_19 = NULL, *_22 = NULL;
	zval *text, *font, *size, *color = NULL, *locate = NULL, *offset = NULL, *angle = NULL, *_0, *_1 = NULL, *value = NULL, *alp = NULL, *col, _4, *_5, _6 = zval_used_for_init, *_7 = NULL, **_11, _12 = zval_used_for_init, _13 = zval_used_for_init, *_15 = NULL, *_16 = NULL, *draw, *_18 = NULL, *metrics = NULL, *_20, *x, *y = NULL, *w, *h, *_21, *_23, *_24, *_25, *_26 = NULL, *_27 = NULL, *posx, *posy, *ox = NULL, *oy = NULL, *img = NULL, *_29;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 4, &text, &font, &size, &color, &locate, &offset, &angle);

	if (!color) {
		ZEPHIR_INIT_VAR(color);
		ZVAL_STRING(color, "#00000000", 1);
	} else {
		ZEPHIR_SEPARATE_PARAM(color);
	}
	if (!locate) {
		ZEPHIR_INIT_VAR(locate);
		ZVAL_LONG(locate, 9);
	}
	if (!offset) {
		ZEPHIR_INIT_VAR(offset);
		ZVAL_LONG(offset, 0);
	} else {
		ZEPHIR_SEPARATE_PARAM(offset);
	}
	if (!angle) {
		ZEPHIR_INIT_VAR(angle);
		ZVAL_LONG(angle, 0);
	}
	ZEPHIR_INIT_VAR(x);
	ZVAL_DOUBLE(x, 0.0);
	ZEPHIR_INIT_VAR(y);
	ZVAL_DOUBLE(y, 0.0);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被写入文字的图像资源", "winer/Image/Driver/Imagick.zep", 480);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, font);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不存在的字体文件：{font}", "winer/Image/Driver/Imagick.zep", 483);
		return;
	}
	_3 = !(Z_TYPE_P(color) == IS_STRING);
	if (!(_3)) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "#", 0);
		ZEPHIR_INIT_VAR(_5);
		zephir_fast_strpos(_5, color, &_4, 0 );
		_3 = !ZEPHIR_IS_LONG_IDENTICAL(_5, 0);
	}
	if (Z_TYPE_P(color) == IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_STRING(&_6, "dechex", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "array_map", &_8, &_6, color);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(color, _7);
		zephir_is_iterable(color, &_10, &_9, 0, 0, "winer/Image/Driver/Imagick.zep", 496);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HVALUE(value, _11);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_LONG(&_6, 2);
			ZEPHIR_SINIT_NVAR(_12);
			ZVAL_LONG(&_12, 0);
			ZEPHIR_SINIT_NVAR(_13);
			ZVAL_LONG(&_13, 0);
			ZEPHIR_CALL_FUNCTION(&_7, "str_pad", &_14, value, &_6, &_12, &_13);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _7);
		}
		ZEPHIR_INIT_VAR(_15);
		zephir_fast_join_str(_15, SL(""), color TSRMLS_CC);
		ZEPHIR_INIT_VAR(_16);
		ZEPHIR_CONCAT_SV(_16, "#", _15);
		ZEPHIR_CPY_WRT(color, _16);
	} else if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "错误的颜色值", "winer/Image/Driver/Imagick.zep", 498);
		return;
	}
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_NVAR(_12);
	ZVAL_LONG(&_12, 7);
	ZEPHIR_INIT_VAR(col);
	zephir_substr(col, color, 0 , 7 , 0);
	if (zephir_fast_strlen_ev(color) == 9) {
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_LONG(&_13, -2);
		ZEPHIR_INIT_VAR(alp);
		zephir_substr(alp, color, -2 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else {
		ZEPHIR_INIT_NVAR(alp);
		ZVAL_LONG(alp, 0);
	}
	ZEPHIR_INIT_VAR(draw);
	object_init_ex(draw, zephir_get_internal_ce(SS("imagickdraw") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, draw, "__construct", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "realpath", &_17, font);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, draw, "setfont", NULL, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, draw, "setfontsize", NULL, size);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, draw, "setfillcolor", NULL, col);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_18, "hexdec", &_19, alp);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_DOUBLE(_15, ((double) 1 - zephir_safe_div_zval_long(_18, 127 TSRMLS_CC)));
	ZEPHIR_CALL_METHOD(NULL, draw, "setfillalpha", NULL, _15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_BOOL(_15, 1);
	ZEPHIR_CALL_METHOD(NULL, draw, "settextantialias", NULL, _15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_BOOL(_15, 1);
	ZEPHIR_CALL_METHOD(NULL, draw, "setstrokeantialias", NULL, _15);
	zephir_check_call_status();
	_20 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&metrics, _20, "queryfontmetrics", NULL, draw, text);
	zephir_check_call_status();
	zephir_array_fetch_string(&_21, metrics, SL("ascender"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 522 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&y, "floatval", &_22, _21);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(w);
	zephir_array_fetch_string(&w, metrics, SL("textWidth"), PH_NOISY, "winer/Image/Driver/Imagick.zep", 523 TSRMLS_CC);
	ZEPHIR_OBS_VAR(h);
	zephir_array_fetch_string(&h, metrics, SL("textHeight"), PH_NOISY, "winer/Image/Driver/Imagick.zep", 524 TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(locate, 9)) {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _23, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 530 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16);
			sub_function(_16, _24, w TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(x, _16);
			_25 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _25, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 531 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_26);
			sub_function(_26, _24, h TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(y, _26);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 7)) {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _23, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 536 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16);
			sub_function(_16, _24, h TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(y, _16);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 1)) {
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 3)) {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _23, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 546 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16);
			sub_function(_16, _24, w TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(x, _16);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 5)) {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _23, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 551 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16);
			sub_function(_16, _24, w TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(_16, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_7, "floatval", &_22, &_6);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(x, _7);
			_25 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _25, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 552 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_26);
			sub_function(_26, _24, h TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(_26, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_27, "floatval", &_22, &_6);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(y, _27);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 8)) {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _23, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 557 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16);
			sub_function(_16, _24, w TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(_16, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_7, "floatval", &_22, &_6);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(x, _7);
			_25 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _25, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 558 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_26);
			sub_function(_26, _24, h TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(y, _26);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 6)) {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _23, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 563 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16);
			sub_function(_16, _24, w TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(x, _16);
			_25 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _25, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 564 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_26);
			sub_function(_26, _24, h TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(_26, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_7, "floatval", &_22, &_6);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(y, _7);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 2)) {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _23, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 569 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16);
			sub_function(_16, _24, w TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(_16, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_7, "floatval", &_22, &_6);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(x, _7);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 4)) {
			_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_24, _23, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 574 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_16);
			sub_function(_16, _24, h TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_DOUBLE(&_6, zephir_safe_div_zval_long(_16, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_7, "floatval", &_22, &_6);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(y, _7);
			break;
		}
		if (Z_TYPE_P(locate) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(posx);
			zephir_array_fetch_long(&posx, locate, 0, PH_NOISY, "winer/Image/Driver/Imagick.zep", 582 TSRMLS_CC);
			ZEPHIR_OBS_VAR(posy);
			zephir_array_fetch_long(&posy, locate, 1, PH_NOISY, "winer/Image/Driver/Imagick.zep", 583 TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(x, posx);
			ZEPHIR_ADD_ASSIGN(y, posy);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不支持的文字位置类型", "winer/Image/Driver/Imagick.zep", 587);
			return;
		}
	} while(0);

	if (Z_TYPE_P(offset) == IS_ARRAY) {
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_STRING(&_6, "intval", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "array_map", &_8, &_6, offset);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(offset, _7);
		ZEPHIR_OBS_VAR(ox);
		zephir_array_fetch_long(&ox, locate, 0, PH_NOISY, "winer/Image/Driver/Imagick.zep", 596 TSRMLS_CC);
		ZEPHIR_OBS_VAR(oy);
		zephir_array_fetch_long(&oy, locate, 1, PH_NOISY, "winer/Image/Driver/Imagick.zep", 597 TSRMLS_CC);
	} else {
		_28 = zephir_get_intval(offset);
		ZEPHIR_INIT_NVAR(offset);
		ZVAL_LONG(offset, _28);
		ZEPHIR_CPY_WRT(ox, offset);
		ZEPHIR_CPY_WRT(oy, offset);
	}
	_23 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_24, _23, SL("type"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Imagick.zep", 605 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "gif", 0);
	if (ZEPHIR_IS_EQUAL(&_6, _24)) {
		_25 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&img, _25, "coalesceimages", NULL);
		zephir_check_call_status();
		_29 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _29, "destroy", NULL);
		zephir_check_call_status();
		do {
			ZEPHIR_INIT_LNVAR(_16);
			zephir_add_function_ex(_16, x, ox TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_26);
			zephir_add_function_ex(_26, y, oy TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, img, "annotateimage", NULL, draw, _16, _26, angle, text);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7, img, "nextimage", NULL);
			zephir_check_call_status();
		} while (zephir_is_true(_7));
		ZEPHIR_CALL_METHOD(&_27, img, "deconstructimages", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("img"), _27 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, img, "destroy", NULL);
		zephir_check_call_status();
	} else {
		_23 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_16);
		zephir_add_function_ex(_16, x, ox TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_26);
		zephir_add_function_ex(_26, y, oy TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _23, "annotateimage", NULL, draw, _16, _26, angle, text);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, draw, "destroy", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 析构方法，用于销毁图像资源
 */
PHP_METHOD(Winer_Image_Driver_Imagick, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0) == 0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1, "destroy", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

