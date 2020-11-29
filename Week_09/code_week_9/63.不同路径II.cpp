//动态规划：在当前位置为障碍物时，到达该点的步数为0
//         dp[i][j] = dp[i-1][j] + dp[i][j-1], obstacleGrid[i][j] == 0
//         dp[i][j] = 0                      , obstacleGrid[i][j] == 1

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.size() == 0) return 0;
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		vector<vector<int>> dp(row, vector<int>(col, 0));
		for (int i = 0; i < row && obstacleGrid[i][0] != 1; i++) {
			dp[i][0] = 1;
		}
		for (int j = 0; j < col && obstacleGrid[0][j] != 1; j++) {
			dp[0][j] = 1;
		}

		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				if (obstacleGrid[i][j] == 0) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else {
					dp[i][j] = 0;
				}
			}
		}
		return dp[row - 1][col - 1];

	}
};