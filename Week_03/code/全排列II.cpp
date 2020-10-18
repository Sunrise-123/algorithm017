// 思路： 在全排列问题的基础上进行去重(剪枝)
// 注意点：考虑重复元素一定要优先排序，将重复的都放在一起，便于找到重复元素和剪枝！
//        （若题目涉及重复元素或比较大小，优先考虑排序）
// 法1： 深度优先遍历。 时间复杂度为：O(n*n!)
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		//存放结果
		vector<vector<int>> result;
		//存放当前排列
		vector<int> perm;
		used.resize(nums.size());
		if (nums.size() == 0) return result;
		//排列数组
		sort(nums.begin(), nums.end());
		backtrack(nums, result, 0, perm);
		return result;
	}

private:
	//存放当前元素是否被使用
	vector<int> used;
	// index: 当前位置；perm:该位置下产生的数组
	void backtrack(vector<int>& nums, vector<vector<int>>& res, int index, vector<int>& perm) {
		// 终止条件
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