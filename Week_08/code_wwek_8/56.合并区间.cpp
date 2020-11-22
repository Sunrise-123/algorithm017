//思路：先排序，后使用双指针
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> result;
		for (int i = 0; i < intervals.size();) {
			int temp = intervals[i][1];
			int j = i + 1;
			while (j < intervals.size() && intervals[j][0] <= temp) {
				temp = max(intervals[j][1], temp);
				j++;
			}
			result.push_back({ intervals[i][0], temp });
			i = j;
		}
		return result;
	}
};