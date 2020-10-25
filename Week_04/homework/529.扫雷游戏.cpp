//思路：总体分为两种情况：
//    1. 点击的位置是有雷(M)，该位置置为‘X’，游戏结束；
//    2. 点击的位置是无雷(E)，此时分为两种情况：
//      (1) 周围均无雷，位置置为'B'，且再向周围扩散搜索;
//      (2) 周围有雷，该点击位置显示数字:1-8；
//
//法1：dfs
class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		//定义8个方向
		vector<vector<int>> dir = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1, 1 },{ -1, -1 } };
		//点击的行和列
		int row = click[0], col = click[1];
		if ('M' == board[row][col]) {
			// 点击的位置，有雷
			board[row][col] = 'X';
		}
		else {
			//点击的位置，无雷,需要搜索周围的8个位置
			dfs(board, row, col, dir);
		}
		return board;
	}
private:
	void dfs(vector<vector<char>>& board, int row, int col, vector<vector<int>> dir) {
		//terminator
		// 统计该位置周围8个位置的雷的个数
		int count = 0;
		for (int i = 0; i < 8; i++) {
			int x = row + dir[i][0];
			int y = col + dir[i][1];
			// 判断下标的合法性，防止越界
			if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
			if ('M' == board[x][y]) {
				count++;
			}
		}
		// 规则3：周围8个位置有雷，修改为雷的个数
		if (count > 0) {
			board[row][col] = '0' + count;
			return;
		}
		else {
			//规则2：周围8个位置无雷，,该位置置为'B', 并继续搜索周围的位置，直到周围无'E'
			board[row][col] = 'B';
			for (int i = 0; i < 8; i++) {
				int x = row + dir[i][0];
				int y = col + dir[i][1];
				// 判断下标的合法性，防止越界
				if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'E') continue;
				dfs(board, x, y, dir);
			}
		}
	}
};