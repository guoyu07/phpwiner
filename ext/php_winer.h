
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_WINER_H
#define PHP_WINER_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_WINER_NAME        "winer"
#define PHP_WINER_VERSION     "0.0.1"
#define PHP_WINER_EXTNAME     "winer"
#define PHP_WINER_AUTHOR      ""
#define PHP_WINER_ZEPVERSION  "0.6.1a"
#define PHP_WINER_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(winer)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(winer)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(winer)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(winer_globals_id, zend_winer_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (winer_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_winer_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(winer_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(winer_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def winer_globals
#define zend_zephir_globals_def zend_winer_globals

extern zend_module_entry winer_module_entry;
#define phpext_winer_ptr &winer_module_entry

#endif
