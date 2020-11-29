// ��̬�滮��ȡ����ֵ���������max_profit����С����ֵmin_cost
//         max_profit = max(��i-1��������󣬵�i��۸� - ��i-1����С�ɱ�)
//         min_cost = min(��i��۸� ��i-1�����С�۸�)
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