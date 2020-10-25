//思路： DFS
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
		// 遍历二维数组
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if ('1' == grid[i][j]) {
					// 将该位置上下左右为1的位置都置为0
					DFS(grid, i, j);
					result++;
				}
			}
		}
		return result;
	}
private:
	void DFS(vector<vector<char>>& grid, int i, int j) {
		// terminator
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
		if ('0' == grid[i][j]) return;
		//process
		grid[i][j] = '0';
		// drill down
		DFS(grid, i + 1, j);
		DFS(grid, i - 1, j);
		DFS(grid, i, j + 1);
		DFS(grid, i, j - 1);
	}
};