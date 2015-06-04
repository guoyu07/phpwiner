
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/concat.h"


/**
 * 工具库。
 * @author winerQin
 * @date 2015-05-06
 * @lastmodify 2015-05-06
 */
ZEPHIR_INIT_CLASS(Winer_Tool) {

	ZEPHIR_REGISTER_CLASS(Winer, Tool, winer, tool, winer_tool_method_entry, 0);

	return SUCCESS;

}

/**
 * 安全过滤函数
 * @param string str
 * @return string
 */
PHP_METHOD(Winer_Tool, safe_replace) {

	zval *str_param = NULL, *_0, _1, _2, *_3, _4, _5, *_6, _7, _8, *_9, _10, _11, *_12, _13, _14, *_15, _16, _17, *_18, _19, _20, *_21, _22, _23, *_24, _25, _26, *_27, _28, _29, *_30, _31, _32, *_33, _34, _35, *_36, _37, _38;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "%20", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "", 0);
	zephir_fast_str_replace(_0, &_1, &_2, str TSRMLS_CC);
	zephir_get_strval(str, _0);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "%27", 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "", 0);
	zephir_fast_str_replace(_3, &_4, &_5, str TSRMLS_CC);
	zephir_get_strval(str, _3);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "%2527", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "", 0);
	zephir_fast_str_replace(_6, &_7, &_8, str TSRMLS_CC);
	zephir_get_strval(str, _6);
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "*", 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_STRING(&_11, "", 0);
	zephir_fast_str_replace(_9, &_10, &_11, str TSRMLS_CC);
	zephir_get_strval(str, _9);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "\"", 0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_STRING(&_14, "&quot;", 0);
	zephir_fast_str_replace(_12, &_13, &_14, str TSRMLS_CC);
	zephir_get_strval(str, _12);
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_STRING(&_16, "\"", 0);
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_STRING(&_17, "", 0);
	zephir_fast_str_replace(_15, &_16, &_17, str TSRMLS_CC);
	zephir_get_strval(str, _15);
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_SINIT_VAR(_19);
	ZVAL_STRING(&_19, "\"", 0);
	ZEPHIR_SINIT_VAR(_20);
	ZVAL_STRING(&_20, "", 0);
	zephir_fast_str_replace(_18, &_19, &_20, str TSRMLS_CC);
	zephir_get_strval(str, _18);
	ZEPHIR_INIT_VAR(_21);
	ZEPHIR_SINIT_VAR(_22);
	ZVAL_STRING(&_22, ";", 0);
	ZEPHIR_SINIT_VAR(_23);
	ZVAL_STRING(&_23, "", 0);
	zephir_fast_str_replace(_21, &_22, &_23, str TSRMLS_CC);
	zephir_get_strval(str, _21);
	ZEPHIR_INIT_VAR(_24);
	ZEPHIR_SINIT_VAR(_25);
	ZVAL_STRING(&_25, "<", 0);
	ZEPHIR_SINIT_VAR(_26);
	ZVAL_STRING(&_26, "&lt;", 0);
	zephir_fast_str_replace(_24, &_25, &_26, str TSRMLS_CC);
	zephir_get_strval(str, _24);
	ZEPHIR_INIT_VAR(_27);
	ZEPHIR_SINIT_VAR(_28);
	ZVAL_STRING(&_28, ">", 0);
	ZEPHIR_SINIT_VAR(_29);
	ZVAL_STRING(&_29, "&gt;", 0);
	zephir_fast_str_replace(_27, &_28, &_29, str TSRMLS_CC);
	zephir_get_strval(str, _27);
	ZEPHIR_INIT_VAR(_30);
	ZEPHIR_SINIT_VAR(_31);
	ZVAL_STRING(&_31, "{", 0);
	ZEPHIR_SINIT_VAR(_32);
	ZVAL_STRING(&_32, "", 0);
	zephir_fast_str_replace(_30, &_31, &_32, str TSRMLS_CC);
	zephir_get_strval(str, _30);
	ZEPHIR_INIT_VAR(_33);
	ZEPHIR_SINIT_VAR(_34);
	ZVAL_STRING(&_34, "}", 0);
	ZEPHIR_SINIT_VAR(_35);
	ZVAL_STRING(&_35, "", 0);
	zephir_fast_str_replace(_33, &_34, &_35, str TSRMLS_CC);
	zephir_get_strval(str, _33);
	ZEPHIR_INIT_VAR(_36);
	ZEPHIR_SINIT_VAR(_37);
	ZVAL_STRING(&_37, "\\\\", 0);
	ZEPHIR_SINIT_VAR(_38);
	ZVAL_STRING(&_38, "", 0);
	zephir_fast_str_replace(_36, &_37, &_38, str TSRMLS_CC);
	zephir_get_strval(str, _36);
	RETURN_CTOR(str);

}

