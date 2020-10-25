//思路：1.数组为升序数组
//     2.转折点的左半部分和右半部分均为升序排列
//     3.数组中不存在重复元素
//分析：1.要求找最小值，而最小值在一段升序排列中是靠近左边的.
//       因此，要比较nums[mid]与nums[right]
//     2.用left来保存最小值，因此终止条件为:left<right
//	   3. 若要比较nums[mid]与nums[left]来获取最小值，可以先获取最大值之后，在此index基础上加1即可获取最小值
//

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < nums[right]) {
				right = mid;
			}
			else if (nums[mid] > nums[right]) {
				left = mid + 1;
			}
		}
		return nums[left];
	}
};