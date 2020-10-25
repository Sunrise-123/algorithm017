//˼·��
// ������1. 0 < bill.length < 10000;
//       2. ֻ��5,10,20���֣���ÿ�ν���ֻ��5��Ԫ��
//       3. ��ʼʱû��Ǯ
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int m5 = 0, m10 = 0;
		for (int bill : bills) {
			switch (bill) {
			case 5: m5++; break;
			case 10: m5--; m10++; break;
			case 20: {
				if (m10 > 0) {
					m5--;
					m10--;
				}
				else {
					m5 -= 3;
				}
				break;
			}
			}
			if (m5 < 0) {
				return false;
			}
		}
		return true;
	}
};