/**
 * 返回经addslashes处理过的字符串或数组
 * @param string|array str 需要处理的字符串或数组
 * @return mixed
 */
PHP_METHOD(Winer_Tool, new_addslashes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *str, *key = NULL, *val = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);

	ZEPHIR_SEPARATE_PARAM(str);


	if (!(Z_TYPE_P(str) == IS_ARRAY)) {
		zephir_addslashes(return_value, str TSRMLS_CC);
		RETURN_MM();
	}
	zephir_is_iterable(str, &_1, &_0, 1, 0, "winer/tool.zep", 48);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_SELF(&_3, "new_addslashes", &_4, val);
		zephir_check_call_status();
		zephir_array_update_zval(&str, key, &_3, PH_COPY | PH_SEPARATE);
	}
	RETVAL_ZVAL(str, 1, 0);
	RETURN_MM();

}

/**
 * 返回经stripslashes处理过的字符串或数组
 * @param string|array str 需要处理的字符串或数组
 * @return mixed
 */
PHP_METHOD(Winer_Tool, new_stripslashes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *str, *key = NULL, *val = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str);

	ZEPHIR_SEPARATE_PARAM(str);


	if (!(Z_TYPE_P(str) == IS_ARRAY)) {
		zephir_stripslashes(return_value, str TSRMLS_CC);
		RETURN_MM();
	}
	zephir_is_iterable(str, &_1, &_0, 1, 0, "winer/tool.zep", 65);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_SELF(&_3, "new_stripslashes", &_4, val);
		zephir_check_call_status();
		zephir_array_update_zval(&str, key, &_3, PH_COPY | PH_SEPARATE);
	}
	RETVAL_ZVAL(str, 1, 0);
	RETURN_MM();

}

/**
 * 数组转换为树。
 * @param array sourceArr 源数组。
 * @param string key 数组主键名称。
 * @param string parentKey 数组父id键名称。
 * @param string childrenKey 生成的子树键名称。
 * @return array
 */
