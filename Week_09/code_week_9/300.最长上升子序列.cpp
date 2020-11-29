//法1：动态规划 O(n^2)
//    dp[i] ： 第i个位置前的最长上升子序列的元素的个数
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int result = 0;
		if (nums.size() == 0) return 0;
		vector<int> dp(nums.size(), 1);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			result = max(result, dp[i]);
		}
		return result;
	}
};
//法2：dp + 二分查找
//    利用vector<int> tails 来记录部分最长上升子序列（不是所有的），其长度为最长上升在子序列的长度
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int result = 0;
		if (nums.size() == 0) return 0;
		vector<int> tails;
		tails.push_back(nums[0]);
		int end = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > tails[end]) {
				tails.push_back(nums[i]);
				end++;
			}
			else {
				int left = 0;
				int right = end;
				while (left < right) {
					int mid = (left + right) >> 1;
					if (tails[mid] < nums[i]) {
						left = mid + 1;
					}
					else {
						right = mid;
					}
				}
				tails[left] = nums[i];
			}
		}
		return end + 1;
	}
};