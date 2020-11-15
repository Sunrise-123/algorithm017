//�ݹ�
class Solution {
public:
	int climbStairs(int n) {
		if (n < 3) return n;
		int f1 = 1, f2 = 2, f3 = 1;
		for (int i = 3; i <= n; i++) {
			f3 = f2 + f1;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
};