PHP_METHOD(Winer_Tool, arrtyToTree) {

	zend_bool _9;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_19 = NULL;
	int i = 0, ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_21;
	HashPosition _0, _20;
	zval *sourceArr, *key, *parentKey, *childrenKey, *tempSrcArr, *v = NULL, **_2, *_3 = NULL, *count, *tArr = NULL, *_4, *_5, *_7 = NULL, *_8, *_10, *_11 = NULL, *_12, *_13, *_14 = NULL, *_15, *_16, *_17 = NULL, *_18, *_items, *_temp_item = NULL, **_22;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &sourceArr, &key, &parentKey, &childrenKey);

	ZEPHIR_INIT_VAR(tempSrcArr);
	array_init(tempSrcArr);
	ZEPHIR_INIT_VAR(_items);
	array_init(_items);


	zephir_is_iterable(sourceArr, &_1, &_0, 0, 0, "winer/tool.zep", 82);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_OBS_NVAR(_3);
		zephir_array_fetch(&_3, v, key, PH_NOISY, "winer/tool.zep", 80 TSRMLS_CC);
		zephir_array_update_zval(&tempSrcArr, _3, &v, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(count);
	ZVAL_LONG(count, zephir_fast_count_int(sourceArr TSRMLS_CC));
	i = (zephir_get_numberval(count) - 1);
	while (1) {
		if (!(i >= 0)) {
			break;
		}
		i--;
		zephir_array_fetch_long(&_4, sourceArr, i, PH_NOISY | PH_READONLY, "winer/tool.zep", 89 TSRMLS_CC);
		zephir_array_fetch(&_5, _4, parentKey, PH_READONLY, "winer/tool.zep", 89 TSRMLS_CC);
		if (zephir_array_isset(tempSrcArr, _5)) {
			Z_SET_ISREF_P(tempSrcArr);
			ZEPHIR_CALL_FUNCTION(&tArr, "array_pop", &_6, tempSrcArr);
			Z_UNSET_ISREF_P(tempSrcArr);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_OBS_NVAR(_3);
			zephir_array_fetch(&_3, tArr, parentKey, PH_NOISY, "winer/tool.zep", 91 TSRMLS_CC);
			zephir_array_fetch(&_8, tempSrcArr, _3, PH_READONLY, "winer/tool.zep", 91 TSRMLS_CC);
			_9 = zephir_array_isset(_8, childrenKey);
			if (_9) {
				ZEPHIR_OBS_NVAR(_11);
				zephir_array_fetch(&_11, tArr, parentKey, PH_NOISY, "winer/tool.zep", 91 TSRMLS_CC);
				zephir_array_fetch(&_10, tempSrcArr, _11, PH_NOISY | PH_READONLY, "winer/tool.zep", 91 TSRMLS_CC);
				zephir_array_fetch(&_12, _10, childrenKey, PH_NOISY | PH_READONLY, "winer/tool.zep", 91 TSRMLS_CC);
				_9 = Z_TYPE_P(_12) == IS_ARRAY;
			}
			if (_9) {
				ZEPHIR_OBS_NVAR(_14);
				zephir_array_fetch(&_14, tArr, parentKey, PH_NOISY, "winer/tool.zep", 91 TSRMLS_CC);
				zephir_array_fetch(&_13, tempSrcArr, _14, PH_NOISY | PH_READONLY, "winer/tool.zep", 91 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(_7);
				zephir_array_fetch(&_7, _13, childrenKey, PH_NOISY, "winer/tool.zep", 91 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_7);
				array_init(_7);
			}
			zephir_array_fetch(&_15, tArr, parentKey, PH_NOISY | PH_READONLY, "winer/tool.zep", 91 TSRMLS_CC);
			zephir_array_update_multi(&tempSrcArr, &_7 TSRMLS_CC, SL("zz"), 2, _15, childrenKey);
			ZEPHIR_OBS_NVAR(_17);
			zephir_array_fetch(&_17, tArr, parentKey, PH_NOISY, "winer/tool.zep", 92 TSRMLS_CC);
			zephir_array_fetch(&_16, tempSrcArr, _17, PH_NOISY | PH_READONLY, "winer/tool.zep", 92 TSRMLS_CC);
			zephir_array_fetch(&_18, _16, childrenKey, PH_NOISY | PH_READONLY, "winer/tool.zep", 92 TSRMLS_CC);
			Z_SET_ISREF_P(_18);
			ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, _18, tArr);
			Z_UNSET_ISREF_P(_18);
			zephir_check_call_status();
		}
	}
	zephir_is_iterable(tempSrcArr, &_21, &_20, 0, 0, "winer/tool.zep", 102);
	for (
	  ; zephir_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
	  ; zephir_hash_move_forward_ex(_21, &_20)
	) {
		ZEPHIR_GET_HVALUE(_temp_item, _22);
		zephir_array_append(&_items, _temp_item, PH_SEPARATE, "winer/tool.zep", 100);
	}
	RETURN_CCTOR(_items);

}

