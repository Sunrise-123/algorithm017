class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		int hash[26] = { 0 };
		for (auto n : s)
			hash[n - 'a']++;
		for (auto m : t)
			hash[m - 'a']--;
		for (int i = 0; i < 26; i++) {
			if (hash[i] != 0) return false;
		}
		return true;
	}
};