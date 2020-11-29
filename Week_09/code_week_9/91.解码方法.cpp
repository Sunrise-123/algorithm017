// 
//
class Solution {
public:
	int numDecodings(string s) {
		int len = s.length();
		if (len == 0 || s == "0") return 0;
		vector<int> dp(len + 1, 1);
		dp[1] = s[0] == '0' ? 0 : 1;
		for (int i = 1; i < len; i++) {
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) {
				if (s[i] == '0') dp[i + 1] = dp[i - 1];
				else dp[i + 1] = dp[i] + dp[i - 1];
			}
			else if (s[i] == '0') {
				return 0;
			}
			else {
				dp[i + 1] = dp[i];
			}
		}
		return dp[len];
	}
};