/**
 * 获取远程内容
 * @param string url 接口url地址
 * @param int timeout 超时时间
 * @return string
 */
PHP_METHOD(Winer_Tool, pc_file_get_contents) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	zval *_0, *_1;
	int timeout, ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *timeout_param = NULL, *stream = NULL, *_2, _4;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &timeout_param);

	zephir_get_strval(url, url_param);
	if (!timeout_param) {
		timeout = 30;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, timeout);
	zephir_array_update_string(&_1, SL("timeout"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("http"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&stream, "stream_context_create", &_3, _0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", &_5, url, &_4, stream);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 转换目录下面的所有文件编码格式
 * @param string in_charset 原字符集
 * @param string out_charset 目标字符集
 * @param string dir_path 目录地址
 * @param string fileexts 转换的文件格式
 * @return string 如果原字符集和目标字符集相同则返回false，否则为true
 */
PHP_METHOD(Winer_Tool, dir_iconv) {

	zephir_fcall_cache_entry *_11 = NULL;
	zend_bool _6;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *in_charset, *out_charset, *dir_path, *fileexts = NULL, *list = NULL, *v = NULL, **_2, _3 = zval_used_for_init, *_4 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &in_charset, &out_charset, &dir_path, &fileexts);

	if (!fileexts) {
		ZEPHIR_INIT_VAR(fileexts);
		ZVAL_STRING(fileexts, "php|html|htm|shtml|shtm|js|txt|xml", 1);
	}


	if (ZEPHIR_IS_EQUAL(in_charset, out_charset)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_SELF(&list, "dir_list", NULL, dir_path);
	zephir_check_call_status();
	zephir_is_iterable(list, &_1, &_0, 0, 0, "winer/tool.zep", 137);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_LONG(&_3, 4);
		ZEPHIR_CALL_FUNCTION(&_4, "pathinfo", &_5, v, &_3);
		zephir_check_call_status();
		_6 = ZEPHIR_IS_EQUAL(_4, fileexts);
		if (_6) {
			ZEPHIR_CALL_FUNCTION(&_7, "is_file", &_8, v);
			zephir_check_call_status();
			_6 = zephir_is_true(_7);
		}
		if (_6) {
			ZEPHIR_INIT_NVAR(_9);
			zephir_file_get_contents(_9, v TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_10, "iconv", &_11, in_charset, out_charset, _9);
			zephir_check_call_status();
			zephir_file_put_contents(NULL, v, _10 TSRMLS_CC);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * 列出目录下所有文件
 * @param string path 路径
 * @param string exts 扩展名
 * @param array list 增加的文件列表
 * @return array 所有满足条件的文件
 */
PHP_METHOD(Winer_Tool, dir_list) {

	zephir_fcall_cache_entry *_12 = NULL;
	zend_bool _6;
	HashTable *_4;
	HashPosition _3;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, *exts = NULL, *list = NULL, *_0 = NULL, *files = NULL, *v = NULL, *_1, **_5, _7 = zval_used_for_init, *_9 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path, &exts, &list);

	ZEPHIR_SEPARATE_PARAM(path);
	if (!exts) {
		ZEPHIR_INIT_VAR(exts);
		ZVAL_STRING(exts, "", 1);
	}
	if (!list) {
		ZEPHIR_INIT_VAR(list);
		array_init(list);
	} else {
		ZEPHIR_SEPARATE_PARAM(list);
	}


	ZEPHIR_CALL_SELF(&_0, "dir_path", NULL, path);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(path, _0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, path, "*");
	ZEPHIR_CALL_FUNCTION(&files, "glob", &_2, _1);
	zephir_check_call_status();
	zephir_is_iterable(files, &_4, &_3, 0, 0, "winer/tool.zep", 160);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(v, _5);
		_6 = !zephir_is_true(exts);
		if (!(_6)) {
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_LONG(&_7, 4);
			ZEPHIR_CALL_FUNCTION(&_0, "pathinfo", &_8, v, &_7);
			zephir_check_call_status();
			_6 = ZEPHIR_IS_EQUAL(_0, exts);
		}
		if (_6) {
			zephir_array_append(&list, v, PH_SEPARATE, "winer/tool.zep", 154);
			ZEPHIR_CALL_FUNCTION(&_9, "is_dir", &_10, v);
			zephir_check_call_status();
			if (zephir_is_true(_9)) {
				ZEPHIR_CALL_SELF(&_11, "dir_list", &_12, v, exts, list);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(list, _11);
			}
		}
	}
	RETVAL_ZVAL(list, 1, 0);
	RETURN_MM();

}

/**
 * 转化 \ 为 /
 * 
 * @param	string	$path	路径
 * @return	string	路径
 */
PHP_METHOD(Winer_Tool, dir_path) {

	zval *path = NULL, *_0 = NULL, _1, _2, _3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path);

	ZEPHIR_SEPARATE_PARAM(path);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\\\\", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/", 0);
	zephir_fast_str_replace(_0, &_1, &_2, path TSRMLS_CC);
	ZEPHIR_CPY_WRT(path, _0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, -1);
	ZEPHIR_INIT_NVAR(_0);
	zephir_substr(_0, path, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	if (!ZEPHIR_IS_STRING(_0, "/")) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VS(_4, path, "/");
		ZEPHIR_CPY_WRT(path, _4);
	}
	RETVAL_ZVAL(path, 1, 0);
	RETURN_MM();

}

/**
 * 删除目录及目录下面的所有文件
 * @param string dir 路径
 * @return bool 如果成功则返回 TRUE，失败则返回 FALSE
 */
PHP_METHOD(Winer_Tool, dir_delete) {

	zephir_fcall_cache_entry *_8 = NULL;
	HashTable *_5;
	HashPosition _4;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_9 = NULL, *_10 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dir = NULL, *_0 = NULL, *list = NULL, *v = NULL, *_2, **_6, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir);

	ZEPHIR_SEPARATE_PARAM(dir);


	ZEPHIR_CALL_SELF(&_0, "dir_path", NULL, dir);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dir, _0);
	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", &_1, dir);
	zephir_check_call_status();
	if (!zephir_is_true(_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, dir, "*");
	ZEPHIR_CALL_FUNCTION(&list, "glob", &_3, _2);
	zephir_check_call_status();
	zephir_is_iterable(list, &_5, &_4, 0, 0, "winer/tool.zep", 197);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(v, _6);
		ZEPHIR_CALL_FUNCTION(&_7, "is_dir", &_1, v);
		zephir_check_call_status();
		if (zephir_is_true(_7)) {
			ZEPHIR_CALL_SELF(NULL, "dir_delete", &_8, v);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_9, v);
			zephir_check_call_status();
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("rmdir", &_10, dir);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取得文件扩展
 * @param $filename 文件名
 * @return 扩展名
 */
PHP_METHOD(Winer_Tool, fileext) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *filename, *_0, _1 = zval_used_for_init, *_2 = NULL, _4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, ".", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "strrchr", &_3, filename, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 10);
	ZEPHIR_INIT_VAR(_5);
	zephir_substr(_5, _2, 1 , 10 , 0);
	zephir_fast_trim(_0, _5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	zephir_fast_strtolower(return_value, _0);
	RETURN_MM();

}

