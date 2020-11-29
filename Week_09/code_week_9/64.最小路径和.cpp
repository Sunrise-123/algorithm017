//��̬�滮��1.��0���е�λ�ã�ֻ�ܴ�����ƶ��õ���dp[0][j] += dp[0][j-1]
//         2.��0���е�λ�ã�ֻ�ܴ�����ƶ��õ���dp[i][0] += dp[i-][0]
//         3.i��Ϊ0��j��Ϊ0��λ�ã����Դ�dp[i-1][j] �� dp[i][j-1]����λ�õõ���
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