// 思路： 
// 法1. 先排序，然后统计每个字母出现的次数，比较两字符串中字符的个数是否相同
// 法2. 使用数组，长度为26，然后统计s字符串中字符出现的次数，再用t中出现的字符减少相应字符的次数，
//    若最终数组中的元素均为0，则为true,反之为false.
//
class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		int str[26] = { 0 };
		for (auto n : s) {
			str[n - 'a']++;
		}
		for (auto m : t) {
			str[m - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (str[i] != 0) return false;
		}
		return true;
	}
};