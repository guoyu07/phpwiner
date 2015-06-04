
extern zend_class_entry *winer_upload_ce;

ZEPHIR_INIT_CLASS(Winer_Upload);

PHP_METHOD(Winer_Upload, __construct);
PHP_METHOD(Winer_Upload, __set);
PHP_METHOD(Winer_Upload, getError);
PHP_METHOD(Winer_Upload, uploadOne);
PHP_METHOD(Winer_Upload, upload);
PHP_METHOD(Winer_Upload, dealFiles);
PHP_METHOD(Winer_Upload, setDriver);
PHP_METHOD(Winer_Upload, check);
PHP_METHOD(Winer_Upload, error);
PHP_METHOD(Winer_Upload, checkSize);
PHP_METHOD(Winer_Upload, checkMime);
PHP_METHOD(Winer_Upload, checkExt);
PHP_METHOD(Winer_Upload, getSaveName);
PHP_METHOD(Winer_Upload, getSubPath);
PHP_METHOD(Winer_Upload, getName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 1)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_ARRAY_INFO(0, driverConfig, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_uploadone, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_upload, 0, 0, 0)
	ZEND_ARG_INFO(0, files)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_dealfiles, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_setdriver, 0, 0, 0)
	ZEND_ARG_INFO(0, driver)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_check, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_error, 0, 0, 1)
	ZEND_ARG_INFO(0, errorNo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_checksize, 0, 0, 1)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_checkmime, 0, 0, 1)
	ZEND_ARG_INFO(0, mime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_checkext, 0, 0, 1)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_getsavename, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_getsubpath, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_getname, 0, 0, 2)
	ZEND_ARG_INFO(0, rule)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(winer_upload_method_entry) {
	PHP_ME(Winer_Upload, __construct, arginfo_winer_upload___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Winer_Upload, __set, arginfo_winer_upload___set, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Upload, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Upload, uploadOne, arginfo_winer_upload_uploadone, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Upload, upload, arginfo_winer_upload_upload, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Upload, dealFiles, arginfo_winer_upload_dealfiles, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, setDriver, arginfo_winer_upload_setdriver, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, check, arginfo_winer_upload_check, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, error, arginfo_winer_upload_error, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, checkSize, arginfo_winer_upload_checksize, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, checkMime, arginfo_winer_upload_checkmime, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, checkExt, arginfo_winer_upload_checkext, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, getSaveName, arginfo_winer_upload_getsavename, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, getSubPath, arginfo_winer_upload_getsubpath, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Upload, getName, arginfo_winer_upload_getname, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