/**
 * 转换字节数为其他单位
 * @param int filesize 字节大小
 * @return string 返回大小
 */
PHP_METHOD(Winer_Tool, sizecount) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *filesize_param = NULL, *size_label = NULL, *_0 = NULL, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL;
	int filesize, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filesize_param);

	filesize = zephir_get_intval(filesize_param);


	if (filesize >= 1073741824) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_DOUBLE(&_1, (zephir_safe_div_long_long(filesize, 1073741824 TSRMLS_CC) * (double) (100)));
		zephir_round(_0, &_1, NULL, NULL TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_DOUBLE(&_2, zephir_safe_div_zval_long(_0, 100 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_3, "strval", &_4, &_2);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(size_label);
		ZEPHIR_CONCAT_VS(size_label, _3, " GB");
	} else if (filesize >= 1048576) {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_DOUBLE(&_1, (zephir_safe_div_long_long(filesize, 1048576 TSRMLS_CC) * (double) (100)));
		zephir_round(_0, &_1, NULL, NULL TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_DOUBLE(&_2, zephir_safe_div_zval_long(_0, 100 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_3, "strval", &_4, &_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(size_label);
		ZEPHIR_CONCAT_VS(size_label, _3, " MB");
	} else if (filesize >= 1024) {
		ZEPHIR_INIT_NVAR(_0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_DOUBLE(&_1, (zephir_safe_div_long_long(filesize, 1024 TSRMLS_CC) * (double) (100)));
		zephir_round(_0, &_1, NULL, NULL TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_DOUBLE(&_2, zephir_safe_div_zval_long(_0, 100 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&_3, "strval", &_4, &_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(size_label);
		ZEPHIR_CONCAT_VS(size_label, _3, " KB");
	} else {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, filesize);
		ZEPHIR_CALL_FUNCTION(&_3, "strval", &_4, &_1);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(size_label);
		ZEPHIR_CONCAT_VS(size_label, _3, " Bytes");
	}
	RETURN_CCTOR(size_label);

}

/**
 * 生成随机字符串
 * @param int $lenth 长度
 * @return string 字符串
 */
PHP_METHOD(Winer_Tool, create_randomstr) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *lenth = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &lenth);

	if (!lenth) {
		ZEPHIR_INIT_VAR(lenth);
		ZVAL_LONG(lenth, 6);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 74);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 2);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 3);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 4);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 5);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 6);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 7);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 8);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 9);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "a", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "b", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "c", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "d", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "e", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "f", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "g", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "h", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "i", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "j", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "k", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "l", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "m", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "n", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "p", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "q", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "r", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "s", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "t", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "u", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "v", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "w", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "x", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "y", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "z", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "A", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "B", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "C", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "D", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "E", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "F", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "G", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "H", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "I", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "J", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "K", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "L", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "M", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "N", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "P", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Q", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "R", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "S", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "T", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "U", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "V", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "W", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "X", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Y", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "Z", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_RETURN_CALL_SELF("random", NULL, lenth, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 产生随机字符串
 * @param int $length 输出长度
 * @param string $chars 可选的,默认为 0123456789
 * @return string 字符串
 */
PHP_METHOD(Winer_Tool, random) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int i = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *chars = NULL;
	zval *length, *chars_param = NULL, *hash, *max, *_index = NULL, _0 = zval_used_for_init, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length, &chars_param);

	if (!chars_param) {
		ZEPHIR_INIT_VAR(chars);
		array_init(chars);
	} else {
		zephir_get_arrval(chars, chars_param);
	}
	ZEPHIR_INIT_VAR(hash);
	ZVAL_STRING(hash, "", 1);


	ZEPHIR_INIT_VAR(max);
	ZVAL_LONG(max, (zephir_fast_count_int(chars TSRMLS_CC) - 1));
	while (1) {
		if (!(ZEPHIR_GT_LONG(length, i))) {
			break;
		}
		i++;
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_CALL_FUNCTION(&_index, "mt_rand", &_1, &_0, max);
		zephir_check_call_status();
		zephir_array_fetch(&_2, chars, _index, PH_NOISY | PH_READONLY, "winer/tool.zep", 252 TSRMLS_CC);
		zephir_concat_self(&hash, _2 TSRMLS_CC);
	}
	RETURN_CCTOR(hash);

}

