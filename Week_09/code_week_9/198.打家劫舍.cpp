// ��̬���̣� ÿһ�Ҷ���ѡ�Ͳ�ѡ����ѡ�񣬵����������Ҳ���ͬʱѡ��
//         ��ʼֵ��dp[0][0] = 0
//                dp[0][1] = nums[0]
//       ��̬���̣�dp[i][0] = max(dp[i-1][0], dp[i-1][1]) //��i����ѡ
//                dp[i][1] = dp[i-1][0] + nums[i]        // ��i��ѡ
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
// �Ż�����Ϊÿ�ζ�ֻ�õ�vector<int> dp �����һ����ֵ�����Կ���ֱ����������������
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