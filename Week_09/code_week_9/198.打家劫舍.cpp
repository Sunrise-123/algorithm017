// 动态方程： 每一家都有选和不选两种选择，但是相邻两家不能同时选择
//         初始值：dp[0][0] = 0
//                dp[0][1] = nums[0]
//       动态方程：dp[i][0] = max(dp[i-1][0], dp[i-1][1]) //第i个不选
//                dp[i][1] = dp[i-1][0] + nums[i]        // 第i个选
//
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int length = nums.size();
		vector<vector<int>> dp(length, vector<int>(2, 0));
		dp[0][0] = 0;
		dp[0][1] = nums[0];
		for (int i = 1; i < length; i++) {
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
			dp[i][1] = dp[i - 1][0] + nums[i];
		}
		return max(dp[length - 1][0], dp[length - 1][1]);

	}
};
// 优化：因为每次都只用到vector<int> dp 的最后一个数值，所以可以直接用两个变量代替
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int length = nums.size();
		int dp_0 = 0;
		int dp_1 = nums[0];
		for (int i = 1; i < length; i++) {
			int temp = max(dp_0, dp_1);
			dp_1 = dp_0 + nums[i];
			dp_0 = temp;
		}
		return max(dp_0, dp_1);

	}
};