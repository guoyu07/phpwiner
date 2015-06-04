
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Winer_Validator) {

	ZEPHIR_REGISTER_CLASS(Winer, Validator, winer, validator, winer_validator_method_entry, 0);

	return SUCCESS;

}

/**
 * 判断是否为合法的用户名。
 * @param string username
 * @param uint min_len 最小长度。包含。
 * @param uint max_len 最大长度。包含。
 * @param string mode 用户名模式：digit、alpha、digit_alpha、chinese、digit_alpha_chinese、mix
 *			digit：数字
 *			aplha：字母
 *			digit_alpha：数字和字母
 *			chinese：中文
 *			digit_alpha_chinese：数字字母中文
 *			mix：混合型：数字字母中文下划线破折号
 * @return bool
 */
PHP_METHOD(Winer_Validator, is_username) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL;
	zend_bool ok;
	unsigned int min_len, max_len;
	zval *username_param = NULL, *min_len_param = NULL, *max_len_param = NULL, *mode_param = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL;
	zval *username = NULL, *mode = NULL, *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &username_param, &min_len_param, &max_len_param, &mode_param);

	zephir_get_strval(username, username_param);
	min_len = zephir_get_intval(min_len_param);
	max_len = zephir_get_intval(max_len_param);
	if (!mode_param) {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_STRING(mode, "mix", 1);
	} else {
		zephir_get_strval(mode, mode_param);
	}


	do {
		if (ZEPHIR_IS_STRING(mode, "digit")) {
			ZEPHIR_SINIT_VAR(_0);
			ZVAL_LONG(&_0, min_len);
			ZEPHIR_CALL_FUNCTION(&_1, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, max_len);
			ZEPHIR_CALL_FUNCTION(&_3, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_SVSVS(_4, "/^\\d{", _1, ",", _3, "}$/");
			zephir_get_strval(pattern, _4);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, pattern, username);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 1);
			} else {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 0);
			}
			ok = zephir_is_true(_5);
			break;
		}
		if (ZEPHIR_IS_STRING(mode, "alpha")) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, min_len);
			ZEPHIR_CALL_FUNCTION(&_1, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, max_len);
			ZEPHIR_CALL_FUNCTION(&_3, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSVS(_4, "/^([a-zA-Z]){", _1, ",", _3, "}$/");
			zephir_get_strval(pattern, _4);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, pattern, username);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 1);
			} else {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 0);
			}
			ok = zephir_is_true(_5);
			break;
		}
		if (ZEPHIR_IS_STRING(mode, "digit_alpha")) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, min_len);
			ZEPHIR_CALL_FUNCTION(&_1, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, max_len);
			ZEPHIR_CALL_FUNCTION(&_3, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSVS(_4, "/^([a-z0-9_-]){", _1, ",", _3, "}$/");
			zephir_get_strval(pattern, _4);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, pattern, username);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 1);
			} else {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 0);
			}
			ok = zephir_is_true(_5);
			break;
		}
		if (ZEPHIR_IS_STRING(mode, "chinese")) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, min_len);
			ZEPHIR_CALL_FUNCTION(&_1, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, max_len);
			ZEPHIR_CALL_FUNCTION(&_3, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSVS(_4, "/^[\\x7f-\\xff]{", _1, ",", _3, "}$/");
			zephir_get_strval(pattern, _4);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, pattern, username);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 1);
			} else {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 0);
			}
			ok = zephir_is_true(_5);
			break;
		}
		if (ZEPHIR_IS_STRING(mode, "digit_alpha_chinese")) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, min_len);
			ZEPHIR_CALL_FUNCTION(&_1, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, max_len);
			ZEPHIR_CALL_FUNCTION(&_3, "strval", &_2, &_0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_SVSVS(_4, "/^[\\x7f-\\xff|0-9a-zA-Z]{", _1, ",", _3, "}$/");
			zephir_get_strval(pattern, _4);
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, pattern, username);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 1);
			} else {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_BOOL(_5, 0);
			}
			ok = zephir_is_true(_5);
			break;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, min_len);
		ZEPHIR_CALL_FUNCTION(&_1, "strval", &_2, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, max_len);
		ZEPHIR_CALL_FUNCTION(&_3, "strval", &_2, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVSVS(_4, "/^[\\x7f-\\xff|0-9a-zA-Z-_]{", _1, ",", _3, "}$/");
		zephir_get_strval(pattern, _4);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, pattern, username);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_BOOL(_5, 1);
		} else {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_BOOL(_5, 0);
		}
		ok = zephir_is_true(_5);
		break;
	} while(0);

	RETURN_MM_BOOL(ok);

}

