// ˼·�� 
// ��1. ������Ȼ��ͳ��ÿ����ĸ���ֵĴ������Ƚ����ַ������ַ��ĸ����Ƿ���ͬ
// ��2. ʹ�����飬����Ϊ26��Ȼ��ͳ��s�ַ������ַ����ֵĴ���������t�г��ֵ��ַ�������Ӧ�ַ��Ĵ�����
//    �����������е�Ԫ�ؾ�Ϊ0����Ϊtrue,��֮Ϊfalse.
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