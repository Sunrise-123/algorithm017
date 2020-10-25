// ˼·��1. �������飻2.�ҵ�ת�۵㡣
//      ��������ת��������ת�۵� תΪ ��������������ת�۵� ����

// ��1�����ֲ���
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return mid;
			//nums[lo]��nums[mid]���Ƚϣ���С������Χ
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
// ��2���ο����ʰ�ķ���
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lo = 0, hi = nums.size() - 1;
		while (lo <= hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] == target) return mid;
			//�ȸ���target ��nums[0]�Ĺ�ϵ��ȷ�������λ����Ұ��
			if (target >= nums[0]) {
				// Ŀ��ֵ�����Σ���������ΪINT_MAX
				if (nums[0] > nums[mid]) {
					nums[mid] = INT_MAX;
				}
			}
			else {
				// Ŀ��ֵ���Ұ��
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