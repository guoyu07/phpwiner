
extern zend_class_entry *winer_image_driver_gd_ce;

ZEPHIR_INIT_CLASS(Winer_Image_Driver_Gd);

PHP_METHOD(Winer_Image_Driver_Gd, __construct);
PHP_METHOD(Winer_Image_Driver_Gd, open);
PHP_METHOD(Winer_Image_Driver_Gd, save);
PHP_METHOD(Winer_Image_Driver_Gd, width);
PHP_METHOD(Winer_Image_Driver_Gd, height);
PHP_METHOD(Winer_Image_Driver_Gd, type);
PHP_METHOD(Winer_Image_Driver_Gd, mime);
PHP_METHOD(Winer_Image_Driver_Gd, size);
PHP_METHOD(Winer_Image_Driver_Gd, crop);
PHP_METHOD(Winer_Image_Driver_Gd, thumb);
PHP_METHOD(Winer_Image_Driver_Gd, water);
PHP_METHOD(Winer_Image_Driver_Gd, text);
PHP_METHOD(Winer_Image_Driver_Gd, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_gd___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, imgname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_gd_open, 0, 0, 1)
	ZEND_ARG_INFO(0, imgname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_gd_save, 0, 0, 1)
	ZEND_ARG_INFO(0, imgname)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, quality)
	ZEND_ARG_INFO(0, interlace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_gd_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_gd_thumb, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_gd_water, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, locate)
	ZEND_ARG_INFO(0, alpha)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_gd_text, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, font)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, locate)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, angle)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(winer_image_driver_gd_method_entry) {
	PHP_ME(Winer_Image_Driver_Gd, __construct, arginfo_winer_image_driver_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Winer_Image_Driver_Gd, open, arginfo_winer_image_driver_gd_open, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, save, arginfo_winer_image_driver_gd_save, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, width, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, height, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, type, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, mime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, size, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, crop, arginfo_winer_image_driver_gd_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, thumb, arginfo_winer_image_driver_gd_thumb, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, water, arginfo_winer_image_driver_gd_water, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, text, arginfo_winer_image_driver_gd_text, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Gd, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
  PHP_FE_END
};