/**
 * 判断是否为合法的密码。
 * @param string password
 * @param uint min_len 最小长度。包含。
 * @param uint max_len 最大长度。包含。
 * @param string mode 用户名模式：digit_alpha、mix
 *			digit_alpha：数字和字母
 *			mix：混合型：数字字母下划线破折号
 * @return bool
 */
PHP_METHOD(Winer_Validator, is_password) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_7 = NULL;
	unsigned int min_len, max_len;
	zval *password_param = NULL, *min_len_param = NULL, *max_len_param = NULL, *mode_param = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL;
	zval *password = NULL, *mode = NULL, *pattern = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &password_param, &min_len_param, &max_len_param, &mode_param);

	zephir_get_strval(password, password_param);
	min_len = zephir_get_intval(min_len_param);
	max_len = zephir_get_intval(max_len_param);
	if (!mode_param) {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_STRING(mode, "mix", 1);
	} else {
		zephir_get_strval(mode, mode_param);
	}


	if (ZEPHIR_IS_STRING(mode, "digit_alpha")) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, min_len);
		ZEPHIR_CALL_FUNCTION(&_1, "strval", &_2, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, max_len);
		ZEPHIR_CALL_FUNCTION(&_3, "strval", &_2, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVSVS(_4, "/^([a-z0-9]){", _1, ",", _3, "}$/");
		zephir_get_strval(pattern, _4);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, pattern, password);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZVAL_BOOL(_5, 1);
		} else {
			ZVAL_BOOL(_5, 0);
		}
		RETURN_CCTOR(_5);
	} else if (ZEPHIR_IS_STRING(mode, "mix")) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, min_len);
		ZEPHIR_CALL_FUNCTION(&_1, "strval", &_2, &_0);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, max_len);
		ZEPHIR_CALL_FUNCTION(&_3, "strval", &_2, &_0);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVSVS(_4, "/^[0-9a-zA-Z-_]{", _1, ",", _3, "}$/");
		zephir_get_strval(pattern, _4);
		ZEPHIR_INIT_NVAR(_5);
		ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, pattern, password);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZVAL_BOOL(_5, 1);
		} else {
			ZVAL_BOOL(_5, 0);
		}
		RETURN_CCTOR(_5);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 判断是否为QQ号码。
 * @param string qq
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_qq) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *qq_param = NULL, *_0, *_1, *_2 = NULL;
	zval *qq = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &qq_param);

	zephir_get_strval(qq, qq_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/^[1-9]\\d{4,12}$/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, qq);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 判断是否为手机号码。
 * @param string mobilephone
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_mobilephone) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *mobilephone_param = NULL, *_0, *_1, *_2 = NULL;
	zval *mobilephone = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mobilephone_param);

	zephir_get_strval(mobilephone, mobilephone_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/^13[\\d]{9}|14^[0-9]\\d{8}|^15[0-9]\\d{8}|^18[0-9]\\d{8}$/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, mobilephone);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 判断是否为座机号码。
 * @param string telphone
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_telphone) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *telphone_param = NULL, *_0, *_1, *_2 = NULL;
	zval *telphone = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &telphone_param);

	zephir_get_strval(telphone, telphone_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/^((\\(\\d{2,3}\\))|(\\d{3}\\-))?(\\(0\\d{2,3}\\)|0\\d{2,3}-)?[1-9]\\d{6,7}(\\-\\d{1,4})?$/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, telphone);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 判断是否为邮政编码。
 * @param string zipcode
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_zipcode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *zipcode_param = NULL, *_0, *_1, *_2 = NULL;
	zval *zipcode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &zipcode_param);

	zephir_get_strval(zipcode, zipcode_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/^[1-9]\\d{5}$/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, zipcode);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 判断字母是否在某个区域内。用于判断某个字符只能介于[a-h](包含)之间的类似情况。
 * @param string alpha 原值。
 * @param string start_alpha 起始值。
 * @param string end_alpha 截止值。
 * @return boolean
 */
