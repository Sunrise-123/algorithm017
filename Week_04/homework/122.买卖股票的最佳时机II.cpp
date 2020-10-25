// 思路：连续上涨日，赚钱，利润增加；连续下降日，亏钱
//      因此，所有上涨日，均进行买卖，计入利润；
//           所有下降日，均不买卖，且不计入利润。
// 时间复杂度：o(N)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int profit = 0;
		for (int i = 1; i < prices.size(); i++) {
			int tmp = prices[i] - prices[i - 1];
			if (tmp > 0) profit += tmp;
		}
		return profit;
	}
};