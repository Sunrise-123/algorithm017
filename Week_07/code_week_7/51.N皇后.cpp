class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> currentStr(n, string(n, '.'));
		// 正对角线
		vector<int> deg(2 * n, 0);
		// 反对角线
		vector<int> adeg(2 * n, 0);
		vector<int> col(n, 0);
		backTrack(0, n, col, deg, adeg, currentStr, result);
		return result;
	}
private:
	void backTrack(int row, int n, vector<int> col, vector<int> deg, vector<int> adeg, vector<string> currentStr, vector<vector<string>>& result)
	{
		if (row == n) {
			result.push_back(currentStr);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!col[i] && !deg[row - i + n] && !adeg[row + i]) {
				col[i] = deg[row - i + n] = adeg[row + i] = 1;
				currentStr[row][i] = 'Q';
				backTrack(row + 1, n, col, deg, adeg, currentStr, result);
				currentStr[row][i] = '.';
				col[i] = deg[row - i + n] = adeg[row + i] = 0;
			}
		}
	}

};