PHP_METHOD(Winer_Validator, alpha_between) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alpha_param = NULL, *start_alpha_param = NULL, *end_alpha_param = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *alpha = NULL, *start_alpha = NULL, *end_alpha = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &alpha_param, &start_alpha_param, &end_alpha_param);

	zephir_get_strval(alpha, alpha_param);
	zephir_get_strval(start_alpha, start_alpha_param);
	zephir_get_strval(end_alpha, end_alpha_param);


	ZEPHIR_CALL_SELF(&_0, "is_alpha", NULL, alpha);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_SELF(&_1, "is_alpha", NULL, start_alpha);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(_1)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_SELF(&_2, "is_alpha", NULL, end_alpha);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(_2)) {
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GE(start_alpha, end_alpha)) {
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_LT(alpha, start_alpha)) {
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GT(alpha, end_alpha)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * 判断数字是否在某个区域之间。[2, 10],包含边界值。
 * @param int value 原值。
 * @param int start_value 起始值。
 * @param int end_value 截止值。
 * @return boolean
 */
PHP_METHOD(Winer_Validator, number_between) {

	zend_bool _1, _3;
	zval *value_param = NULL, *start_value_param = NULL, *end_value_param = NULL, _0, _2, _4;
	int value, start_value, end_value;

	zephir_fetch_params(0, 3, 0, &value_param, &start_value_param, &end_value_param);

	value = zephir_get_intval(value_param);
	start_value = zephir_get_intval(start_value_param);
	end_value = zephir_get_intval(end_value_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, value);
	_1 = zephir_is_numeric(&_0) == 0;
	if (!(_1)) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, start_value);
		_1 = zephir_is_numeric(&_2) == 0;
	}
	_3 = _1;
	if (!(_3)) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_LONG(&_4, end_value);
		_3 = zephir_is_numeric(&_4) == 0;
	}
	if (_3) {
		RETURN_BOOL(0);
	}
	if (start_value >= end_value) {
		RETURN_BOOL(0);
	}
	if (value < start_value) {
		RETURN_BOOL(0);
	}
	if (value > end_value) {
		RETURN_BOOL(0);
	}
	RETURN_BOOL(1);

}

/**
 * 验证是否为中文。
 * @param string char
 * @return bool
 */
PHP_METHOD(Winer_Validator, is_chinese) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *ch_param = NULL, *_0, *_1, *_2 = NULL;
	zval *ch = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ch_param);

	zephir_get_strval(ch, ch_param);


	if (zephir_fast_strlen_ev(ch) == 0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/^[\\x7f-\\xff]+$/", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, ch);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 判断是否为字母、数字、下划线（_）、破折号（-）。
 * @param string str
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_alpha_dash) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *str_param = NULL, *_0, *_1, *_2 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/^([a-z0-9_-])+$/i", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, str);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 判断是否为字母数字。
 * @param string str
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_alpha_number) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *str_param = NULL, *_0, *_1, *_2 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/^([a-z0-9])+$/i", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, str);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 判断是否为字母。
 * @param string str
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_alpha) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *str_param = NULL, *_0, *_1, *_2 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "/^([a-z])+$/i", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, str);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 验证日期时间格式。
 * -- 1、验证value是否为format格式。
 * -- 2、只能验证格式，不能验证时间是否正确。比如：2014-22-22
 * @param string format 格式。格式如：Y-m-d 或H:i:s
 * @param string value 日期。
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_date_format) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *format_param = NULL, *value_param = NULL, *_0 = NULL;
	zval *format = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &format_param, &value_param);

	zephir_get_strval(format, format_param);
	zephir_get_strval(value, value_param);


	ZEPHIR_CALL_FUNCTION(&_0, "date_create_from_format", NULL, format, value);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_0));

}

