// 思路：遍历board,看是否满足要求的3个条件
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int row[9][10] = { 0 };
		int col[9][10] = { 0 };
		int box[9][10] = { 0 };
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				int currentNumber = board[i][j] - '0';
				if (row[i][currentNumber]) return false;
				if (col[j][currentNumber]) return false;
				if (box[j / 3 + (i / 3) * 3][currentNumber]) return false;
				row[i][currentNumber] = 1;
				col[j][currentNumber] = 1;
				box[j / 3 + (i / 3) * 3][currentNumber] = 1;
			}
		}
		return true;
	}
};