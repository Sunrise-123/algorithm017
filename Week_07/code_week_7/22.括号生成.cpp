class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n < 1) return result;
		string currentStr;
		generate(0, 0, n, currentStr, result);
		return result;
	}
private:
	void generate(int left, int right, int n, string currentStr, vector<string>& result) {
		if (left == n && right == n) {
			result.emplace_back(currentStr);
			return;
		}
		// ºÙ÷¶
		if (left < n) generate(left + 1, right, n, currentStr + "(", result);
		if (right < left) generate(left, right + 1, n, currentStr + ")", result);
	}
};