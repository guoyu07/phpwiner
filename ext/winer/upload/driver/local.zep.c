
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Winer_Upload_Driver_Local) {

	ZEPHIR_REGISTER_CLASS(Winer\\Upload\\Driver, Local, winer, upload_driver_local, winer_upload_driver_local_method_entry, 0);

	/**
	 * 上传文件根目录
	 * @var string
	 */
	zend_declare_property_null(winer_upload_driver_local_ce, SL("rootPath"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * 本地上传错误信息
	 * @var string
	 */
	zend_declare_property_string(winer_upload_driver_local_ce, SL("error"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数，用于设置上传根路径
 */
PHP_METHOD(Winer_Upload_Driver_Local, __construct) {

	zval *config = NULL;

	zephir_fetch_params(0, 0, 1, &config);

	if (!config) {
		config = ZEPHIR_GLOBAL(global_null);
	}



}

/**
 * 检测上传根目录
 * @param string rootpath 根目录
 * @return boolean true-检测通过，false-检测失败
 */
PHP_METHOD(Winer_Upload_Driver_Local, checkRootPath) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *rootpath, *_0 = NULL, *_3 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rootpath);



	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", &_1, rootpath);
	zephir_check_call_status();
	_2 = zephir_is_true(_0);
	if (_2) {
		ZEPHIR_CALL_FUNCTION(&_3, "is_writable", &_4, rootpath);
		zephir_check_call_status();
		_2 = zephir_is_true(_3);
	}
	if (!(_2)) {
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SV(_5, "上传根目录不存在！请尝试手动创建:", rootpath);
		zephir_update_property_this(this_ptr, SL("error"), _5 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_this(this_ptr, SL("rootPath"), rootpath TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

/**
 * 检测上传目录
 * @param string savepath 上传目录
 * @return boolean 检测结果，true-通过，false-失败
 */
PHP_METHOD(Winer_Upload_Driver_Local, checkSavePath) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepath, *_0 = NULL, *_1, *_2, *_3 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepath);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "mkdir", NULL, savepath);
	zephir_check_call_status();
	if (!zephir_is_true(_0)) {
		RETURN_MM_BOOL(0);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("rootPath"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VV(_2, _1, savepath);
		ZEPHIR_CALL_FUNCTION(&_3, "is_writable", &_4, _2);
		zephir_check_call_status();
		if (!zephir_is_true(_3)) {
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "上传目录 ", savepath, " 不可写！");
			zephir_update_property_this(this_ptr, SL("error"), _5 TSRMLS_CC);
			RETURN_MM_BOOL(0);
		} else {
			RETURN_MM_BOOL(1);
		}
	}

}

/**
 * 保存指定文件
 * @param array file 保存的文件信息
 * @param boolean replace 同名文件是否覆盖
 * @return boolean 保存状态，true-成功，false-失败
 */
PHP_METHOD(Winer_Upload_Driver_Local, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_bool _4;
	zval *filename = NULL;
	zval *file, *replace = NULL, *_0, *_1, *_2, *_3, *_5 = NULL, *_7, *_8, *_9 = NULL, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file, &replace);

	if (!replace) {
		replace = ZEPHIR_GLOBAL(global_true);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootPath"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, file, SL("savepath"), PH_NOISY | PH_READONLY, "winer/Upload/Driver/Local.zep", 66 TSRMLS_CC);
	zephir_array_fetch_string(&_2, file, SL("savename"), PH_NOISY | PH_READONLY, "winer/Upload/Driver/Local.zep", 66 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VVV(_3, _0, _1, _2);
	zephir_get_strval(filename, _3);
	_4 = !zephir_is_true(replace);
	if (_4) {
		ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_6, filename);
		zephir_check_call_status();
		_4 = zephir_is_true(_5);
	}
	if (_4) {
		zephir_array_fetch_string(&_7, file, SL("savename"), PH_NOISY | PH_READONLY, "winer/Upload/Driver/Local.zep", 70 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SV(_8, "存在同名文件", _7);
		zephir_update_property_this(this_ptr, SL("error"), _8 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_7, file, SL("tmp_name"), PH_NOISY | PH_READONLY, "winer/Upload/Driver/Local.zep", 75 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_9, "move_uploaded_file", &_10, _7, filename);
	zephir_check_call_status();
	if (!zephir_is_true(_9)) {
		ZEPHIR_INIT_ZVAL_NREF(_11);
		ZVAL_STRING(_11, "文件上传保存错误！", 1);
		zephir_update_property_this(this_ptr, SL("error"), _11 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * 创建目录
 * @param string savepath 要创建的路径。
 * @return boolean 创建状态，true-成功，false-失败
 */
PHP_METHOD(Winer_Upload_Driver_Local, mkdir) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zval *dir = NULL;
	zval *savepath, *_0, *_1, *_2 = NULL, _4, *_5 = NULL, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepath);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("rootPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, savepath);
	zephir_get_strval(dir, _1);
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", &_3, dir);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 0777);
	ZEPHIR_CALL_FUNCTION(&_5, "mkdir", &_6, dir, &_4, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_7);
		ZVAL_STRING(_7, "目录 {savepath} 创建失败！", 1);
		zephir_update_property_this(this_ptr, SL("error"), _7 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取最后一次上传错误信息
 * @return string 错误信息
 */
PHP_METHOD(Winer_Upload_Driver_Local, getError) {


	RETURN_MEMBER(this_ptr, "error");

}

