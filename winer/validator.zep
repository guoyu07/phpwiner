namespace Winer;

class Validator {

	/**
	 * 判断是否为合法的用户名。
	 * @param string username
	 * @param uint min_len 最小长度。包含。
	 * @param uint max_len 最大长度。包含。
	 * @param string mode 用户名模式：digit、alpha、digit_alpha、chinese、digit_alpha_chinese、mix
	 *			digit：数字
	 *			aplha：字母
	 *			digit_alpha：数字和字母
	 *			chinese：中文
	 *			digit_alpha_chinese：数字字母中文
	 *			mix：混合型：数字字母中文下划线破折号
	 * @return bool
	 */
	public static function is_username(string username, uint min_len, uint max_len, string mode = "mix") {
	    bool ok;
	    string pattern;
		switch (mode) {
			case "digit":
				let pattern = "/^\d{" . strval(min_len) . "," . strval(max_len) . "}$/";
			    let ok = preg_match(pattern, username) ? true : false;
				break;

			case "alpha":
				let pattern = "/^([a-zA-Z]){" . strval(min_len) . "," . strval(max_len) . "}$/";
			    let ok = preg_match(pattern, username) ? true : false;
				break;

			case "digit_alpha":
				let pattern = "/^([a-z0-9_-]){" . strval(min_len) . "," . strval(max_len) . "}$/";
				let ok = preg_match(pattern, username) ? true : false;
				break;

			case "chinese":
				let pattern = "/^[\x7f-\xff]{" . strval(min_len) . "," . strval(max_len) . "}$/";
				let ok = (preg_match(pattern, username)) ? true : false;
				break;

			case "digit_alpha_chinese":
				let pattern = "/^[\x7f-\xff|0-9a-zA-Z]{" . strval(min_len) . "," . strval(max_len) . "}$/";
				let ok = (preg_match(pattern, username)) ? true : false;
				break;

			case "mix":
			default:
				let pattern = "/^[\x7f-\xff|0-9a-zA-Z-_]{" . strval(min_len) . "," . strval(max_len) . "}$/";
				let ok = (preg_match(pattern, username)) ? true : false;
				break;
		}
		return ok;
	}

	/**
	 * 判断是否为合法的密码。
	 * @param string password
	 * @param uint min_len 最小长度。包含。
	 * @param uint max_len 最大长度。包含。
	 * @param string mode 用户名模式：digit_alpha、mix
	 *			digit_alpha：数字和字母
	 *			mix：混合型：数字字母下划线破折号
	 * @return bool
	 */
	public static function is_password(string password, uint min_len, uint max_len, string mode = "mix") {
		string pattern;
		if mode == "digit_alpha" {
			let pattern = "/^([a-z0-9]){" . strval(min_len) . "," . strval(max_len) . "}$/";
			return preg_match($pattern, password) ? true : false;
		} elseif mode == "mix" {
			let pattern = "/^[0-9a-zA-Z-_]{" . strval(min_len) . "," . strval(max_len) . "}$/";
			return (preg_match($pattern, password)) ? true : false;
		}
	}

	/**
	 * 判断是否为QQ号码。
	 * @param string qq
	 * @return boolean
	 */
	public static function is_qq(string qq) {
		return preg_match("/^[1-9]\d{4,12}$/", qq) ? true : false;
	}

	/**
	 * 判断是否为手机号码。
	 * @param string mobilephone
	 * @return boolean
	 */
	public static function is_mobilephone(string mobilephone) {
		return preg_match("/^13[\d]{9}|14^[0-9]\d{8}|^15[0-9]\d{8}|^18[0-9]\d{8}$/", mobilephone) ? true : false;
	}

	/**
	 * 判断是否为座机号码。
	 * @param string telphone
	 * @return boolean
	 */
	public static function is_telphone(string telphone) {
		return preg_match("/^((\(\d{2,3}\))|(\d{3}\-))?(\(0\d{2,3}\)|0\d{2,3}-)?[1-9]\d{6,7}(\-\d{1,4})?$/", telphone) ? true : false;
	}

	/**
	 * 判断是否为邮政编码。
	 * @param string zipcode
	 * @return boolean
	 */
	public static function is_zipcode(string zipcode) {
		return preg_match("/^[1-9]\d{5}$/", zipcode) ? true : false;
	}

	/**
	 * 判断字母是否在某个区域内。用于判断某个字符只能介于[a-h](包含)之间的类似情况。
	 * @param string alpha 原值。
	 * @param string start_alpha 起始值。
	 * @param string end_alpha 截止值。
	 * @return boolean
	 */
	public static function alpha_between(string alpha, string start_alpha, string end_alpha) {
		if (self::is_alpha(alpha) == false) {
			return false;
		}
		if (self::is_alpha(start_alpha) == false) {
			return false;
		}
		if (self::is_alpha(end_alpha) == false) {
			return false;
		}
		if (start_alpha >= end_alpha) {
			return false;
		}
		if (alpha < start_alpha) {
			return false;
		}
		if (alpha > end_alpha) {
			return false;
		}
		return true;
	}
	
