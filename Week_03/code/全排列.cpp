//思路： 回溯法，通过不断的试错来得到正解，若得不到正解，则取消前几步的操作。
//       通常用递归方法解决，最终得到问题的所有解
// 时间复杂度：O(n * n!)
// 交换法：每次选取一个元素固定在第一个位置，然后找数组剩余位置的排列
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>result;
		backtrack(result, nums, 0, (int)nums.size());
		return result;
	}
private:
	void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
		// 递归结束的条件
		if (first == len) {
			res.emplace_back(output);
			return;
		}
		for (int i = first; i < len; i++) {
			//维护数组
			swap(output[i], output[first]);
			//继续递归下一个数
			backtrack(res, output, first + 1, len);
			// 撤销操作
			swap(output[i], output[first]);
		}
	}
};