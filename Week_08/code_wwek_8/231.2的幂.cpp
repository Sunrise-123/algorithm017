//˼·�������2�Ĵ��ݣ�������Ƶ���ʽ��ֻ��һ��1
//     ���ԣ����ֻ��1��1������ n & n-1 == 0
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && (n & (n - 1)) == 0;
	}
};