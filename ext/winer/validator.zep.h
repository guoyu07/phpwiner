
extern zend_class_entry *winer_validator_ce;

ZEPHIR_INIT_CLASS(Winer_Validator);

PHP_METHOD(Winer_Validator, is_username);
PHP_METHOD(Winer_Validator, is_password);
PHP_METHOD(Winer_Validator, is_qq);
PHP_METHOD(Winer_Validator, is_mobilephone);
PHP_METHOD(Winer_Validator, is_telphone);
PHP_METHOD(Winer_Validator, is_zipcode);
PHP_METHOD(Winer_Validator, alpha_between);
PHP_METHOD(Winer_Validator, number_between);
PHP_METHOD(Winer_Validator, is_chinese);
PHP_METHOD(Winer_Validator, is_alpha_dash);
PHP_METHOD(Winer_Validator, is_alpha_number);
PHP_METHOD(Winer_Validator, is_alpha);
PHP_METHOD(Winer_Validator, is_date_format);
PHP_METHOD(Winer_Validator, is_integer);
PHP_METHOD(Winer_Validator, is_ip);
PHP_METHOD(Winer_Validator, is_url);
PHP_METHOD(Winer_Validator, is_email);
PHP_METHOD(Winer_Validator, is_require);
PHP_METHOD(Winer_Validator, is_utf8);
PHP_METHOD(Winer_Validator, len);

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_username, 0, 0, 3)
	ZEND_ARG_INFO(0, username)
	ZEND_ARG_INFO(0, min_len)
	ZEND_ARG_INFO(0, max_len)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_password, 0, 0, 3)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, min_len)
	ZEND_ARG_INFO(0, max_len)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_qq, 0, 0, 1)
	ZEND_ARG_INFO(0, qq)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_mobilephone, 0, 0, 1)
	ZEND_ARG_INFO(0, mobilephone)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_telphone, 0, 0, 1)
	ZEND_ARG_INFO(0, telphone)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_zipcode, 0, 0, 1)
	ZEND_ARG_INFO(0, zipcode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_alpha_between, 0, 0, 3)
	ZEND_ARG_INFO(0, alpha)
	ZEND_ARG_INFO(0, start_alpha)
	ZEND_ARG_INFO(0, end_alpha)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_number_between, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, start_value)
	ZEND_ARG_INFO(0, end_value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_chinese, 0, 0, 1)
	ZEND_ARG_INFO(0, ch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_alpha_dash, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_alpha_number, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_alpha, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_date_format, 0, 0, 2)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_integer, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_ip, 0, 0, 1)
	ZEND_ARG_INFO(0, ip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_url, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_email, 0, 0, 1)
	ZEND_ARG_INFO(0, email)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_require, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_is_utf8, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_validator_len, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, min)
	ZEND_ARG_INFO(0, max)
	ZEND_ARG_INFO(0, is_utf8)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(winer_validator_method_entry) {
	PHP_ME(Winer_Validator, is_username, arginfo_winer_validator_is_username, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_password, arginfo_winer_validator_is_password, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_qq, arginfo_winer_validator_is_qq, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_mobilephone, arginfo_winer_validator_is_mobilephone, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_telphone, arginfo_winer_validator_is_telphone, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_zipcode, arginfo_winer_validator_is_zipcode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, alpha_between, arginfo_winer_validator_alpha_between, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, number_between, arginfo_winer_validator_number_between, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_chinese, arginfo_winer_validator_is_chinese, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_alpha_dash, arginfo_winer_validator_is_alpha_dash, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_alpha_number, arginfo_winer_validator_is_alpha_number, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_alpha, arginfo_winer_validator_is_alpha, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_date_format, arginfo_winer_validator_is_date_format, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_integer, arginfo_winer_validator_is_integer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_ip, arginfo_winer_validator_is_ip, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_url, arginfo_winer_validator_is_url, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_email, arginfo_winer_validator_is_email, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_require, arginfo_winer_validator_is_require, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, is_utf8, arginfo_winer_validator_is_utf8, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Validator, len, arginfo_winer_validator_len, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
