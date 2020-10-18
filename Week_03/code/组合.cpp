// 思路：要找到所有问题的解，自然要进行遍历
//      通过枚举可以得到所有解，因此可以绘制成树的形式，进而考虑到回溯法
//
// 时间复杂度：O((从n中选择K) * k)
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> path;
		dfs(n, k, 1, path, result);
		return result;
	}
private:
	void dfs(int n, int k, int start, vector<int>& path, vector<vector<int>>& res) {
		// 终止条件
		if (path.size() == k) {
			res.emplace_back(path);
			return;
		}
		//
		for (int i = start; i <= n - (k - path.size()) + 1; i++) {
			//处理当前逻辑
			path.emplace_back(i);
			//下探到下一层
			dfs(n, k, i + 1, path, res);
			// reverse
			path.pop_back();
		}
	}
};