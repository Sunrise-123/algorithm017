class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = !nums.empty();
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] != nums[i - 1]) {
				nums[i++] = nums[j];
			}
		}
		return i;
	}
};