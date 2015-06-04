
extern zend_class_entry *winer_image_ce;

ZEPHIR_INIT_CLASS(Winer_Image);

PHP_METHOD(Winer_Image, __construct);
PHP_METHOD(Winer_Image, open);
PHP_METHOD(Winer_Image, save);
PHP_METHOD(Winer_Image, width);
PHP_METHOD(Winer_Image, height);
PHP_METHOD(Winer_Image, type);
PHP_METHOD(Winer_Image, mime);
PHP_METHOD(Winer_Image, size);
PHP_METHOD(Winer_Image, crop);
PHP_METHOD(Winer_Image, thumb);
PHP_METHOD(Winer_Image, water);
PHP_METHOD(Winer_Image, text);

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, t)
	ZEND_ARG_INFO(0, imgname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_open, 0, 0, 1)
	ZEND_ARG_INFO(0, imgname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_save, 0, 0, 1)
	ZEND_ARG_INFO(0, imgname)
	ZEND_ARG_INFO(0, t)
	ZEND_ARG_INFO(0, quality)
	ZEND_ARG_INFO(0, interlace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_thumb, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, t)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_water, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, locate)
	ZEND_ARG_INFO(0, alpha)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_image_text, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, font)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, locate)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, angle)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(winer_image_method_entry) {
	PHP_ME(Winer_Image, __construct, arginfo_winer_image___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Winer_Image, open, arginfo_winer_image_open, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, save, arginfo_winer_image_save, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, width, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, height, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, type, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, mime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, size, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, crop, arginfo_winer_image_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, thumb, arginfo_winer_image_thumb, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, water, arginfo_winer_image_water, ZEND_ACC_PUBLIC)
	PHP_ME(Winer_Image, text, arginfo_winer_image_text, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
