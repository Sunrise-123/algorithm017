// ˼·�� ��ȫ��������Ļ����Ͻ���ȥ��(��֦)
// ע��㣺�����ظ�Ԫ��һ��Ҫ�������򣬽��ظ��Ķ�����һ�𣬱����ҵ��ظ�Ԫ�غͼ�֦��
//        ������Ŀ�漰�ظ�Ԫ�ػ�Ƚϴ�С�����ȿ�������
// ��1�� ������ȱ����� ʱ�临�Ӷ�Ϊ��O(n*n!)
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		//��Ž��
		vector<vector<int>> result;
		//��ŵ�ǰ����
		vector<int> perm;
		used.resize(nums.size());
		if (nums.size() == 0) return result;
		//��������
		sort(nums.begin(), nums.end());
		backtrack(nums, result, 0, perm);
		return result;
	}

private:
	//��ŵ�ǰԪ���Ƿ�ʹ��
	vector<int> used;
	// index: ��ǰλ�ã�perm:��λ���²���������
	void backtrack(vector<int>& nums, vector<vector<int>>& res, int index, vector<int>& perm) {
		// ��ֹ����
		if (index == nums.size()) {
			res.emplace_back(perm);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (used[i] || (i > 0 && nums[i] == nums[i - 1]) && !used[i - 1]) continue;
			perm.emplace_back(nums[i]);
			used[i] = 1;
			backtrack(nums, res, index + 1, perm);
			used[i] = 0;
			perm.pop_back();
		}
		return;
	}

};