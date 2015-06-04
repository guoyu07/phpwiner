
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Winer_Image_Driver_Gd) {

	ZEPHIR_REGISTER_CLASS(Winer\\Image\\Driver, Gd, winer, image_driver_gd, winer_image_driver_gd_method_entry, 0);

	/**
	 * 图像资源对象
	 * @var resource
	 */
	zend_declare_property_null(winer_image_driver_gd_ce, SL("img"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 图像信息，包括width,height,type,mime,size
	 * @var array
	 */
	zend_declare_property_null(winer_image_driver_gd_ce, SL("info"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造方法，可用于打开一张图像
 * @param string imgname 图像路径
 */
PHP_METHOD(Winer_Image_Driver_Gd, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *imgname_param = NULL;
	zval *imgname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &imgname_param);

	if (!imgname_param) {
		ZEPHIR_INIT_VAR(imgname);
		ZVAL_EMPTY_STRING(imgname);
	} else {
		zephir_get_strval(imgname, imgname_param);
	}


	if (zephir_fast_strlen_ev(imgname) > 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "open", NULL, imgname);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 打开一张图像
 * @param  string imgname 图像路径
 */
PHP_METHOD(Winer_Image_Driver_Gd, open) {

	zval *_7;
	zend_bool _3, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_11 = NULL;
	zval *imgname, *_0 = NULL, *info = NULL, *_4, *_6, *_8 = NULL, *_9, *_10 = NULL, *_12, *fun, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &imgname);



	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, imgname);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不存在的图像文件", "winer/Image/Driver/Gd.zep", 36);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&info, "getimagesize", &_2, imgname);
	zephir_check_call_status();
	_3 = ZEPHIR_IS_FALSE_IDENTICAL(info);
	if (!(_3)) {
		zephir_array_fetch_long(&_4, info, 2, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 44 TSRMLS_CC);
		_5 = ZEPHIR_IS_LONG_IDENTICAL(_4, 1);
		if (_5) {
			ZEPHIR_OBS_VAR(_6);
			zephir_array_fetch_string(&_6, info, SL("bits"), PH_NOISY, "winer/Image/Driver/Gd.zep", 44 TSRMLS_CC);
			_5 = ZEPHIR_IS_EMPTY(_6);
		}
		_3 = _5;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "非法图像文件", "winer/Image/Driver/Gd.zep", 45);
		return;
	}
	ZEPHIR_INIT_VAR(_7);
	array_init_size(_7, 6);
	ZEPHIR_OBS_VAR(_8);
	zephir_array_fetch_long(&_8, info, 0, PH_NOISY, "winer/Image/Driver/Gd.zep", 50 TSRMLS_CC);
	zephir_array_update_string(&_7, SL("width"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_8);
	zephir_array_fetch_long(&_8, info, 1, PH_NOISY, "winer/Image/Driver/Gd.zep", 51 TSRMLS_CC);
	zephir_array_update_string(&_7, SL("height"), &_8, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_long(&_9, info, 2, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 52 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_10, "image_type_to_extension", &_11, _9, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	zephir_array_update_string(&_7, SL("type"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_8);
	zephir_array_fetch_string(&_8, info, SL("mime"), PH_NOISY, "winer/Image/Driver/Gd.zep", 54 TSRMLS_CC);
	zephir_array_update_string(&_7, SL("mime"), &_8, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("info"), _7 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(_8);
	zephir_read_property_this(&_8, this_ptr, SL("img"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_8))) {
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _12);
		zephir_check_call_status();
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_13, _12, SL("type"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 63 TSRMLS_CC);
	ZEPHIR_INIT_VAR(fun);
	ZEPHIR_CONCAT_SV(fun, "imagecreatefrom", _13);
	ZEPHIR_CALL_ZVAL_FUNCTION(&_10, fun, NULL, imgname);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("img"), _10 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 保存图像
 * @param  string  imgname   图像保存名称
 * @param  string  type      图像类型
 * @param  integer quality   图像质量     
 * @param  boolean interlace 是否对JPEG类型图像设置隔行扫描
 */
PHP_METHOD(Winer_Image_Driver_Gd, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool interlace, _4;
	zval *imgname_param = NULL, *type = NULL, *quality = NULL, *interlace_param = NULL, *_0, *_1, *_2, _3, _5, *_6, *fun;
	zval *imgname = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &imgname_param, &type, &quality, &interlace_param);

	zephir_get_strval(imgname, imgname_param);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被保存的图像资源", "winer/Image/Driver/Gd.zep", 76);
		return;
	}
	if (Z_TYPE_P(type) == IS_NULL) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(type);
		zephir_array_fetch_string(&type, _1, SL("type"), PH_NOISY, "winer/Image/Driver/Gd.zep", 81 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_2);
		zephir_fast_strtolower(_2, type);
		ZEPHIR_CPY_WRT(type, _2);
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
		ZEPHIR_CALL_FUNCTION(NULL, "imageinterlace", NULL, _1, (interlace ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
		zephir_check_call_status();
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagejpeg", NULL, _6, imgname, quality);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(fun);
		ZEPHIR_CONCAT_SV(fun, "image", type);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_ZVAL_FUNCTION(NULL, fun, NULL, _1, imgname);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回图像宽度
 * @return integer 图像宽度
 */
PHP_METHOD(Winer_Image_Driver_Gd, width) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Gd.zep", 103);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 105 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * 返回图像高度
 * @return integer 图像高度
 */
PHP_METHOD(Winer_Image_Driver_Gd, height) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Gd.zep", 114);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 116 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * 返回图像类型
 * @return string 图像类型
 */
PHP_METHOD(Winer_Image_Driver_Gd, type) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Gd.zep", 125);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("type"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 127 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * 返回图像MIME类型
 * @return string 图像MIME类型
 */
PHP_METHOD(Winer_Image_Driver_Gd, mime) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Gd.zep", 136);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("mime"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 138 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * 返回图像尺寸数组 0 - 图像宽度，1 - 图像高度
 * @return array 图像尺寸
 */
PHP_METHOD(Winer_Image_Driver_Gd, size) {

	zval *_0, *_1, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有指定图像资源", "winer/Image/Driver/Gd.zep", 147);
		return;
	}
	array_init_size(return_value, 3);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, _1, SL("width"), PH_NOISY, "winer/Image/Driver/Gd.zep", 149 TSRMLS_CC);
	zephir_array_fast_append(return_value, _2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(_2);
	zephir_array_fetch_string(&_2, _3, SL("height"), PH_NOISY, "winer/Image/Driver/Gd.zep", 149 TSRMLS_CC);
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
PHP_METHOD(Winer_Image_Driver_Gd, crop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL;
	zval *w, *h, *x = NULL, *y = NULL, *width = NULL, *height = NULL, *_0, *img = NULL, *color = NULL, _2 = zval_used_for_init, _3 = zval_used_for_init, _4 = zval_used_for_init, *_7, *_9, *_11, *_12;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被裁剪的图像资源", "winer/Image/Driver/Gd.zep", 163);
		return;
	}
	if (ZEPHIR_IS_EMPTY(width)) {
		ZEPHIR_CPY_WRT(width, w);
	}
	if (ZEPHIR_IS_EMPTY(height)) {
		ZEPHIR_CPY_WRT(height, h);
	}
	do {
		ZEPHIR_CALL_FUNCTION(&img, "imagecreatetruecolor", &_1, width, height);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 255);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 255);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 255);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_5, img, &_2, &_3, &_4);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 0);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefill", &_6, img, &_2, &_3, color);
		zephir_check_call_status();
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 0);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", &_8, img, _7, &_2, &_3, x, y, width, height, w, h);
		zephir_check_call_status();
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_10, _9);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("img"), img TSRMLS_CC);
	} while (0);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "width", 1);
	zephir_update_property_array(this_ptr, SL("info"), _11, width TSRMLS_CC);
	ZEPHIR_INIT_VAR(_12);
	ZVAL_STRING(_12, "height", 1);
	zephir_update_property_array(this_ptr, SL("info"), _12, height TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 生成缩略图
 * @param  integer width  缩略图最大宽度
 * @param  integer height 缩略图最大高度
 * @param  integer type   缩略图裁剪类型
 */
PHP_METHOD(Winer_Image_Driver_Gd, thumb) {

	zephir_fcall_cache_entry *_14 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL;
	double posx, posy;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zend_bool _3;
	int type, ZEPHIR_LAST_CALL_STATUS;
	zval *width = NULL, *height = NULL, *type_param = NULL, *_0, *w = NULL, *h = NULL, *x = NULL, *y = NULL, *_1, *_2, *scale = NULL, *_4 = NULL, *_5 = NULL, *_8, *_9, *_10 = NULL, *_11, *_12 = NULL, *neww, *newh, _13 = zval_used_for_init, *img = NULL, *color = NULL, _15 = zval_used_for_init, _16 = zval_used_for_init, *_21, *_22;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &width, &height, &type_param);

	ZEPHIR_SEPARATE_PARAM(width);
	ZEPHIR_SEPARATE_PARAM(height);
	if (!type_param) {
		type = 1;
	} else {
		type = zephir_get_intval(type_param);
	}
	ZEPHIR_INIT_VAR(x);
	ZVAL_LONG(x, 0);
	ZEPHIR_INIT_VAR(y);
	ZVAL_LONG(y, 0);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被缩略的图像资源", "winer/Image/Driver/Gd.zep", 201);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(w);
	zephir_array_fetch_string(&w, _1, SL("width"), PH_NOISY, "winer/Image/Driver/Gd.zep", 209 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(h);
	zephir_array_fetch_string(&h, _2, SL("height"), PH_NOISY, "winer/Image/Driver/Gd.zep", 210 TSRMLS_CC);
	do {
		if (type == 1) {
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
		if (type == 3) {
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
			zephir_array_fetch_string(&_9, _8, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 236 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_10);
			sub_function(_10, _9, w TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			ZVAL_DOUBLE(x, zephir_safe_div_zval_long(_10, 2 TSRMLS_CC));
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_9, _11, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 237 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_12);
			sub_function(_12, _9, h TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_DOUBLE(y, zephir_safe_div_zval_long(_12, 2 TSRMLS_CC));
			break;
		}
		if (type == 4) {
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
		if (type == 5) {
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
			zephir_array_fetch_string(&_9, _8, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 257 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			sub_function(x, _9, w TSRMLS_CC);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_9, _11, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 258 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			sub_function(y, _9, h TSRMLS_CC);
			break;
		}
		if (type == 2) {
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
			do {
				ZEPHIR_CALL_FUNCTION(&img, "imagecreatetruecolor", &_14, width, height);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_13);
				ZVAL_LONG(&_13, 255);
				ZEPHIR_SINIT_NVAR(_15);
				ZVAL_LONG(&_15, 255);
				ZEPHIR_SINIT_NVAR(_16);
				ZVAL_LONG(&_16, 255);
				ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_17, img, &_13, &_15, &_16);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_13);
				ZVAL_LONG(&_13, 0);
				ZEPHIR_SINIT_NVAR(_15);
				ZVAL_LONG(&_15, 0);
				ZEPHIR_CALL_FUNCTION(NULL, "imagefill", &_18, img, &_13, &_15, color);
				zephir_check_call_status();
				_8 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_13);
				ZVAL_DOUBLE(&_13, posx);
				ZEPHIR_SINIT_NVAR(_15);
				ZVAL_DOUBLE(&_15, posy);
				ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", &_19, img, _8, &_13, &_15, x, y, neww, newh, w, h);
				zephir_check_call_status();
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
				ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_20, _11);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("img"), img TSRMLS_CC);
			} while (0);
			ZEPHIR_INIT_VAR(_21);
			ZVAL_STRING(_21, "width", 1);
			zephir_update_property_array(this_ptr, SL("info"), _21, width TSRMLS_CC);
			ZEPHIR_INIT_VAR(_22);
			ZVAL_STRING(_22, "height", 1);
			zephir_update_property_array(this_ptr, SL("info"), _22, height TSRMLS_CC);
			RETURN_MM_NULL();
		}
		if (type == 6) {
			ZEPHIR_INIT_NVAR(x);
			ZVAL_LONG(x, 0);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_LONG(y, 0);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不支持的缩略图裁剪类型", "winer/Image/Driver/Gd.zep", 302);
		return;
	} while(0);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "crop", NULL, w, h, x, y, width, height);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 添加水印
 * @param  string  source 水印图片路径
 * @param  integer locate 水印位置
 * @param  integer alpha  水印透明度
 */
