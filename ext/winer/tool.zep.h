
extern zend_class_entry *winer_tool_ce;

ZEPHIR_INIT_CLASS(Winer_Tool);

PHP_METHOD(Winer_Tool, safe_replace);
PHP_METHOD(Winer_Tool, new_addslashes);
PHP_METHOD(Winer_Tool, new_stripslashes);
PHP_METHOD(Winer_Tool, arrtyToTree);
PHP_METHOD(Winer_Tool, pc_file_get_contents);
PHP_METHOD(Winer_Tool, dir_iconv);
PHP_METHOD(Winer_Tool, dir_list);
PHP_METHOD(Winer_Tool, dir_path);
PHP_METHOD(Winer_Tool, dir_delete);
PHP_METHOD(Winer_Tool, fileext);
PHP_METHOD(Winer_Tool, sizecount);
PHP_METHOD(Winer_Tool, create_randomstr);
PHP_METHOD(Winer_Tool, random);

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_safe_replace, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_new_addslashes, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_new_stripslashes, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_arrtytotree, 0, 0, 4)
	ZEND_ARG_INFO(0, sourceArr)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, parentKey)
	ZEND_ARG_INFO(0, childrenKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_pc_file_get_contents, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_dir_iconv, 0, 0, 3)
	ZEND_ARG_INFO(0, in_charset)
	ZEND_ARG_INFO(0, out_charset)
	ZEND_ARG_INFO(0, dir_path)
	ZEND_ARG_INFO(0, fileexts)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_dir_list, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, exts)
	ZEND_ARG_INFO(0, list)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_dir_path, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_dir_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_fileext, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_sizecount, 0, 0, 1)
	ZEND_ARG_INFO(0, filesize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_create_randomstr, 0, 0, 0)
	ZEND_ARG_INFO(0, lenth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_winer_tool_random, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_ARRAY_INFO(0, chars, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(winer_tool_method_entry) {
	PHP_ME(Winer_Tool, safe_replace, arginfo_winer_tool_safe_replace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, new_addslashes, arginfo_winer_tool_new_addslashes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, new_stripslashes, arginfo_winer_tool_new_stripslashes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, arrtyToTree, arginfo_winer_tool_arrtytotree, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, pc_file_get_contents, arginfo_winer_tool_pc_file_get_contents, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, dir_iconv, arginfo_winer_tool_dir_iconv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, dir_list, arginfo_winer_tool_dir_list, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, dir_path, arginfo_winer_tool_dir_path, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, dir_delete, arginfo_winer_tool_dir_delete, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, fileext, arginfo_winer_tool_fileext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, sizecount, arginfo_winer_tool_sizecount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, create_randomstr, arginfo_winer_tool_create_randomstr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Winer_Tool, random, arginfo_winer_tool_random, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
