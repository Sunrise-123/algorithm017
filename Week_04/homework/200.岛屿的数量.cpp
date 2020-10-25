//˼·�� DFS
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
		// ������ά����
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if ('1' == grid[i][j]) {
					// ����λ����������Ϊ1��λ�ö���Ϊ0
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