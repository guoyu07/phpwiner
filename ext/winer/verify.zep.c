
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Winer_Verify) {

	ZEPHIR_REGISTER_CLASS(Winer, Verify, winer, verify, winer_verify_method_entry, 0);

	zend_declare_property_null(winer_verify_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(winer_verify_ce, SL("_image"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(winer_verify_ce, SL("_color"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * 架构方法 设置参数
 * @access public     
 * @param array config 配置参数
 */
PHP_METHOD(Winer_Verify, __construct) {

	zval *config_param = NULL, *_2 = NULL, *_3;
	zval *config = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &config_param);

	if (!config_param) {
		ZEPHIR_INIT_VAR(config);
		array_init(config);
	} else {
		zephir_get_arrval(config, config_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 17);
	add_assoc_stringl_ex(_0, SS("seKey"), SL("winer_Verify"), 1);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 66);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 2);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 3);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 4);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 5);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 6);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 7);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 8);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "a", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "b", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "c", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "d", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "e", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "f", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "h", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "i", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "j", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "k", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "m", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "n", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "p", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "q", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "r", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "s", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "t", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "u", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "v", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "w", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "x", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "y", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "z", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "A", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "B", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "C", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "D", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "E", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "F", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "G", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "H", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "J", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "K", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "L", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "M", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "N", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "P", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Q", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "R", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "T", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "U", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "V", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "W", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "X", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "Y", 1);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("codeSet"), &_1, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_0, SS("expire"), 1800);
	zephir_array_update_string(&_0, SL("useImgBg"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_0, SS("fontSize"), 25);
	add_assoc_long_ex(_0, SS("angle"), 0);
	zephir_array_update_string(&_0, SL("useCurve"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(_0, SS("imageH"), 100);
	add_assoc_long_ex(_0, SS("imageW"), 100);
	add_assoc_long_ex(_0, SS("length"), 5);
	add_assoc_stringl_ex(_0, SS("fontttf"), SL(""), 1);
	ZEPHIR_INIT_NVAR(_1);
	array_init_size(_1, 4);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 243);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 251);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 254);
	zephir_array_fast_append(_1, _2);
	zephir_array_update_string(&_0, SL("bg"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("reset"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_fast_array_merge(_2, &(_3), &(config) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("config"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 验证验证码是否正确
 * @access public
 * @param string code 用户验证码
 * @param string id 验证码标识     
 * @return bool 用户验证码是否正确
 */
PHP_METHOD(Winer_Verify, check) {

	zend_bool _4;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *code_param = NULL, *id_param = NULL, *key, *_0 = NULL, *_1, *_2, *secode, *_SESSION, *_5 = NULL, *_6, _7, *_8, *_9 = NULL, *_10, *_11, *_12;
	zval *code = NULL, *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &code_param, &id_param);

	zephir_get_strval(code, code_param);
	if (!id_param) {
		ZEPHIR_INIT_VAR(id);
		ZVAL_STRING(id, "", 1);
	} else {
		zephir_get_strval(id, id_param);
	}


	_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("seKey"), PH_NOISY | PH_READONLY, "winer/verify.zep", 48 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "authcode", &_3, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VV(key, _0, id);
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	ZEPHIR_OBS_VAR(secode);
	zephir_array_fetch(&secode, _SESSION, key, PH_NOISY, "winer/verify.zep", 51 TSRMLS_CC);
	_4 = ZEPHIR_IS_EMPTY(code);
	if (!(_4)) {
		_4 = ZEPHIR_IS_EMPTY(secode);
	}
	if (_4) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_time(_5);
	zephir_array_fetch_string(&_6, secode, SL("verify_time"), PH_NOISY | PH_READONLY, "winer/verify.zep", 56 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_7);
	sub_function(&_7, _5, _6 TSRMLS_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_6, _8, SL("expire"), PH_NOISY | PH_READONLY, "winer/verify.zep", 56 TSRMLS_CC);
	if (ZEPHIR_GT(&_7, _6)) {
		zephir_array_unset(&_SESSION, key, PH_SEPARATE);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_5);
	zephir_fast_strtoupper(_5, code);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "authcode", &_3, _5);
	zephir_check_call_status();
	zephir_array_fetch_string(&_10, secode, SL("verify_code"), PH_NOISY | PH_READONLY, "winer/verify.zep", 60 TSRMLS_CC);
	if (ZEPHIR_IS_EQUAL(_9, _10)) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_12, _11, SL("reset"), PH_NOISY | PH_READONLY, "winer/verify.zep", 61 TSRMLS_CC);
		if (zephir_is_true(_12)) {
			zephir_array_unset(&_SESSION, key, PH_SEPARATE);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

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
PHP_METHOD(Winer_Verify, entry) {

	zephir_nts_static zephir_fcall_cache_entry *_24 = NULL, *_30 = NULL, *_31 = NULL, *_50 = NULL, *_54 = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_49 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, codeNX = 0, i = 0, _53;
	zval *id_param = NULL, *ttfPath_param = NULL, *bgPath_param = NULL, *_0, *_1, *_2, *_3, *_4, *_5, _6 = zval_used_for_init, *_7, *_8, _9 = zval_used_for_init, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_22, *_23 = NULL, *_25 = NULL, *_26 = NULL, *_27 = NULL, *_28, *_29, *code = NULL, *_len = NULL, *_rand = NULL, *_32, *_33, *_34, *_35, *_36, *_37 = NULL, *_38, *_39, *_40, *_41, *_42, *_43, *_44, *_45, *_46, *_47, *_48, *key = NULL, *secode, *_51, *_SESSION, *_52;
	zval *id = NULL, *ttfPath = NULL, *bgPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &id_param, &ttfPath_param, &bgPath_param);

	if (!id_param) {
		ZEPHIR_INIT_VAR(id);
		ZVAL_STRING(id, "", 1);
	} else {
		zephir_get_strval(id, id_param);
	}
	if (!ttfPath_param) {
		ZEPHIR_INIT_VAR(ttfPath);
		ZVAL_STRING(ttfPath, "", 1);
	} else {
		zephir_get_strval(ttfPath, ttfPath_param);
	}
	if (!bgPath_param) {
		ZEPHIR_INIT_VAR(bgPath);
		ZVAL_STRING(bgPath, "", 1);
	} else {
		zephir_get_strval(bgPath, bgPath_param);
	}
	ZEPHIR_INIT_VAR(code);
	array_init(code);
	ZEPHIR_INIT_VAR(secode);
	array_init(secode);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("imageW"), PH_NOISY | PH_READONLY, "winer/verify.zep", 80 TSRMLS_CC);
	if (!zephir_is_true(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_3, _2, SL("length"), PH_NOISY | PH_READONLY, "winer/verify.zep", 81 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _4, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 81 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_6);
		mul_function(&_6, _3, _5 TSRMLS_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_3, _7, SL("length"), PH_NOISY | PH_READONLY, "winer/verify.zep", 81 TSRMLS_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _8, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 81 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_9);
		mul_function(&_9, _3, _5 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10);
		ZVAL_STRING(_10, "imageW", 1);
		ZEPHIR_INIT_VAR(_11);
		ZVAL_DOUBLE(_11, ((zephir_get_numberval(&_6) * 1.5) + zephir_safe_div_zval_long(&_9, 2 TSRMLS_CC)));
		zephir_update_property_array(this_ptr, SL("config"), _10, _11 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 84 TSRMLS_CC);
	if (zephir_is_true(_3)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _4, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 85 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "imageH", 1);
		ZEPHIR_INIT_NVAR(_11);
		ZVAL_DOUBLE(_11, (zephir_get_numberval(_5) * 2.5));
		zephir_update_property_array(this_ptr, SL("config"), _10, _11 TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("imageW"), PH_NOISY | PH_READONLY, "winer/verify.zep", 88 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, _4, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 88 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_12, "imagecreate", NULL, _3, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_image"), _12 TSRMLS_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_13, _8, SL("bg"), PH_NOISY | PH_READONLY, "winer/verify.zep", 90 TSRMLS_CC);
	zephir_array_fetch_long(&_14, _13, 0, PH_NOISY | PH_READONLY, "winer/verify.zep", 90 TSRMLS_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_16, _15, SL("bg"), PH_NOISY | PH_READONLY, "winer/verify.zep", 90 TSRMLS_CC);
	zephir_array_fetch_long(&_17, _16, 1, PH_NOISY | PH_READONLY, "winer/verify.zep", 90 TSRMLS_CC);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_19, _18, SL("bg"), PH_NOISY | PH_READONLY, "winer/verify.zep", 90 TSRMLS_CC);
	zephir_array_fetch_long(&_20, _19, 2, PH_NOISY | PH_READONLY, "winer/verify.zep", 90 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecolorallocate", &_21, _7, _14, _17, _20);
	zephir_check_call_status();
	_22 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 1);
	ZEPHIR_SINIT_NVAR(_9);
	ZVAL_LONG(&_9, 150);
	ZEPHIR_CALL_FUNCTION(&_23, "mt_rand", &_24, &_6, &_9);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 1);
	ZEPHIR_SINIT_NVAR(_9);
	ZVAL_LONG(&_9, 150);
	ZEPHIR_CALL_FUNCTION(&_25, "mt_rand", &_24, &_6, &_9);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 1);
	ZEPHIR_SINIT_NVAR(_9);
	ZVAL_LONG(&_9, 150);
	ZEPHIR_CALL_FUNCTION(&_26, "mt_rand", &_24, &_6, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_27, "imagecolorallocate", &_21, _22, _23, _25, _26);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_color"), _27 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "fontttf", 1);
	zephir_update_property_array(this_ptr, SL("config"), _10, ttfPath TSRMLS_CC);
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_29, _28, SL("useImgBg"), PH_NOISY | PH_READONLY, "winer/verify.zep", 97 TSRMLS_CC);
	if (zephir_is_true(_29)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_background", &_30, bgPath);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("useCurve"), PH_NOISY | PH_READONLY, "winer/verify.zep", 100 TSRMLS_CC);
	if (zephir_is_true(_3)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_writecurve", &_31);
		zephir_check_call_status();
	}
	while (1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_3, _2, SL("length"), PH_NOISY | PH_READONLY, "winer/verify.zep", 110 TSRMLS_CC);
		if (!(ZEPHIR_GT_LONG(_3, i))) {
			break;
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _4, SL("codeSet"), PH_NOISY | PH_READONLY, "winer/verify.zep", 112 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_len);
		ZVAL_LONG(_len, (zephir_fast_count_int(_5 TSRMLS_CC) - 1));
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 0);
		ZEPHIR_CALL_FUNCTION(&_rand, "mt_rand", &_24, &_6, _len);
		zephir_check_call_status();
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_32, _7, SL("codeSet"), PH_NOISY | PH_READONLY, "winer/verify.zep", 114 TSRMLS_CC);
		zephir_array_fetch(&_33, _32, _rand, PH_NOISY | PH_READONLY, "winer/verify.zep", 114 TSRMLS_CC);
		zephir_array_update_long(&code, i, &_33, PH_COPY | PH_SEPARATE, "winer/verify.zep", 114);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_34, _8, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 115 TSRMLS_CC);
		_35 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_36, _35, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 115 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_DOUBLE(&_6, (zephir_get_numberval(_34) * 1.2));
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_DOUBLE(&_9, (zephir_get_numberval(_36) * 1.4));
		ZEPHIR_CALL_FUNCTION(&_37, "mt_rand", &_24, &_6, &_9);
		zephir_check_call_status();
		codeNX = (i * zephir_get_numberval(_37));
		_38 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
		_39 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_40, _39, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 116 TSRMLS_CC);
		_41 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_42, _41, SL("angle"), PH_NOISY | PH_READONLY, "winer/verify.zep", 116 TSRMLS_CC);
		_43 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_44, _43, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 116 TSRMLS_CC);
		_45 = zephir_fetch_nproperty_this(this_ptr, SL("_color"), PH_NOISY_CC);
		_46 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_47, _46, SL("fontttf"), PH_NOISY | PH_READONLY, "winer/verify.zep", 116 TSRMLS_CC);
		zephir_array_fetch_long(&_48, code, i, PH_NOISY | PH_READONLY, "winer/verify.zep", 116 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, codeNX);
		ZEPHIR_SINIT_NVAR(_9);
		ZVAL_DOUBLE(&_9, (zephir_get_numberval(_44) * 1.6));
		ZEPHIR_CALL_FUNCTION(NULL, "imagettftext", &_49, _38, _40, _42, &_6, &_9, _45, _47, _48);
		zephir_check_call_status();
		i++;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("seKey"), PH_NOISY | PH_READONLY, "winer/verify.zep", 122 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&key, this_ptr, "authcode", &_50, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_10);
	ZEPHIR_INIT_NVAR(_11);
	zephir_fast_join_str(_11, SL(""), code TSRMLS_CC);
	zephir_fast_strtoupper(_10, _11);
	ZEPHIR_CALL_METHOD(&code, this_ptr, "authcode", &_50, _10);
	zephir_check_call_status();
	zephir_array_update_string(&secode, SL("verify_code"), &code, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_51);
	zephir_time(_51);
	zephir_array_update_string(&secode, SL("verify_time"), &_51, PH_COPY | PH_SEPARATE);
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_52);
	ZEPHIR_CONCAT_VV(_52, key, id);
	_53 = zephir_maybe_separate_zval(&_SESSION);
	zephir_array_update_zval(&_SESSION, _52, &secode, PH_COPY | PH_SEPARATE);
	if (_53) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SESSION", _SESSION);
	}
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "Cache-Control: private, max-age=0, no-store, no-cache, must-revalidate", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_54, &_6);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "Cache-Control: post-check=0, pre-check=0", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_54, &_6, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "Pragma: no-cache", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_54, &_6);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_STRING(&_6, "content-type: image/png", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_54, &_6);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagepng", NULL, _4);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, _7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Winer_Verify, _writeCurve) {

	zephir_fcall_cache_entry *_35 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, i, _25;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_24 = NULL, *_27 = NULL;
	double w;
	zval *px = NULL, *py = NULL, *a = NULL, *b = NULL, *f = NULL, *t = NULL, *px1 = NULL, *px2 = NULL, *_0, *_1, _2 = zval_used_for_init, _3 = zval_used_for_init, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20, _21 = zval_used_for_init, _22 = zval_used_for_init, *_23 = NULL, *_26 = NULL, *_28, *_29, *_30, *_31, *_32, *_33, _34 = zval_used_for_init, *_36, *_37, *_38, *_39, *_40, *_41, *_42, _43 = zval_used_for_init, *_44, *_45, *_46, *_47, *_48, *_49, _50 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(px);
	ZVAL_LONG(px, 0);
	ZEPHIR_INIT_VAR(py);
	ZVAL_LONG(py, 0);

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, _0, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 164 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_DOUBLE(&_3, zephir_safe_div_zval_long(_1, 2 TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&a, "mt_rand", &_4, &_2, &_3);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_6, _5, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 165 TSRMLS_CC);
	zephir_negate(_6 TSRMLS_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_8, _7, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 165 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_DOUBLE(&_2, zephir_safe_div_zval_long(_6, 4 TSRMLS_CC));
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_DOUBLE(&_3, zephir_safe_div_zval_long(_8, 4 TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&b, "mt_rand", &_4, &_2, &_3);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_10, _9, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 166 TSRMLS_CC);
	zephir_negate(_10 TSRMLS_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_12, _11, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 166 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_DOUBLE(&_2, zephir_safe_div_zval_long(_10, 4 TSRMLS_CC));
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_DOUBLE(&_3, zephir_safe_div_zval_long(_12, 4 TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&f, "mt_rand", &_4, &_2, &_3);
	zephir_check_call_status();
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_14, _13, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 167 TSRMLS_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_16, _15, SL("imageW"), PH_NOISY | PH_READONLY, "winer/verify.zep", 167 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, (zephir_get_numberval(_16) * 2));
	ZEPHIR_CALL_FUNCTION(&t, "mt_rand", &_4, _14, &_2);
	zephir_check_call_status();
	w = zephir_safe_div_double_zval((((double) 2 * 3.1415926535898)), t TSRMLS_CC);
	ZEPHIR_INIT_VAR(px1);
	ZVAL_LONG(px1, 0);
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_18, _17, SL("imageW"), PH_NOISY | PH_READONLY, "winer/verify.zep", 171 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_DOUBLE(&_2, zephir_safe_div_zval_long(_18, 2 TSRMLS_CC));
	_19 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_20, _19, SL("imageW"), PH_NOISY | PH_READONLY, "winer/verify.zep", 171 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_DOUBLE(&_3, (zephir_get_numberval(_20) * 0.8));
	ZEPHIR_SINIT_VAR(_21);
	ZVAL_LONG(&_21, zephir_get_intval(&_2));
	ZEPHIR_SINIT_VAR(_22);
	ZVAL_LONG(&_22, zephir_get_intval(&_3));
	ZEPHIR_CALL_FUNCTION(&_23, "mt_rand", &_4, &_21, &_22);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&px2, "floatval", &_24, _23);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(px, px2);
	while (1) {
		if (!(ZEPHIR_LE(px, px2))) {
			break;
		}
		_25 = (zephir_get_numberval(px) + 1);
		ZEPHIR_INIT_NVAR(px);
		ZVAL_LONG(px, _25);
		if (w != 0) {
			ZEPHIR_SINIT_NVAR(_21);
			ZVAL_LONG(&_21, ((w * zephir_get_numberval(px)) + zephir_get_numberval(f)));
			ZEPHIR_CALL_FUNCTION(&_26, "sin", &_27, &_21);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_21);
			mul_function(&_21, a, _26 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_22);
			zephir_add_function_ex(&_22, &_21, b TSRMLS_CC);
			_28 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_29, _28, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 178 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_21);
			ZVAL_DOUBLE(&_21, (zephir_get_numberval(&_22) + zephir_safe_div_zval_long(_29, 2 TSRMLS_CC)));
			ZEPHIR_CALL_FUNCTION(&py, "floatval", &_24, &_21);
			zephir_check_call_status();
			_30 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_31, _30, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 179 TSRMLS_CC);
			i = (int) zephir_safe_div_zval_long(_31, 5 TSRMLS_CC);
			while (1) {
				if (!(i > 0)) {
					break;
				}
				_32 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_33 = zephir_fetch_nproperty_this(this_ptr, SL("_color"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_21);
				ZVAL_LONG(&_21, (zephir_get_numberval(px) + i));
				ZEPHIR_SINIT_NVAR(_34);
				ZVAL_LONG(&_34, (zephir_get_numberval(py) + i));
				ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_35, _32, &_21, &_34, _33);
				zephir_check_call_status();
				i--;
			}
		}
	}
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_29, _28, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 188 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_21);
	ZVAL_LONG(&_21, 1);
	ZEPHIR_SINIT_NVAR(_34);
	ZVAL_DOUBLE(&_34, zephir_safe_div_zval_long(_29, 2 TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&a, "mt_rand", &_4, &_21, &_34);
	zephir_check_call_status();
	_30 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_31, _30, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 189 TSRMLS_CC);
	zephir_negate(_31 TSRMLS_CC);
	_32 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_36, _32, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 189 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_21);
	ZVAL_DOUBLE(&_21, zephir_safe_div_zval_long(_31, 4 TSRMLS_CC));
	ZEPHIR_SINIT_NVAR(_34);
	ZVAL_DOUBLE(&_34, zephir_safe_div_zval_long(_36, 4 TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&f, "mt_rand", &_4, &_21, &_34);
	zephir_check_call_status();
	_33 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_37, _33, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 190 TSRMLS_CC);
	_38 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_39, _38, SL("imageW"), PH_NOISY | PH_READONLY, "winer/verify.zep", 190 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_21);
	ZVAL_LONG(&_21, (zephir_get_numberval(_39) * 2));
	ZEPHIR_CALL_FUNCTION(&t, "mt_rand", &_4, _37, &_21);
	zephir_check_call_status();
	w = zephir_safe_div_double_zval((((double) 2 * 3.1415926535898)), t TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_21);
	ZVAL_LONG(&_21, ((w * zephir_get_numberval(px)) + zephir_get_numberval(f)));
	ZEPHIR_CALL_FUNCTION(&_26, "sin", &_27, &_21);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_21);
	mul_function(&_21, a, _26 TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_34);
	sub_function(&_34, py, &_21 TSRMLS_CC);
	_40 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_41, _40, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 192 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(b);
	ZVAL_DOUBLE(b, (zephir_get_numberval(&_34) - zephir_safe_div_zval_long(_41, 2 TSRMLS_CC)));
	ZEPHIR_CPY_WRT(px1, px2);
	_42 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_NVAR(px2);
	zephir_array_fetch_string(&px2, _42, SL("imageW"), PH_NOISY, "winer/verify.zep", 194 TSRMLS_CC);
	ZEPHIR_CPY_WRT(px, px1);
	while (1) {
		if (!(ZEPHIR_LE(px, px2))) {
			break;
		}
		_25 = (zephir_get_numberval(px) + 1);
		ZEPHIR_INIT_NVAR(px);
		ZVAL_LONG(px, _25);
		if (w != 0) {
			ZEPHIR_SINIT_NVAR(_21);
			ZVAL_LONG(&_21, ((w * zephir_get_numberval(px)) + zephir_get_numberval(f)));
			ZEPHIR_CALL_FUNCTION(&_26, "sin", &_27, &_21);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_21);
			mul_function(&_21, a, _26 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_43);
			zephir_add_function_ex(&_43, &_21, b TSRMLS_CC);
			_44 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_45, _44, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 200 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(py);
			ZVAL_DOUBLE(py, (zephir_get_numberval(&_43) + zephir_safe_div_zval_long(_45, 2 TSRMLS_CC)));
			_46 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
			zephir_array_fetch_string(&_47, _46, SL("fontSize"), PH_NOISY | PH_READONLY, "winer/verify.zep", 201 TSRMLS_CC);
			i = (int) zephir_safe_div_zval_long(_47, 5 TSRMLS_CC);
			while (1) {
				if (!(i > 0)) {
					break;
				}
				_48 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
				_49 = zephir_fetch_nproperty_this(this_ptr, SL("_color"), PH_NOISY_CC);
				ZEPHIR_SINIT_NVAR(_21);
				ZVAL_LONG(&_21, (zephir_get_numberval(px) + i));
				ZEPHIR_SINIT_NVAR(_50);
				ZVAL_LONG(&_50, (zephir_get_numberval(py) + i));
				ZEPHIR_CALL_FUNCTION(NULL, "imagesetpixel", &_35, _48, &_21, &_50, _49);
				zephir_check_call_status();
				i--;
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 绘制背景图片
 * 注：如果验证码输出图片比较大，将占用比较多的系统资源
 * @param string bgPath 验证背景图片路径。
 */
PHP_METHOD(Winer_Verify, _background) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *bgPath_param = NULL, *data = NULL, *width, *height, *bgImage = NULL, *_1, *_2, *_3, *_4, *_5, _6, _7, _8, _9;
	zval *bgPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &bgPath_param);

	if (!bgPath_param) {
		ZEPHIR_INIT_VAR(bgPath);
		ZVAL_STRING(bgPath, "", 1);
	} else {
		zephir_get_strval(bgPath, bgPath_param);
	}


	ZEPHIR_CALL_FUNCTION(&data, "getimagesize", &_0, bgPath);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(width);
	zephir_array_fetch_long(&width, data, 0, PH_NOISY, "winer/verify.zep", 220 TSRMLS_CC);
	ZEPHIR_OBS_VAR(height);
	zephir_array_fetch_long(&height, data, 1, PH_NOISY, "winer/verify.zep", 221 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&bgImage, "imagecreatefromjpeg", NULL, bgPath);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_image"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_3, _2, SL("imageW"), PH_NOISY | PH_READONLY, "winer/verify.zep", 225 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, _4, SL("imageH"), PH_NOISY | PH_READONLY, "winer/verify.zep", 225 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "imagecopyresampled", NULL, _1, bgImage, &_6, &_7, &_8, &_9, _3, _5, width, height);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "imagedestroy", NULL, bgImage);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/* 加密验证码 */
PHP_METHOD(Winer_Verify, authcode) {

	zval *str = NULL, *key, *_0, *_1, *_2, _3, _4, *_5, _6, _7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);

	ZEPHIR_SEPARATE_PARAM(str);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("seKey"), PH_NOISY | PH_READONLY, "winer/verify.zep", 232 TSRMLS_CC);
	zephir_md5(_0, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 5);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 8);
	ZEPHIR_INIT_VAR(key);
	zephir_substr(key, _0, 5 , 8 , 0);
	ZEPHIR_INIT_VAR(_5);
	zephir_md5(_5, str);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 8);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 10);
	ZEPHIR_INIT_NVAR(str);
	zephir_substr(str, _5, 8 , 10 , 0);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VV(_8, key, str);
	zephir_md5(return_value, _8);
	RETURN_MM();

}

