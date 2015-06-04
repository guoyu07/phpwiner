
extern zend_class_entry *winer_image_driver_imagick_ce;

ZEPHIR_INIT_CLASS(Winer_Image_Driver_Imagick);

PHP_METHOD(Winer_Image_Driver_Imagick, __construct);
PHP_METHOD(Winer_Image_Driver_Imagick, open);
PHP_METHOD(Winer_Image_Driver_Imagick, save);
PHP_METHOD(Winer_Image_Driver_Imagick, width);
PHP_METHOD(Winer_Image_Driver_Imagick, height);
PHP_METHOD(Winer_Image_Driver_Imagick, type);
PHP_METHOD(Winer_Image_Driver_Imagick, mime);
PHP_METHOD(Winer_Image_Driver_Imagick, size);
PHP_METHOD(Winer_Image_Driver_Imagick, crop);
PHP_METHOD(Winer_Image_Driver_Imagick, _crop);
PHP_METHOD(Winer_Image_Driver_Imagick, thumb);
PHP_METHOD(Winer_Image_Driver_Imagick, inside_fill);
PHP_METHOD(Winer_Image_Driver_Imagick, water);
PHP_METHOD(Winer_Image_Driver_Imagick, text);
PHP_METHOD(Winer_Image_Driver_Imagick, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, imgname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick_open, 0, 0, 1)
	ZEND_ARG_INFO(0, imgname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick_save, 0, 0, 1)
	ZEND_ARG_INFO(0, imgname)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, quality)
	ZEND_ARG_INFO(0, interlace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick__crop, 0, 0, 6)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, img)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick_thumb, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick_inside_fill, 0, 0, 5)
	ZEND_ARG_INFO(0, newimg)
	ZEND_ARG_INFO(0, posx)
	ZEND_ARG_INFO(0, posy)
	ZEND_ARG_INFO(0, neww)
	ZEND_ARG_INFO(0, newh)
	ZEND_ARG_INFO(0, img)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick_water, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, locate)
	ZEND_ARG_INFO(0, alpha)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_driver_imagick_text, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, font)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, locate)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, angle)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(winer_image_driver_imagick_method_entry) {
	PHP_ME(Winer_Image_Driver_Imagick, __construct, arginfo_winer_image_driver_imagick___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Winer_Image_Driver_Imagick, open, arginfo_winer_image_driver_imagick_open, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, save, arginfo_winer_image_driver_imagick_save, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, width, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, height, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, type, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, mime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, size, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, crop, arginfo_winer_image_driver_imagick_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, _crop, arginfo_winer_image_driver_imagick__crop, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Image_Driver_Imagick, thumb, arginfo_winer_image_driver_imagick_thumb, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, inside_fill, arginfo_winer_image_driver_imagick_inside_fill, ZEND_ACC_PRIVATE)
	PHP_ME(Winer_Image_Driver_Imagick, water, arginfo_winer_image_driver_imagick_water, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, text, arginfo_winer_image_driver_imagick_text, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image_Driver_Imagick, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
  PHP_FE_END
};
