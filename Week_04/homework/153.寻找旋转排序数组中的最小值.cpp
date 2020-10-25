//˼·��1.����Ϊ��������
//     2.ת�۵����벿�ֺ��Ұ벿�־�Ϊ��������
//     3.�����в������ظ�Ԫ��
//������1.Ҫ������Сֵ������Сֵ��һ�������������ǿ�����ߵ�.
//       ��ˣ�Ҫ�Ƚ�nums[mid]��nums[right]
//     2.��left��������Сֵ�������ֹ����Ϊ:left<right
//	   3. ��Ҫ�Ƚ�nums[mid]��nums[left]����ȡ��Сֵ�������Ȼ�ȡ���ֵ֮���ڴ�index�����ϼ�1���ɻ�ȡ��Сֵ
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