	/**
	 * 判断数字是否在某个区域之间。[2, 10],包含边界值。
	 * @param int value 原值。
	 * @param int start_value 起始值。
	 * @param int end_value 截止值。
	 * @return boolean
	 */
	public static function number_between(int value, int start_value, int end_value) {
		if (is_numeric(value) === false || is_numeric(start_value) === false || is_numeric(end_value) === false) {
			return false;
		}
		if (start_value >= end_value) {
			return false;
		}
		if (value < start_value) {
			return false;
		}
		if (value > end_value) {
			return false;
		}
		return true;
	}

	/**
	 * 验证是否为中文。
	 * @param string char
	 * @return bool
	 */
	public static function is_chinese(string ch) {
		if (strlen(ch) === 0) {
			return false;
		}
		return (preg_match("/^[\x7f-\xff]+$/", ch)) ? true : false;
	}

	/**
	 * 判断是否为字母、数字、下划线（_）、破折号（-）。
	 * @param string str
	 * @return boolean
	 */
	public static function is_alpha_dash(string str) {
		return preg_match("/^([a-z0-9_-])+$/i", str) ? true : false;
	}
	
	/**
	 * 判断是否为字母数字。
	 * @param string str
	 * @return boolean
	 */
	public static function is_alpha_number(string str) {
		return preg_match("/^([a-z0-9])+$/i", str) ? true : false;
	}

	/**
	 * 判断是否为字母。
	 * @param string str
	 * @return boolean
	 */
	public static function is_alpha(string str) {
		return preg_match("/^([a-z])+$/i", str) ? true : false;
	}
	
	/**
	 * 验证日期时间格式。
	 * -- 1、验证value是否为format格式。
	 * -- 2、只能验证格式，不能验证时间是否正确。比如：2014-22-22
	 * @param string format 格式。格式如：Y-m-d 或H:i:s
	 * @param string value 日期。
	 * @return boolean
	 */
	public static function is_date_format(string format, string value) {
		return date_create_from_format(format, value) !== false;
	}
	
	/**
	 * 判断是否为整数。
	 * @param string str
	 * @return boolean
	 */
	public static function is_integer(string str) {
		return filter_var(str, FILTER_VALIDATE_INT) !== false;
	}
	
	/**
	 * 验证IP是否合法。
	 * @param string ip
	 * @return bool
	 */
	public static function is_ip(string ip) {
		return filter_var(ip, FILTER_VALIDATE_IP) !== false;
	}

	/**
	 * 验证URL是否合法。
	 * -- 合法的URL：http://www.baidu.com
	 * @param string url
	 * @return bool
	 */
	public static function is_url(string url) {
		return filter_var(url, FILTER_VALIDATE_URL) !== false;
	}

	/**
	 * 判断email格式是否正确。
	 * @param string email
	 * @return bool
	 */
	public static function is_email(string email) {
		return filter_var(email, FILTER_VALIDATE_EMAIL) !== false;
	}

	/**
	 * 是否必需。
	 * @param string str
	 * @return bool
	 */
	public static function is_require(string str) {
		return strlen(str) ? true : false;
	}

	/**
	 * 判断字符串是否为utf8编码，英文和半角字符返回ture。
	 * @param string string
	 * @return bool
	 */
	public static function is_utf8(str) {
		return preg_match("%^(?:
					[\x09\x0A\x0D\x20-\x7E]
					| [\xC2-\xDF][\x80-\xBF]
					| \xE0[\xA0-\xBF][\x80-\xBF]
					| [\xE1-\xEC\xEE\xEF][\x80-\xBF]{2}
					| \xED[\x80-\x9F][\x80-\xBF]
					| \xF0[\x90-\xBF][\x80-\xBF]{2}
					| [\xF1-\xF3][\x80-\xBF]{3}
					| \xF4[\x80-\x8F][\x80-\xBF]{2}
					)*$%xs", str) ? true : false;
	}
	
	/**
	 * 检查字符串长度。
	 * @param string str 字符串。
	 * @param int min 最小长度。
	 * @param int max 最大长度。
	 * @param bool is_utf8 是否UTF-8字符。
	 * @return boolean
	 */
	public static function len(string str, int min = 0, int max = 255, bool is_utf8 = false) {
		int len;
		let len = is_utf8 ? mb_strlen(str) : strlen(str);
		if ((len >= min) && (len <= max)) {
			return true;
		} else {
			return false;
		}
	}
}