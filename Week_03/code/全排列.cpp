//˼·�� ���ݷ���ͨ�����ϵ��Դ����õ����⣬���ò������⣬��ȡ��ǰ�����Ĳ�����
//       ͨ���õݹ鷽����������յõ���������н�
// ʱ�临�Ӷȣ�O(n * n!)
// ��������ÿ��ѡȡһ��Ԫ�ع̶��ڵ�һ��λ�ã�Ȼ��������ʣ��λ�õ�����
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>result;
		backtrack(result, nums, 0, (int)nums.size());
		return result;
	}
private:
	void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
		// �ݹ����������
		if (first == len) {
			res.emplace_back(output);
			return;
		}
		for (int i = first; i < len; i++) {
			//ά������
			swap(output[i], output[first]);
			//�����ݹ���һ����
			backtrack(res, output, first + 1, len);
			// ��������
			swap(output[i], output[first]);
		}
	}
};