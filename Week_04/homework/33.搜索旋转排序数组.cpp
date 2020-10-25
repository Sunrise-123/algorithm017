// 思路：1. 有序数组；2.找到转折点。
//      即：将旋转数组中找转折点 转为 再有序数组中找转折点 问题

// 法1：二分查找
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return mid;
			//nums[lo]与nums[mid]做比较，缩小搜索范围
			if (nums[mid] >= nums[lo]) {
				if (nums[lo] <= target && target < nums[mid]) {
					hi = mid - 1;
				}
				else {
					lo = mid + 1;
				}
			}
			else {
				if (target > nums[mid] && target <= nums[hi]) {
					lo = mid + 1;
				}
				else {
					hi = mid - 1;
				}
			}
		}
		return -1;
	}
};
// 法2：参考国际版的方法
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return mid;
			//先根据target 与nums[0]的关系，确定在左半段还是右半段
			if (target >= nums[0]) {
				// 目标值在左半段，左半段设置为INT_MAX
				if (nums[0] > nums[mid]) {
					nums[mid] = INT_MAX;
				}
			}
			else {
				// 目标值在右半段
				if (nums[0] <= nums[mid]) {
					nums[mid] = INT_MIN;
				}
			}
			//
			if (nums[mid] >= target) {
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		return -1;
	}
};