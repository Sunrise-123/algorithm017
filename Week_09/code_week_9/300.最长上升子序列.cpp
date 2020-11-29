//��1����̬�滮 O(n^2)
//    dp[i] �� ��i��λ��ǰ������������е�Ԫ�صĸ���
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
//��2��dp + ���ֲ���
//    ����vector<int> tails ����¼��������������У��������еģ����䳤��Ϊ������������еĳ���
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