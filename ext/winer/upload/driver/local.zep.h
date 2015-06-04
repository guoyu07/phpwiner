
extern zend_class_entry *winer_upload_driver_local_ce;

ZEPHIR_INIT_CLASS(Winer_Upload_Driver_Local);

PHP_METHOD(Winer_Upload_Driver_Local, __construct);
PHP_METHOD(Winer_Upload_Driver_Local, checkRootPath);
PHP_METHOD(Winer_Upload_Driver_Local, checkSavePath);
PHP_METHOD(Winer_Upload_Driver_Local, save);
PHP_METHOD(Winer_Upload_Driver_Local, mkdir);
PHP_METHOD(Winer_Upload_Driver_Local, getError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_driver_local___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_driver_local_checkrootpath, 0, 0, 1)
	ZEND_ARG_INFO(0, rootpath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_driver_local_checksavepath, 0, 0, 1)
	ZEND_ARG_INFO(0, savepath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_driver_local_save, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_upload_driver_local_mkdir, 0, 0, 1)
	ZEND_ARG_INFO(0, savepath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(winer_upload_driver_local_method_entry) {
	PHP_ME(Winer_Upload_Driver_Local, __construct, arginfo_winer_upload_driver_local___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Winer_Upload_Driver_Local, checkRootPath, arginfo_winer_upload_driver_local_checkrootpath, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Upload_Driver_Local, checkSavePath, arginfo_winer_upload_driver_local_checksavepath, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Upload_Driver_Local, save, arginfo_winer_upload_driver_local_save, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Upload_Driver_Local, mkdir, arginfo_winer_upload_driver_local_mkdir, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Upload_Driver_Local, getError, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
