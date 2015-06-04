
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/exception.h"

ZEPHIR_INIT_CLASS(Winer_Upload) {

	ZEPHIR_REGISTER_CLASS(Winer, Upload, winer, upload, winer_upload_method_entry, 0);

	/**
	 * 默认上传配置
	 * @var array
	 */
	zend_declare_property_null(winer_upload_ce, SL("config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 上传错误信息
	 * @var string
	 */
	zend_declare_property_string(winer_upload_ce, SL("error"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 上传驱动实例
	 * @var Object
	 */
	zend_declare_property_null(winer_upload_ce, SL("uploader"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造方法，用于构造上传实例
 * @param array config 配置
 * @param string driver 要使用的上传驱动 LOCAL-本地上传驱动，FTP-FTP上传驱动
 */
PHP_METHOD(Winer_Upload, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *driver = NULL;
	zval *config_param = NULL, *driver_param = NULL, *driverConfig_param = NULL, *_1 = NULL, *_3, *_5, *_6, *_7, *_8, *_9 = NULL, *_10, *_11, *_12 = NULL, _13 = zval_used_for_init, *_14 = NULL, *_16, *_17, *_18, *_19, *_20;
	zval *config = NULL, *driverConfig = NULL, *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &config_param, &driver_param, &driverConfig_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}
	if (!driver_param) {
		ZEPHIR_INIT_VAR(driver);
		ZVAL_STRING(driver, "", 1);
	} else {
		zephir_get_strval(driver, driver_param);
	}
	if (!driverConfig_param) {
	ZEPHIR_INIT_VAR(driverConfig);
	array_init(driverConfig);
	} else {
		zephir_get_arrval(driverConfig, driverConfig_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 17);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_array_update_string(&_0, SL("mimes"), &_1, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_0, SS("maxSize"), 0);
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	zephir_array_update_string(&_0, SL("exts"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("autoSub"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 3);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "date", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Y-m-d", 1);
	zephir_array_fast_append(_2, _1);
	zephir_array_update_string(&_0, SL("subName"), &_2, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("rootPath"), SL("./Uploads/"), 1);
	add_assoc_stringl_ex(_0, SS("savePath"), SL(""), 1);
	ZEPHIR_INIT_NVAR(_2);
	array_init_size(_2, 3);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "uniqid", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "", 1);
	zephir_array_fast_append(_2, _1);
	zephir_array_update_string(&_0, SL("saveName"), &_2, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("saveExt"), SL(""), 1);
	zephir_array_update_string(&_0, SL("replace"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("hash"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(_0, SS("driver"), SL("local"), 1);
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	zephir_array_update_string(&_0, SL("driverConfig"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_fast_array_merge(_1, &(_3), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdriver", &_4, driver, driverConfig);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_6);
	zephir_array_fetch_string(&_6, _5, SL("mimes"), PH_NOISY, "winer/upload.zep", 55 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_6))) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_8, _7, SL("mimes"), PH_NOISY | PH_READONLY, "winer/upload.zep", 56 TSRMLS_CC);
		if (Z_TYPE_P(_8) == IS_STRING) {
			ZEPHIR_INIT_VAR(_9);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_11, _10, SL("mimes"), PH_NOISY | PH_READONLY, "winer/upload.zep", 57 TSRMLS_CC);
			zephir_fast_explode_str(_9, SL(","), _11, LONG_MAX TSRMLS_CC);
			ZEPHIR_INIT_VAR(_12);
			ZVAL_STRING(_12, "mimes", 1);
			zephir_update_property_array(this_ptr, SL("config"), _12, _9 TSRMLS_CC);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_11, _10, SL("mimes"), PH_NOISY | PH_READONLY, "winer/upload.zep", 59 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_13);
		ZVAL_STRING(&_13, "strtolower", 0);
		ZEPHIR_CALL_FUNCTION(&_14, "array_map", &_15, &_13, _11);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "mimes", 1);
		zephir_update_property_array(this_ptr, SL("config"), _9, _14 TSRMLS_CC);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_16);
	zephir_array_fetch_string(&_16, _7, SL("exts"), PH_NOISY, "winer/upload.zep", 61 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_16))) {
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_8, _17, SL("exts"), PH_NOISY | PH_READONLY, "winer/upload.zep", 62 TSRMLS_CC);
		if (Z_TYPE_P(_8) == IS_STRING) {
			ZEPHIR_INIT_NVAR(_12);
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_19, _18, SL("exts"), PH_NOISY | PH_READONLY, "winer/upload.zep", 63 TSRMLS_CC);
			zephir_fast_explode_str(_12, SL(","), _19, LONG_MAX TSRMLS_CC);
			ZEPHIR_INIT_VAR(_20);
			ZVAL_STRING(_20, "exts", 1);
			zephir_update_property_array(this_ptr, SL("config"), _20, _12 TSRMLS_CC);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_11, _10, SL("exts"), PH_NOISY | PH_READONLY, "winer/upload.zep", 65 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_13);
		ZVAL_STRING(&_13, "strtolower", 0);
		ZEPHIR_CALL_FUNCTION(&_14, "array_map", &_15, &_13, _11);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "exts", 1);
		zephir_update_property_array(this_ptr, SL("config"), _9, _14 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Winer_Upload, __set) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name, *value, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		zephir_update_property_array(this_ptr, SL("config"), name, value TSRMLS_CC);
		if (ZEPHIR_IS_STRING(name, "driverConfig")) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdriver", &_1);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取最后一次上传错误信息
 * @return string 错误信息
 */
PHP_METHOD(Winer_Upload, getError) {


	RETURN_MEMBER(this_ptr, "error");

}

/**
 * 上传单个文件
 * @param  array  file 文件数组
 * @return array       上传成功后的文件信息
 */
PHP_METHOD(Winer_Upload, uploadOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *file, *info = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	zephir_array_fast_append(_0, file);
	ZEPHIR_CALL_METHOD(&info, this_ptr, "upload", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	if (zephir_is_true(info)) {
		zephir_array_fetch_long(&_1, info, 0, PH_NOISY, "winer/upload.zep", 96 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(_1, info);
	}
	RETURN_CCTOR(_1);

}

/**
 * 上传文件
 * @param 文件信息数组 files 通常是 _FILES数组
 * @return boolean
 */
PHP_METHOD(Winer_Upload, upload) {

	zval *_33 = NULL;
	zephir_fcall_cache_entry *_19 = NULL;
	zend_bool _16, _36, _37;
	HashTable *_12;
	HashPosition _11;
	zephir_nts_static zephir_fcall_cache_entry *_10 = NULL, *_15 = NULL, *_21 = NULL, *_23 = NULL, *_26 = NULL, *_29 = NULL, *_30 = NULL, *_31 = NULL, *_35 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *files = NULL, *_FILES, *_0, *_1 = NULL, *_2, *_3, *_4, *_5 = NULL, *_6, *_7, *_8 = NULL, *info, *finfo = NULL, _9 = zval_used_for_init, *key = NULL, *file = NULL, **_13, *_14, *_17, *_18, *_20 = NULL, *_22 = NULL, *_24, *_25 = NULL, *_27, *_28 = NULL, *savename = NULL, *subpath = NULL, *_32 = NULL, *ext = NULL, *_34 = NULL, *imginfo = NULL, *_38 = NULL, *_39, *_40;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &files);

	if (!files) {
		ZEPHIR_CPY_WRT(files, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(files);
	}
	ZEPHIR_INIT_VAR(info);
	array_init(info);
	ZEPHIR_INIT_VAR(finfo);
	ZVAL_NULL(finfo);


	if (ZEPHIR_IS_EMPTY(files)) {
		zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
		ZEPHIR_CPY_WRT(files, _FILES);
	}
	if (ZEPHIR_IS_EMPTY(files)) {
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_STRING(_0, "没有上传的文件！", 1);
		zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("rootPath"), PH_NOISY | PH_READONLY, "winer/upload.zep", 114 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "checkrootpath", NULL, _3);
	zephir_check_call_status();
	if (!zephir_is_true(_1)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5, _4, "geterror", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("error"), _5 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_6, _4, SL("savePath"), PH_NOISY | PH_READONLY, "winer/upload.zep", 120 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, _0, "checksavepath", NULL, _6);
	zephir_check_call_status();
	if (!zephir_is_true(_5)) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_8, _7, "geterror", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("error"), _8 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	if ((zephir_function_exists_ex(SS("finfo_open") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, 16);
		ZEPHIR_CALL_FUNCTION(&finfo, "finfo_open", NULL, &_9);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "dealfiles", &_10, files);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(files, _5);
	zephir_is_iterable(files, &_12, &_11, 0, 0, "winer/upload.zep", 198);
	for (
	  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
	  ; zephir_hash_move_forward_ex(_12, &_11)
	) {
		ZEPHIR_GET_HMKEY(key, _12, _11);
		ZEPHIR_GET_HVALUE(file, _13);
		zephir_array_fetch_string(&_14, file, SL("name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 137 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_5, "strip_tags", &_15, _14);
		zephir_check_call_status();
		zephir_array_update_string(&file, SL("name"), &_5, PH_COPY | PH_SEPARATE);
		if (!(zephir_array_isset_string(file, SS("key")))) {
			zephir_array_update_string(&file, SL("key"), &key, PH_COPY | PH_SEPARATE);
		}
		_16 = !(ZEPHIR_IS_EMPTY(finfo));
		if (_16) {
			zephir_array_fetch_string(&_17, file, SL("error"), PH_NOISY | PH_READONLY, "winer/upload.zep", 142 TSRMLS_CC);
			_16 = ZEPHIR_IS_LONG_IDENTICAL(_17, 0);
		}
		if (_16) {
			zephir_array_fetch_string(&_18, file, SL("tmp_name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 143 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_8, "finfo_file", &_19, finfo, _18);
			zephir_check_call_status();
			zephir_array_update_string(&file, SL("type"), &_8, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_18, file, SL("name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 146 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_LONG(&_9, 4);
		ZEPHIR_CALL_FUNCTION(&_20, "pathinfo", &_21, _18, &_9);
		zephir_check_call_status();
		zephir_array_update_string(&file, SL("ext"), &_20, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_22, this_ptr, "check", &_23, file);
		zephir_check_call_status();
		if (!zephir_is_true(_22)) {
			continue;
		}
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_18, _0, SL("hash"), PH_NOISY | PH_READONLY, "winer/upload.zep", 153 TSRMLS_CC);
		if (zephir_is_true(_18)) {
			zephir_array_fetch_string(&_24, file, SL("tmp_name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 154 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_25, "md5_file", &_26, _24);
			zephir_check_call_status();
			zephir_array_update_string(&file, SL("md5"), &_25, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_27, file, SL("tmp_name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 155 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_28, "sha1_file", &_29, _27);
			zephir_check_call_status();
			zephir_array_update_string(&file, SL("sha1"), &_28, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CALL_METHOD(&savename, this_ptr, "getsavename", &_30, file);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(savename)) {
			continue;
		} else {
			zephir_array_update_string(&file, SL("savename"), &savename, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_18, file, SL("name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 169 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&subpath, this_ptr, "getsubpath", &_31, _18);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(subpath)) {
			continue;
		} else {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_18, _4, SL("savePath"), PH_NOISY | PH_READONLY, "winer/upload.zep", 173 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_32);
			ZEPHIR_CONCAT_VV(_32, _18, subpath);
			zephir_array_update_string(&file, SL("savepath"), &_32, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_INIT_NVAR(ext);
		zephir_array_fetch_string(&_18, file, SL("ext"), PH_NOISY | PH_READONLY, "winer/upload.zep", 178 TSRMLS_CC);
		zephir_fast_strtolower(ext, _18);
		ZEPHIR_INIT_NVAR(_33);
		array_init_size(_33, 8);
		ZEPHIR_INIT_NVAR(_34);
		ZVAL_STRING(_34, "gif", 1);
		zephir_array_fast_append(_33, _34);
		ZEPHIR_INIT_NVAR(_34);
		ZVAL_STRING(_34, "jpg", 1);
		zephir_array_fast_append(_33, _34);
		ZEPHIR_INIT_NVAR(_34);
		ZVAL_STRING(_34, "jpeg", 1);
		zephir_array_fast_append(_33, _34);
		ZEPHIR_INIT_NVAR(_34);
		ZVAL_STRING(_34, "bmp", 1);
		zephir_array_fast_append(_33, _34);
		ZEPHIR_INIT_NVAR(_34);
		ZVAL_STRING(_34, "png", 1);
		zephir_array_fast_append(_33, _34);
		ZEPHIR_INIT_NVAR(_34);
		ZVAL_STRING(_34, "swf", 1);
		zephir_array_fast_append(_33, _34);
		if (zephir_fast_in_array(ext, _33 TSRMLS_CC)) {
			zephir_array_fetch_string(&_24, file, SL("tmp_name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 181 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&imginfo, "getimagesize", &_35, _24);
			zephir_check_call_status();
			_36 = ZEPHIR_IS_EMPTY(imginfo);
			if (!(_36)) {
				_37 = ZEPHIR_IS_STRING(ext, "gif");
				if (_37) {
					ZEPHIR_OBS_NVAR(_38);
					zephir_array_fetch_string(&_38, imginfo, SL("bits"), PH_NOISY, "winer/upload.zep", 182 TSRMLS_CC);
					_37 = ZEPHIR_IS_EMPTY(_38);
				}
				_36 = _37;
			}
			if (_36) {
				ZEPHIR_INIT_ZVAL_NREF(_7);
				ZVAL_STRING(_7, "非法图像文件！", 1);
				zephir_update_property_this(this_ptr, SL("error"), _7 TSRMLS_CC);
				continue;
			}
		}
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
		_39 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_18, _39, SL("replace"), PH_NOISY | PH_READONLY, "winer/upload.zep", 189 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_25, _7, "save", NULL, file, _18);
		zephir_check_call_status();
		if (zephir_is_true(_25)) {
			zephir_array_unset_string(&file, SS("error"), PH_SEPARATE);
			zephir_array_unset_string(&file, SS("tmp_name"), PH_SEPARATE);
			zephir_array_update_zval(&info, key, &file, PH_COPY | PH_SEPARATE);
		} else {
			_40 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_25, _40, "geterror", NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("error"), _25 TSRMLS_CC);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(finfo))) {
		ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, finfo);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_34);
	if (ZEPHIR_IS_EMPTY(info)) {
		ZVAL_BOOL(_34, 0);
	} else {
		ZEPHIR_CPY_WRT(_34, info);
	}
	RETURN_CCTOR(_34);

}

/**
 * 转换上传文件数组变量为正确的方式
 * @access private
 * @param array files  上传的文件变量
 * @return array
 */
PHP_METHOD(Winer_Upload, dealFiles) {

	HashTable *_1, *_6;
	HashPosition _0, _5;
	int n = 0, i = 0;
	zval *files_param = NULL, *fileArray = NULL, *key = NULL, *file = NULL, *count = NULL, *keys = NULL, *_key = NULL, **_2, *_3, *_4, **_7, *_8, *_9;
	zval *files = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &files_param);

	zephir_get_arrval(files, files_param);
	ZEPHIR_INIT_VAR(fileArray);
	array_init(fileArray);


	zephir_is_iterable(files, &_1, &_0, 0, 0, "winer/upload.zep", 236);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(file, _2);
		zephir_array_fetch_string(&_3, file, SL("name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 219 TSRMLS_CC);
		if (Z_TYPE_P(_3) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(keys);
			zephir_array_keys(keys, file TSRMLS_CC);
			zephir_array_fetch_string(&_4, file, SL("name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 221 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(count);
			ZVAL_LONG(count, zephir_fast_count_int(_4 TSRMLS_CC));
			while (1) {
				if (!(ZEPHIR_GT_LONG(count, i))) {
					break;
				}
				i++;
				zephir_array_update_multi(&fileArray, &key TSRMLS_CC, SL("ls"), 3, n, SL("key"));
				zephir_is_iterable(keys, &_6, &_5, 0, 0, "winer/upload.zep", 229);
				for (
				  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6, &_5)
				) {
					ZEPHIR_GET_HVALUE(_key, _7);
					zephir_array_fetch(&_8, file, _key, PH_NOISY | PH_READONLY, "winer/upload.zep", 227 TSRMLS_CC);
					zephir_array_fetch_long(&_9, _8, i, PH_NOISY | PH_READONLY, "winer/upload.zep", 227 TSRMLS_CC);
					zephir_array_update_multi(&fileArray, &_9 TSRMLS_CC, SL("lz"), 2, n, _key);
				}
				n++;
			}
		} else {
			ZEPHIR_CPY_WRT(fileArray, files);
			break;
		}
	}
	RETURN_CCTOR(fileArray);

}

/**
 * 设置上传驱动
 * @param string driver 驱动名称
 * @param array config 驱动配置
 * @return void  
 */
PHP_METHOD(Winer_Upload, setDriver) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_9;
	zval *driver = NULL, *config = NULL, *class_name = NULL, *_0 = NULL, *_1, *_2, _3, *_4, *_5, *_6, *_7, *_8 = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &driver, &config);

	if (!driver) {
		ZEPHIR_INIT_VAR(driver);
		ZVAL_STRING(driver, "", 1);
	} else {
		ZEPHIR_SEPARATE_PARAM(driver);
	}
	if (!config) {
		ZEPHIR_CPY_WRT(config, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(config);
	}


	ZEPHIR_INIT_VAR(_0);
	if (zephir_fast_strlen_ev(driver) > 0) {
		ZEPHIR_CPY_WRT(_0, driver);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(_0);
		zephir_array_fetch_string(&_0, _1, SL("driver"), PH_NOISY, "winer/upload.zep", 247 TSRMLS_CC);
	}
	ZEPHIR_CPY_WRT(driver, _0);
	ZEPHIR_INIT_LNVAR(_0);
	if (zephir_is_true(config)) {
		ZEPHIR_CPY_WRT(_0, config);
	} else {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(_0);
		zephir_array_fetch_string(&_0, _2, SL("driverConfig"), PH_NOISY, "winer/upload.zep", 248 TSRMLS_CC);
	}
	ZEPHIR_CPY_WRT(config, _0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "\\", 0);
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_strpos(_4, driver, &_3, 0 );
	if (zephir_is_true(_4)) {
		ZEPHIR_CPY_WRT(class_name, driver);
	} else {
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_INIT_VAR(_6);
		zephir_fast_strtolower(_6, driver);
		zephir_ucfirst(_5, _6);
		ZEPHIR_INIT_NVAR(class_name);
		ZEPHIR_CONCAT_SV(class_name, "winer\\Upload\\Driver\\", _5);
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_fetch_safe_class(_8, class_name);
	_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_7, _9);
	if (zephir_has_constructor(_7 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, config);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("uploader"), _7 TSRMLS_CC);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
	if (!zephir_is_true(_10)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "不存在上传驱动：{driver}", "winer/upload.zep", 252);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 检查上传的文件
 * @param array file 文件信息
 * @return boolean
 */
PHP_METHOD(Winer_Upload, check) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *file, *_0, *_1, *_3, *_4, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	zephir_array_fetch_string(&_0, file, SL("error"), PH_NOISY | PH_READONLY, "winer/upload.zep", 263 TSRMLS_CC);
	if (zephir_is_true(_0)) {
		zephir_array_fetch_string(&_1, file, SL("error"), PH_NOISY | PH_READONLY, "winer/upload.zep", 264 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "error", &_2, _1);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_string(&_3, file, SL("name"), PH_NOISY, "winer/upload.zep", 269 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_3)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_STRING(_4, "未知上传错误！", 1);
		zephir_update_property_this(this_ptr, SL("error"), _4 TSRMLS_CC);
	}
	zephir_array_fetch_string(&_1, file, SL("tmp_name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 274 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_5, "is_uploaded_file", &_6, _1);
	zephir_check_call_status();
	if (!zephir_is_true(_5)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_STRING(_4, "非法上传文件！", 1);
		zephir_update_property_this(this_ptr, SL("error"), _4 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_1, file, SL("size"), PH_NOISY | PH_READONLY, "winer/upload.zep", 280 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "checksize", &_8, _1);
	zephir_check_call_status();
	if (!zephir_is_true(_7)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_STRING(_4, "上传文件大小不符！", 1);
		zephir_update_property_this(this_ptr, SL("error"), _4 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_1, file, SL("type"), PH_NOISY | PH_READONLY, "winer/upload.zep", 287 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "checkmime", &_10, _1);
	zephir_check_call_status();
	if (!zephir_is_true(_9)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_STRING(_4, "上传文件MIME类型不允许！", 1);
		zephir_update_property_this(this_ptr, SL("error"), _4 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_1, file, SL("ext"), PH_NOISY | PH_READONLY, "winer/upload.zep", 293 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "checkext", &_12, _1);
	zephir_check_call_status();
	if (!zephir_is_true(_11)) {
		ZEPHIR_INIT_ZVAL_NREF(_4);
		ZVAL_STRING(_4, "上传文件后缀不允许", 1);
		zephir_update_property_this(this_ptr, SL("error"), _4 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * 获取错误代码信息
 * @param string errorNo 错误号
 * @return void
 */
PHP_METHOD(Winer_Upload, error) {

	zval *errorNo, *_0;

	zephir_fetch_params(0, 1, 0, &errorNo);



	do {
		if (ZEPHIR_IS_LONG(errorNo, 1)) {
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_STRING(_0, "上传的文件超过了 php.ini 中 upload_max_filesize 选项限制的值！", 1);
			zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(errorNo, 2)) {
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_STRING(_0, "上传文件的大小超过了 HTML 表单中 MAX_FILE_SIZE 选项指定的值！", 1);
			zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(errorNo, 3)) {
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_STRING(_0, "文件只有部分被上传！", 1);
			zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(errorNo, 4)) {
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_STRING(_0, "没有文件被上传！", 1);
			zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(errorNo, 6)) {
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_STRING(_0, "找不到临时文件夹！", 1);
			zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(errorNo, 7)) {
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_STRING(_0, "文件写入失败！", 1);
			zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
			break;
		}
		ZEPHIR_INIT_ZVAL_NREF(_0);
		ZVAL_STRING(_0, "未知上传错误！", 1);
		zephir_update_property_this(this_ptr, SL("error"), _0 TSRMLS_CC);
	} while(0);


}

/**
 * 检查文件大小是否合法
 * @param integer size 数据
 * @return boolean
 */
PHP_METHOD(Winer_Upload, checkSize) {

	zval *size, *_0, *_1, *_2, *_3;

	zephir_fetch_params(0, 1, 0, &size);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("maxSize"), PH_NOISY | PH_READONLY, "winer/upload.zep", 339 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("maxSize"), PH_NOISY | PH_READONLY, "winer/upload.zep", 341 TSRMLS_CC);
	if (!(ZEPHIR_GT(size, _1))) {
		RETURN_BOOL(1);
	} else if (ZEPHIR_IS_LONG(_3, 0)) {
		RETURN_BOOL(1);
	} else {
		RETURN_BOOL(0);
	}

}

/**
 * 检查上传的文件MIME类型是否合法
 * @param string mime 数据
 * @return boolean
 */
PHP_METHOD(Winer_Upload, checkMime) {

	zval *mime, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mime);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_array_fetch_string(&_1, _0, SL("mimes"), PH_NOISY, "winer/upload.zep", 354 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_1)) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_VAR(_2);
		zephir_fast_strtolower(_2, mime);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_4, _3, SL("mimes"), PH_NOISY | PH_READONLY, "winer/upload.zep", 357 TSRMLS_CC);
		RETURN_MM_BOOL(zephir_fast_in_array(_2, _4 TSRMLS_CC));
	}

}

/**
 * 检查上传的文件后缀是否合法
 * @param string ext 后缀
 * @return boolean
 */
PHP_METHOD(Winer_Upload, checkExt) {

	zval *ext, *_0, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ext);



	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_array_fetch_string(&_2, _1, SL("exts"), PH_NOISY, "winer/upload.zep", 367 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZEPHIR_INIT_VAR(_3);
		zephir_fast_strtolower(_3, ext);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _4, SL("exts"), PH_NOISY | PH_READONLY, "winer/upload.zep", 367 TSRMLS_CC);
		ZVAL_BOOL(_0, zephir_fast_in_array(_3, _5 TSRMLS_CC));
	}
	RETURN_CCTOR(_0);

}

/**
 * 根据上传文件命名规则取得保存文件名
 * @param string file 文件信息
 * @return string
 */
PHP_METHOD(Winer_Upload, getSaveName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zval *ext = NULL;
	zval *file, *rule, *filename, *savename = NULL, *_0, *_1, *_2 = NULL, _3 = zval_used_for_init, *_4 = NULL, *_7, *_8, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(rule);
	zephir_array_fetch_string(&rule, _0, SL("saveName"), PH_NOISY, "winer/upload.zep", 380 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(rule)) {
		zephir_array_fetch_string(&_1, file, SL("name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 383 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "_", _1);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, 8);
		ZEPHIR_CALL_FUNCTION(&_4, "pathinfo", &_5, _2, &_3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 1);
		ZEPHIR_INIT_VAR(filename);
		zephir_substr(filename, _4, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(savename, filename);
	} else {
		zephir_array_fetch_string(&_1, file, SL("name"), PH_NOISY | PH_READONLY, "winer/upload.zep", 386 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&savename, this_ptr, "getname", &_6, rule, _1);
		zephir_check_call_status();
		if (ZEPHIR_IS_EMPTY(savename)) {
			ZEPHIR_INIT_ZVAL_NREF(_7);
			ZVAL_STRING(_7, "文件命名规则错误！", 1);
			zephir_update_property_this(this_ptr, SL("error"), _7 TSRMLS_CC);
			RETURN_MM_STRING("", 1);
		}
	}
	ZEPHIR_INIT_LNVAR(_2);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_8);
	zephir_array_fetch_string(&_8, _7, SL("saveExt"), PH_NOISY, "winer/upload.zep", 393 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(_8)) {
		ZEPHIR_OBS_NVAR(_2);
		zephir_array_fetch_string(&_2, file, SL("ext"), PH_NOISY, "winer/upload.zep", 393 TSRMLS_CC);
	} else {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(_2);
		zephir_array_fetch_string(&_2, _9, SL("saveExt"), PH_NOISY, "winer/upload.zep", 393 TSRMLS_CC);
	}
	zephir_get_strval(ext, _2);
	ZEPHIR_CONCAT_VSV(return_value, savename, ".", ext);
	RETURN_MM();

}

/**
 * 获取子目录的名称
 * @param array file  上传的文件信息
 * @return string
 */
PHP_METHOD(Winer_Upload, getSubPath) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _3, _7;
	zval *subpath = NULL;
	zval *filename, *rule, *_0, *_1, *_2, *_4 = NULL, *_6, *_8, *_9 = NULL, *_10, *_11, *_12, *_13, *_14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename);

	ZEPHIR_INIT_VAR(subpath);
	ZVAL_STRING(subpath, "", 1);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(rule);
	zephir_array_fetch_string(&rule, _0, SL("subName"), PH_NOISY, "winer/upload.zep", 405 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("autoSub"), PH_NOISY | PH_READONLY, "winer/upload.zep", 406 TSRMLS_CC);
	_3 = zephir_is_true(_2);
	if (_3) {
		_3 = !(ZEPHIR_IS_EMPTY(rule));
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "getname", &_5, rule, filename);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_VS(_6, _4, "/");
		zephir_get_strval(subpath, _6);
		_7 = !(ZEPHIR_IS_EMPTY(subpath));
		if (_7) {
			_8 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
			_10 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_11, _10, SL("savePath"), PH_NOISY | PH_READONLY, "winer/upload.zep", 408 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_12);
			ZEPHIR_CONCAT_VV(_12, _11, subpath);
			ZEPHIR_CALL_METHOD(&_9, _8, "mkdir", NULL, _12);
			zephir_check_call_status();
			_7 = !zephir_is_true(_9);
		}
		if (_7) {
			_13 = zephir_fetch_nproperty_this(this_ptr, SL("uploader"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_14, _13, "geterror", NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("error"), _14 TSRMLS_CC);
			RETURN_CTOR(subpath);
		}
	}
	RETURN_CTOR(subpath);

}

/**
 * 根据指定的规则获取文件或目录名称
 * @param  array  rule     规则
 * @param  string filename 原文件名
 * @return string          文件或目录名称
 */
PHP_METHOD(Winer_Upload, getName) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *filename = NULL;
	zval *rule, *filename_param = NULL, *name = NULL, *func, *param, *value = NULL, *_0, **_3, *_4 = NULL, _5 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &rule, &filename_param);

	zephir_get_strval(filename, filename_param);
	ZEPHIR_INIT_VAR(name);
	ZVAL_STRING(name, "", 1);


	if (Z_TYPE_P(rule) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(func);
		zephir_array_fetch_long(&func, rule, 0, PH_NOISY, "winer/upload.zep", 428 TSRMLS_CC);
		ZEPHIR_INIT_VAR(param);
		array_init_size(param, 2);
		ZEPHIR_OBS_VAR(_0);
		zephir_array_fetch_long(&_0, rule, 1, PH_NOISY, "winer/upload.zep", 429 TSRMLS_CC);
		zephir_array_fast_append(param, _0);
		zephir_is_iterable(param, &_2, &_1, 0, 0, "winer/upload.zep", 433);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(value, _3);
			ZEPHIR_INIT_NVAR(_4);
			ZEPHIR_SINIT_NVAR(_5);
			ZVAL_STRING(&_5, "__FILE__", 0);
			zephir_fast_str_replace(_4, &_5, filename, value TSRMLS_CC);
			ZEPHIR_CPY_WRT(value, _4);
		}
		ZEPHIR_INIT_NVAR(name);
		ZEPHIR_CALL_USER_FUNC_ARRAY(name, func, param);
		zephir_check_call_status();
	} else if (Z_TYPE_P(rule) == IS_STRING) {
		if ((zephir_function_exists(rule TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_INIT_NVAR(name);
			ZEPHIR_CALL_USER_FUNC(name, rule);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(name, rule);
		}
	}
	RETURN_CCTOR(name);

}

