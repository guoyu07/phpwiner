
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "winer.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *winer_image_ce;
zend_class_entry *winer_image_driver_gd_ce;
zend_class_entry *winer_image_driver_imagick_ce;
zend_class_entry *winer_tool_ce;
zend_class_entry *winer_upload_ce;
zend_class_entry *winer_upload_driver_local_ce;
zend_class_entry *winer_validator_ce;
zend_class_entry *winer_verify_ce;

ZEND_DECLARE_MODULE_GLOBALS(winer)

static PHP_MINIT_FUNCTION(winer)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Winer_Image);
	ZEPHIR_INIT(Winer_Image_Driver_Gd);
	ZEPHIR_INIT(Winer_Image_Driver_Imagick);
	ZEPHIR_INIT(Winer_Tool);
	ZEPHIR_INIT(Winer_Upload);
	ZEPHIR_INIT(Winer_Upload_Driver_Local);
	ZEPHIR_INIT(Winer_Validator);
	ZEPHIR_INIT(Winer_Verify);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(winer)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_winer_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(winer)
{

	zend_winer_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(winer)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(winer)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_WINER_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_WINER_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_WINER_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_WINER_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_WINER_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(winer)
{
	php_zephir_init_globals(winer_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(winer)
{

}


zend_function_entry php_winer_functions[] = {
ZEND_FE_END

};

zend_module_entry winer_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_WINER_EXTNAME,
	php_winer_functions,
	PHP_MINIT(winer),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(winer),
#else
	NULL,
#endif
	PHP_RINIT(winer),
	PHP_RSHUTDOWN(winer),
	PHP_MINFO(winer),
	PHP_WINER_VERSION,
	ZEND_MODULE_GLOBALS(winer),
	PHP_GINIT(winer),
	PHP_GSHUTDOWN(winer),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_WINER
ZEND_GET_MODULE(winer)
#endif