/**
 * 判断是否为整数。
 * @param string str
 * @return boolean
 */
PHP_METHOD(Winer_Validator, is_integer) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, _0, *_1 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 257);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, str, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_1));

}

/**
 * 验证IP是否合法。
 * @param string ip
 * @return bool
 */
PHP_METHOD(Winer_Validator, is_ip) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *ip_param = NULL, _0, *_1 = NULL;
	zval *ip = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ip_param);

	zephir_get_strval(ip, ip_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 275);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, ip, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_1));

}

/**
 * 验证URL是否合法。
 * -- 合法的URL：http://www.baidu.com
 * @param string url
 * @return bool
 */
PHP_METHOD(Winer_Validator, is_url) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, _0, *_1 = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(url, url_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 273);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, url, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_1));

}

/**
 * 判断email格式是否正确。
 * @param string email
 * @return bool
 */
PHP_METHOD(Winer_Validator, is_email) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *email_param = NULL, _0, *_1 = NULL;
	zval *email = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &email_param);

	zephir_get_strval(email, email_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 274);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, email, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(_1));

}

/**
 * 是否必需。
 * @param string str
 * @return bool
 */
PHP_METHOD(Winer_Validator, is_require) {

	zval *str_param = NULL, *_0;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	if (zephir_fast_strlen_ev(str)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 判断字符串是否为utf8编码，英文和半角字符返回ture。
 * @param string string
 * @return bool
 */
PHP_METHOD(Winer_Validator, is_utf8) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *str, *_0, *_1, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "%^(?:\r\n\t\t\t\t\t[\\x09\\x0A\\x0D\\x20-\\x7E]\r\n\t\t\t\t\t| [\\xC2-\\xDF][\\x80-\\xBF]\r\n\t\t\t\t\t| \\xE0[\\xA0-\\xBF][\\x80-\\xBF]\r\n\t\t\t\t\t| [\\xE1-\\xEC\\xEE\\xEF][\\x80-\\xBF]{2}\r\n\t\t\t\t\t| \\xED[\\x80-\\x9F][\\x80-\\xBF]\r\n\t\t\t\t\t| \\xF0[\\x90-\\xBF][\\x80-\\xBF]{2}\r\n\t\t\t\t\t| [\\xF1-\\xF3][\\x80-\\xBF]{3}\r\n\t\t\t\t\t| \\xF4[\\x80-\\x8F][\\x80-\\xBF]{2}\r\n\t\t\t\t\t)*$%xs", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_2, "preg_match", &_3, _1, str);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

/**
 * 检查字符串长度。
 * @param string str 字符串。
 * @param int min 最小长度。
 * @param int max 最大长度。
 * @param bool is_utf8 是否UTF-8字符。
 * @return boolean
 */
PHP_METHOD(Winer_Validator, len) {

	zend_bool is_utf8, _1;
	int min, max, len, ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *min_param = NULL, *max_param = NULL, *is_utf8_param = NULL, *_0 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &str_param, &min_param, &max_param, &is_utf8_param);

	zephir_get_strval(str, str_param);
	if (!min_param) {
		min = 0;
	} else {
		min = zephir_get_intval(min_param);
	}
	if (!max_param) {
		max = 255;
	} else {
		max = zephir_get_intval(max_param);
	}
	if (!is_utf8_param) {
		is_utf8 = 0;
	} else {
		is_utf8 = zephir_get_boolval(is_utf8_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (is_utf8) {
		ZEPHIR_CALL_FUNCTION(&_0, "mb_strlen", NULL, str);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, zephir_fast_strlen_ev(str));
	}
	len = zephir_get_numberval(_0);
	_1 = (len >= min);
	if (_1) {
		_1 = (len <= max);
	}
	if (_1) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

