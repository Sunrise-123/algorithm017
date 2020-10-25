// 思路：若想尽可能多的分给孩子，那么最小的饼干应该分给胃口小的孩子
//      因此可以先对孩子的胃口和饼干两个数组进行排序，然后每个胃口去匹配相应的饼干
// 时间复杂度：O(NlogN)
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int child = 0;
		int cookie = 0;
		while (child < g.size() && cookie < s.size()) {
			if (g[child] <= s[cookie]) child++;
			cookie++;
		}
		return child;
	}
};