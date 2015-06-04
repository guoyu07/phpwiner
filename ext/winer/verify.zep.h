
extern zend_class_entry *winer_verify_ce;

ZEPHIR_INIT_CLASS(Winer_Verify);

PHP_METHOD(Winer_Verify, __construct);
PHP_METHOD(Winer_Verify, check);
PHP_METHOD(Winer_Verify, entry);
PHP_METHOD(Winer_Verify, _writeCurve);
PHP_METHOD(Winer_Verify, _background);
PHP_METHOD(Winer_Verify, authcode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_verify___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_verify_check, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_verify_entry, 0, 0, 0)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, ttfPath)
	ZEND_ARG_INFO(0, bgPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_verify__background, 0, 0, 0)
	ZEND_ARG_INFO(0, bgPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_verify_authcode, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(winer_verify_method_entry) {
	PHP_ME(Winer_Verify, __construct, arginfo_winer_verify___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Winer_Verify, check, arginfo_winer_verify_check, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Verify, entry, arginfo_winer_verify_entry, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Verify, _writeCurve, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Verify, _background, arginfo_winer_verify__background, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Verify, authcode, arginfo_winer_verify_authcode, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
