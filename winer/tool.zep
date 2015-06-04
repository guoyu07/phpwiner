/**
 * 工具库。
 * @author winerQin
 * @date 2015-05-06
 * @lastmodify 2015-05-06
 */

namespace Winer;

class Tool {
    
    /**
     * 安全过滤函数
     * @param string str
     * @return string
     */
    public static function safe_replace(string str) {
        let str = str_replace("%20", "", str);
        let str = str_replace("%27", "", str);
        let str = str_replace("%2527", "", str);
        let str = str_replace("*", "", str);
        let str = str_replace("\"", "&quot;", str);
        let str = str_replace("\"", "", str);
        let str = str_replace("\"", "", str);
        let str = str_replace(";", "", str);
        let str = str_replace("<", "&lt;", str);
        let str = str_replace(">", "&gt;", str);
        let str = str_replace("{", "", str);
        let str = str_replace("}", "", str);
        let str = str_replace("\\\\", "", str);
        return str;
    }

    /**
     * 返回经addslashes处理过的字符串或数组
     * @param string|array str 需要处理的字符串或数组
     * @return mixed
     */
    public static function new_addslashes(str){
        if(!is_array(str)) {
        	return addslashes(str);
        }
        var key;
        var val;
        for key, val in str {
        	let str[key] = self::new_addslashes(val);
        }
        return str;
    }

    /**
     * 返回经stripslashes处理过的字符串或数组
     * @param string|array str 需要处理的字符串或数组
     * @return mixed
     */
    public static function new_stripslashes(str) {
        if(!is_array(str)) {
        	return stripslashes(str);
        }
        var key;
        var val;
        for key, val in str {
        	let str[key] = self::new_stripslashes(val);
        }
        return str;
    }
    
    /**
     * 数组转换为树。
     * @param array sourceArr 源数组。
     * @param string key 数组主键名称。
     * @param string parentKey 数组父id键名称。
     * @param string childrenKey 生成的子树键名称。
     * @return array
     */
    public static function arrtyToTree(sourceArr, key, parentKey, childrenKey) {
        var tempSrcArr = [];
        var v;
        for v in sourceArr {
        	let tempSrcArr[v[key]] = v;
        }
        var i = 0;
        var count;
        var tArr;
        let count = count(sourceArr);
        let i = count - 1;
        while i >= 0 {
        	let i--;
        	if (isset(tempSrcArr[sourceArr[i][parentKey]])) {
                let tArr = array_pop(tempSrcArr);
                let tempSrcArr[tArr[parentKey]][childrenKey] = (isset(tempSrcArr[tArr[parentKey]][childrenKey]) && is_array(tempSrcArr[tArr[parentKey]][childrenKey])) ? tempSrcArr[tArr[parentKey]][childrenKey] : [];
                array_push(tempSrcArr[tArr[parentKey]][childrenKey], tArr);
            }
        }

        // 最外层关联索引转换为数字索引，这样在json转换的时候是list,而非对象。
        var _items = [];
        var _temp_item;
        for _temp_item in tempSrcArr {
        	let _items[] = _temp_item;
        }
        return _items;
    }
    
    /**
     * 获取远程内容
     * @param string url 接口url地址
     * @param int timeout 超时时间
     * @return string
     */
    public static function pc_file_get_contents(string url, int timeout = 30) -> string {
    	var stream;
        let stream = stream_context_create(["http" : ["timeout" : timeout]]);
        return file_get_contents(url, 0, stream);
    }
    
    /**
     * 转换目录下面的所有文件编码格式
     * @param string in_charset 原字符集
     * @param string out_charset 目标字符集
     * @param string dir_path 目录地址
     * @param string fileexts 转换的文件格式
     * @return string 如果原字符集和目标字符集相同则返回false，否则为true
     */
    public static function dir_iconv(in_charset, out_charset, dir_path, fileexts = "php|html|htm|shtml|shtm|js|txt|xml") {
        if(in_charset == out_charset) {
        	return false;
        }
        var list;
        var v;
        let list = self::dir_list(dir_path);
        for v in list {
        	if (pathinfo(v, PATHINFO_EXTENSION) == fileexts && is_file(v)) {
                file_put_contents(v, iconv(in_charset, out_charset, file_get_contents(v)));
            }
        }
        return true;
    }
    
    /**
     * 列出目录下所有文件
     * @param string path 路径
     * @param string exts 扩展名
     * @param array list 增加的文件列表
     * @return array 所有满足条件的文件
     */
    public static function dir_list(path, exts = "", list = []) {
        let path = self::dir_path(path);
        var files;
        var v;
        let files = glob(path . "*");
        for v in files {
        	if (!exts || pathinfo(v, PATHINFO_EXTENSION) == exts) {
                let list[] = v;
                if (is_dir(v)) {
                    let list = self::dir_list(v, exts, list);
                }
            }
        }
        return list;
    }
    
    /**
	 * 转化 \ 为 /
	 * 
	 * @param	string	$path	路径
	 * @return	string	路径
	 */
	public static function dir_path(path) {
		let path = str_replace("\\\\", "/", path);
		if(substr(path, -1) != "/") {
			let path = path . "/";
		}
		return path;
	}
    
    /**
     * 删除目录及目录下面的所有文件
     * @param string dir 路径
     * @return bool 如果成功则返回 TRUE，失败则返回 FALSE
     */
    public static function dir_delete(dir) {
        let dir = self::dir_path(dir);
        if (!is_dir(dir)) {
        	return FALSE;
        }
        var list;
        var v;
        let list = glob($dir . "*");
        for v in list {
        	if (is_dir(v)) {
        		self::dir_delete(v);
        	} else {
        		unlink(v);
        	}
        }
        return rmdir(dir);
    }
    
    /**
     * 取得文件扩展
     * @param $filename 文件名
     * @return 扩展名
     */
    public static function fileext(filename) {
        return strtolower(trim(substr(strrchr(filename, "."), 1, 10)));
    }
    
    /**
     * 转换字节数为其他单位
     * @param int filesize 字节大小
     * @return string 返回大小
     */
    public static function sizecount(int filesize) {
    	var size_label;
        if (filesize >= 1073741824) {
            let size_label = strval(round(filesize / 1073741824 * 100) / 100) ." GB";
        } elseif (filesize >= 1048576) {
            let size_label = strval(round(filesize / 1048576 * 100) / 100) ." MB";
        } elseif(filesize >= 1024) {
            let size_label = strval(round(filesize / 1024 * 100) / 100) . " KB";
        } else {
            let size_label = strval(filesize) . " Bytes";
        }
        return size_label;
    }

    /**
     * 生成随机字符串
     * @param int $lenth 长度
     * @return string 字符串
     */
    public static function create_randomstr(lenth = 6) {
        return self::random(lenth, ["1","2","3","4","5","6","7","8","9","a","b","c","d","e","f","g","h","i","j","k","l","m","n","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","P","Q","R","S","T","U","V","W","X","Y","Z"]);
    }

    /**
     * 产生随机字符串
     * @param int $length 输出长度
     * @param string $chars 可选的,默认为 0123456789
     * @return string 字符串
     */
    public static function random(length, array chars = ["0","1","2","3","4","5","6","7","8","9"]) {
        var hash = "";
        var max;
        let max = count(chars) - 1;
        var i = 0;
        while i < length {
        	let i++;
        	var _index;
        	let _index = mt_rand(0, max);
        	let hash .= chars[_index];
        }
        return hash;
    }
    
}