PHP_METHOD(Winer_Image_Driver_Gd, water) {

	zephir_fcall_cache_entry *_17 = NULL, *_21 = NULL, *_22 = NULL, *_25 = NULL, *_31 = NULL, *_32 = NULL;
	zend_bool _4, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_10 = NULL;
	zval *source, *locate = NULL, *alpha = NULL, *_0, *_1 = NULL, *info = NULL, *_5, *_7, *fun, *water = NULL, *_8, *_9 = NULL, *x = NULL, *y = NULL, *_11, *_12, *_13, *_14, *_15 = NULL, *_16, *src = NULL, *color = NULL, _18 = zval_used_for_init, _19 = zval_used_for_init, _20 = zval_used_for_init, *_23, *_24, *_26, *_27, _28 = zval_used_for_init, *_29, *_30;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被添加水印的图像资源", "winer/Image/Driver/Gd.zep", 318);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, source);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "水印图像不存在", "winer/Image/Driver/Gd.zep", 321);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&info, "getimagesize", &_3, source);
	zephir_check_call_status();
	_4 = ZEPHIR_IS_FALSE_IDENTICAL(info);
	if (!(_4)) {
		zephir_array_fetch_long(&_5, info, 2, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 327 TSRMLS_CC);
		_6 = ZEPHIR_IS_LONG_IDENTICAL(_5, 1);
		if (_6) {
			ZEPHIR_OBS_VAR(_7);
			zephir_array_fetch_string(&_7, info, SL("bits"), PH_NOISY, "winer/Image/Driver/Gd.zep", 327 TSRMLS_CC);
			_6 = ZEPHIR_IS_EMPTY(_7);
		}
		_4 = _6;
	}
	if (_4) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "非法水印文件", "winer/Image/Driver/Gd.zep", 328);
		return;
	}
	zephir_array_fetch_long(&_8, info, 2, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 334 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_9, "image_type_to_extension", &_10, _8, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(fun);
	ZEPHIR_CONCAT_SV(fun, "imagecreatefrom", _9);
	ZEPHIR_CALL_ZVAL_FUNCTION(&water, fun, NULL, source);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagealphablending", NULL, water, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(locate, 9)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _11, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 346 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 346 TSRMLS_CC);
			ZEPHIR_INIT_VAR(x);
			sub_function(x, _12, _13 TSRMLS_CC);
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _14, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 347 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 347 TSRMLS_CC);
			ZEPHIR_INIT_VAR(y);
			sub_function(y, _12, _13 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 7)) {
			ZEPHIR_INIT_NVAR(x);
			ZVAL_LONG(x, 0);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _11, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 353 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 353 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			sub_function(y, _12, _13 TSRMLS_CC);
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
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _11, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 364 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 364 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			sub_function(x, _12, _13 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_LONG(y, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 5)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _11, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 370 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 370 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_15);
			sub_function(_15, _12, _13 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			ZVAL_DOUBLE(x, zephir_safe_div_zval_long(_15, 2 TSRMLS_CC));
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _14, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 371 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 371 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_16);
			sub_function(_16, _12, _13 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_DOUBLE(y, zephir_safe_div_zval_long(_16, 2 TSRMLS_CC));
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 8)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _11, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 376 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 376 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_15);
			sub_function(_15, _12, _13 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			ZVAL_DOUBLE(x, zephir_safe_div_zval_long(_15, 2 TSRMLS_CC));
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _14, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 377 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 377 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			sub_function(y, _12, _13 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 6)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _11, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 382 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 382 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			sub_function(x, _12, _13 TSRMLS_CC);
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _14, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 383 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 383 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_15);
			sub_function(_15, _12, _13 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_DOUBLE(y, zephir_safe_div_zval_long(_15, 2 TSRMLS_CC));
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 2)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _11, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 388 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 388 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_15);
			sub_function(_15, _12, _13 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(x);
			ZVAL_DOUBLE(x, zephir_safe_div_zval_long(_15, 2 TSRMLS_CC));
			ZEPHIR_INIT_NVAR(y);
			ZVAL_LONG(y, 0);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 4)) {
			ZEPHIR_INIT_NVAR(x);
			ZVAL_LONG(x, 0);
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_12, _11, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 395 TSRMLS_CC);
			zephir_array_fetch_long(&_13, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 395 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_15);
			sub_function(_15, _12, _13 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(y);
			ZVAL_DOUBLE(y, zephir_safe_div_zval_long(_15, 2 TSRMLS_CC));
			break;
		}
		if (Z_TYPE_P(locate) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(x);
			zephir_array_fetch_long(&x, locate, 0, PH_NOISY, "winer/Image/Driver/Gd.zep", 401 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(y);
			zephir_array_fetch_long(&y, locate, 1, PH_NOISY, "winer/Image/Driver/Gd.zep", 402 TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不支持的水印位置类型", "winer/Image/Driver/Gd.zep", 404);
			return;
		}
	} while(0);

	do {
		zephir_array_fetch_long(&_12, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 412 TSRMLS_CC);
		zephir_array_fetch_long(&_13, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 412 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&src, "imagecreatetruecolor", &_17, _12, _13);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 255);
		ZEPHIR_SINIT_NVAR(_19);
		ZVAL_LONG(&_19, 255);
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, 255);
		ZEPHIR_CALL_FUNCTION(&color, "imagecolorallocate", &_21, src, &_18, &_19, &_20);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_19);
		ZVAL_LONG(&_19, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "imagefill", &_22, src, &_18, &_19, color);
		zephir_check_call_status();
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		zephir_array_fetch_long(&_23, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 417 TSRMLS_CC);
		zephir_array_fetch_long(&_24, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 417 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_19);
		ZVAL_LONG(&_19, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_25, src, _11, &_18, &_19, x, y, _23, _24);
		zephir_check_call_status();
		zephir_array_fetch_long(&_26, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 418 TSRMLS_CC);
		zephir_array_fetch_long(&_27, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 418 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_19);
		ZVAL_LONG(&_19, 0);
		ZEPHIR_SINIT_NVAR(_20);
		ZVAL_LONG(&_20, 0);
		ZEPHIR_SINIT_NVAR(_28);
		ZVAL_LONG(&_28, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopy", &_25, src, water, &_18, &_19, &_20, &_28, _26, _27);
		zephir_check_call_status();
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		zephir_array_fetch_long(&_29, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 419 TSRMLS_CC);
		zephir_array_fetch_long(&_30, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 419 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_18);
		ZVAL_LONG(&_18, 0);
		ZEPHIR_SINIT_NVAR(_19);
		ZVAL_LONG(&_19, 0);
		ZEPHIR_CALL_FUNCTION(NULL, "imagecopymerge", &_31, _14, src, x, y, &_18, &_19, _29, _30, alpha);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_32, src);
		zephir_check_call_status();
	} while (0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", &_32, water);
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
PHP_METHOD(Winer_Image_Driver_Gd, text) {

	zephir_fcall_cache_entry *_46 = NULL, *_47 = NULL;
	zend_bool _35, _41;
	int ZEPHIR_LAST_CALL_STATUS, _34;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_9 = NULL, *_14 = NULL, *_23 = NULL, *_25 = NULL, *_33 = NULL, *_39 = NULL;
	zval *text, *font, *size, *color = NULL, *locate = NULL, *offset = NULL, *angle = NULL, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *info = NULL, *minx = NULL, *maxx = NULL, *miny = NULL, *maxy = NULL, *_5, *_6, *_7, *_8, *_10, *_11, *_12, *_13, *_15, *_16, *_17, *_18, *_19, *_20, *_21, *_22, *x = NULL, *y = NULL, w, h, *_24 = NULL, *_26, *_27, *_28, *_29 = NULL, _30 = zval_used_for_init, *_31 = NULL, *_32 = NULL, *posx, *posy, *ox = NULL, *oy = NULL, _36 = zval_used_for_init, *_37, _38 = zval_used_for_init, *_40, *_42, *col = NULL, *_43, *_44, *_45;

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


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "没有可以被写入文字的图像资源", "winer/Image/Driver/Gd.zep", 442);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, font);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "不存在的字体文件：", font);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "winer/Image/Driver/Gd.zep", 445 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&info, "imagettfbbox", NULL, size, angle, font, text);
	zephir_check_call_status();
	zephir_array_fetch_long(&_5, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 455 TSRMLS_CC);
	zephir_array_fetch_long(&_6, info, 2, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 455 TSRMLS_CC);
	zephir_array_fetch_long(&_7, info, 4, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 455 TSRMLS_CC);
	zephir_array_fetch_long(&_8, info, 6, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 455 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&minx, "min", &_9, _5, _6, _7, _8);
	zephir_check_call_status();
	zephir_array_fetch_long(&_10, info, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 456 TSRMLS_CC);
	zephir_array_fetch_long(&_11, info, 2, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 456 TSRMLS_CC);
	zephir_array_fetch_long(&_12, info, 4, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 456 TSRMLS_CC);
	zephir_array_fetch_long(&_13, info, 6, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 456 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&maxx, "max", &_14, _10, _11, _12, _13);
	zephir_check_call_status();
	zephir_array_fetch_long(&_15, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 457 TSRMLS_CC);
	zephir_array_fetch_long(&_16, info, 3, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 457 TSRMLS_CC);
	zephir_array_fetch_long(&_17, info, 5, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 457 TSRMLS_CC);
	zephir_array_fetch_long(&_18, info, 7, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 457 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&miny, "min", &_9, _15, _16, _17, _18);
	zephir_check_call_status();
	zephir_array_fetch_long(&_19, info, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 458 TSRMLS_CC);
	zephir_array_fetch_long(&_20, info, 3, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 458 TSRMLS_CC);
	zephir_array_fetch_long(&_21, info, 5, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 458 TSRMLS_CC);
	zephir_array_fetch_long(&_22, info, 7, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 458 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&maxy, "max", &_14, _19, _20, _21, _22);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&x, "floatval", &_23, minx);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_24, "abs", &_25, miny);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&y, "floatval", &_23, _24);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(w);
	sub_function(&w, maxx, minx TSRMLS_CC);
	ZEPHIR_SINIT_VAR(h);
	sub_function(&h, maxy, miny TSRMLS_CC);
	do {
		if (ZEPHIR_IS_LONG(locate, 9)) {
			_26 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _26, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 474 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			sub_function(_4, _27, &w TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(x, _4);
			_28 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _28, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 475 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_29);
			sub_function(_29, _27, &h TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(y, _29);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 7)) {
			_26 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _26, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 480 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			sub_function(_4, _27, &h TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(y, _4);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 1)) {
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 3)) {
			_26 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _26, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 490 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			sub_function(_4, _27, &w TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(x, _4);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 5)) {
			_26 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _26, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 495 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			sub_function(_4, _27, &w TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_30);
			ZVAL_DOUBLE(&_30, zephir_safe_div_zval_long(_4, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_31, "floatval", &_23, &_30);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(x, _31);
			_28 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _28, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 496 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_29);
			sub_function(_29, _27, &h TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_30);
			ZVAL_DOUBLE(&_30, zephir_safe_div_zval_long(_29, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_32, "floatval", &_23, &_30);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(y, _32);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 8)) {
			_26 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _26, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 501 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			sub_function(_4, _27, &w TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_30);
			ZVAL_DOUBLE(&_30, zephir_safe_div_zval_long(_4, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_31, "floatval", &_23, &_30);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(x, _31);
			_28 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _28, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 502 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_30);
			sub_function(&_30, _27, &h TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_32, "floatval", &_23, &_30);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(y, _32);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 6)) {
			_26 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _26, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 507 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			sub_function(_4, _27, &w TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(x, _4);
			_28 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _28, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 508 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_29);
			sub_function(_29, _27, &h TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_30);
			ZVAL_DOUBLE(&_30, zephir_safe_div_zval_long(_29, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_31, "floatval", &_23, &_30);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(y, _31);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 2)) {
			_26 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _26, SL("width"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 513 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			sub_function(_4, _27, &w TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_30);
			ZVAL_DOUBLE(&_30, zephir_safe_div_zval_long(_4, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_31, "floatval", &_23, &_30);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(x, _31);
			break;
		}
		if (ZEPHIR_IS_LONG(locate, 4)) {
			_26 = zephir_fetch_nproperty_this(this_ptr, SL("info"), PH_NOISY_CC);
			zephir_array_fetch_string(&_27, _26, SL("height"), PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 518 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			sub_function(_4, _27, &h TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_30);
			ZVAL_DOUBLE(&_30, zephir_safe_div_zval_long(_4, 2 TSRMLS_CC));
			ZEPHIR_CALL_FUNCTION(&_31, "floatval", &_23, &_30);
			zephir_check_call_status();
			ZEPHIR_ADD_ASSIGN(y, _31);
			break;
		}
		if (Z_TYPE_P(locate) == IS_ARRAY) {
			ZEPHIR_OBS_VAR(posx);
			zephir_array_fetch_long(&posx, locate, 0, PH_NOISY, "winer/Image/Driver/Gd.zep", 526 TSRMLS_CC);
			ZEPHIR_OBS_VAR(posy);
			zephir_array_fetch_long(&posy, locate, 1, PH_NOISY, "winer/Image/Driver/Gd.zep", 527 TSRMLS_CC);
			ZEPHIR_ADD_ASSIGN(x, posx);
			ZEPHIR_ADD_ASSIGN(y, posy);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不支持的文字位置类型", "winer/Image/Driver/Gd.zep", 531);
			return;
		}
	} while(0);

	if (Z_TYPE_P(offset) == IS_ARRAY) {
		ZEPHIR_SINIT_NVAR(_30);
		ZVAL_STRING(&_30, "intval", 0);
		ZEPHIR_CALL_FUNCTION(&_31, "array_map", &_33, &_30, offset);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(offset, _31);
		ZEPHIR_OBS_VAR(ox);
		zephir_array_fetch_long(&ox, offset, 0, PH_NOISY, "winer/Image/Driver/Gd.zep", 540 TSRMLS_CC);
		ZEPHIR_OBS_VAR(oy);
		zephir_array_fetch_long(&oy, offset, 1, PH_NOISY, "winer/Image/Driver/Gd.zep", 541 TSRMLS_CC);
	} else {
		_34 = zephir_get_intval(offset);
		ZEPHIR_INIT_NVAR(offset);
		ZVAL_LONG(offset, _34);
		ZEPHIR_CPY_WRT(ox, offset);
		ZEPHIR_CPY_WRT(oy, offset);
	}
	_35 = Z_TYPE_P(color) == IS_STRING;
	if (_35) {
		ZEPHIR_SINIT_NVAR(_30);
		ZVAL_STRING(&_30, "#", 0);
		ZEPHIR_INIT_NVAR(_3);
		zephir_fast_strpos(_3, color, &_30, 0 );
		_35 = ZEPHIR_IS_LONG_IDENTICAL(_3, 0);
	}
	if (_35) {
		ZEPHIR_SINIT_VAR(_36);
		ZVAL_LONG(&_36, 1);
		ZEPHIR_INIT_VAR(_37);
		zephir_substr(_37, color, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_SINIT_VAR(_38);
		ZVAL_LONG(&_38, 2);
		ZEPHIR_CALL_FUNCTION(&color, "str_split", &_39, _37, &_38);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_38);
		ZVAL_STRING(&_38, "hexdec", 0);
		ZEPHIR_CALL_FUNCTION(&_31, "array_map", &_33, &_38, color);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(color, _31);
		ZEPHIR_OBS_VAR(_40);
		zephir_array_fetch_long(&_40, color, 3, PH_NOISY, "winer/Image/Driver/Gd.zep", 552 TSRMLS_CC);
		_41 = ZEPHIR_IS_EMPTY(_40);
		if (!(_41)) {
			zephir_array_fetch_long(&_27, color, 3, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 552 TSRMLS_CC);
			_41 = ZEPHIR_GT_LONG(_27, 127);
		}
		if (_41) {
			ZEPHIR_INIT_VAR(_42);
			ZVAL_LONG(_42, 0);
			zephir_array_update_long(&color, 3, &_42, PH_COPY | PH_SEPARATE, "winer/Image/Driver/Gd.zep", 553);
		}
	} else if (!(Z_TYPE_P(color) == IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "错误的颜色值", "winer/Image/Driver/Gd.zep", 556);
		return;
	}
	do {
		_26 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		zephir_array_fetch_long(&_27, color, 0, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 562 TSRMLS_CC);
		zephir_array_fetch_long(&_43, color, 1, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 562 TSRMLS_CC);
		zephir_array_fetch_long(&_44, color, 2, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 562 TSRMLS_CC);
		zephir_array_fetch_long(&_45, color, 3, PH_NOISY | PH_READONLY, "winer/Image/Driver/Gd.zep", 562 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&col, "imagecolorallocatealpha", &_46, _26, _27, _43, _44, _45);
		zephir_check_call_status();
		_28 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_30);
		zephir_add_function_ex(&_30, x, ox TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_36);
		zephir_add_function_ex(&_36, y, oy TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", &_47, _28, size, angle, &_30, &_36, col, font, text);
		zephir_check_call_status();
	} while (0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 析构方法，用于销毁图像资源
 */
PHP_METHOD(Winer_Image_Driver_Gd, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("img"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0) == 0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("img"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _1);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

