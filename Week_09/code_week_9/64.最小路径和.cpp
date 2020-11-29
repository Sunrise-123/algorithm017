//动态规划：1.第0行中的位置，只能从左侧移动得到。dp[0][j] += dp[0][j-1]
//         2.第0列中的位置，只能从左侧移动得到。dp[i][0] += dp[i-][0]
//         3.i不为0，j不为0的位置，可以从dp[i-1][j] 和 dp[i][j-1]两个位置得到。
//            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + dp[i][j]
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0) return 0;
		int row = grid.size();
		int col = grid[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (i == 0 && j == 0) continue;
				else if (i == 0) grid[i][j] += grid[i][j - 1];
				else if (j == 0) grid[i][j] += grid[i - 1][j];
				else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[row - 1][col - 1];
	}
};