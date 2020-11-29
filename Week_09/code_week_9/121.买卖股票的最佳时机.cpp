// 动态规划：取两个值，最大利润max_profit、最小买入值min_cost
//         max_profit = max(第i-1天最大利润，第i天价格 - 第i-1天最小成本)
//         min_cost = min(第i天价格， 第i-1天的最小价格)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int max_profit = 0;
		int min_cost = prices[0];
		for (int i = 0; i < prices.size(); i++) {
			max_profit = max(max_profit, prices[i] - min_cost);
			min_cost = min(min_cost, prices[i]);
		}
		return max_val;
	}
};