// ˼·�����������գ�׬Ǯ���������ӣ������½��գ���Ǯ
//      ��ˣ����������գ���������������������
//           �����½��գ������������Ҳ���������
// ʱ�临�Ӷȣ�o(N)
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