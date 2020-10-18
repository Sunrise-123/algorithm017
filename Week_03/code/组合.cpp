// ˼·��Ҫ�ҵ���������Ľ⣬��ȻҪ���б���
//      ͨ��ö�ٿ��Եõ����н⣬��˿��Ի��Ƴ�������ʽ���������ǵ����ݷ�
//
// ʱ�临�Ӷȣ�O((��n��ѡ��K) * k)
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
		// ��ֹ����
		if (path.size() == k) {
			res.emplace_back(path);
			return;
		}
		//
		for (int i = start; i <= n - (k - path.size()) + 1; i++) {
			//����ǰ�߼�
			path.emplace_back(i);
			//��̽����һ��
			dfs(n, k, i + 1, path, res);
			// reverse
			path.pop_back();
		}
	}
};