//思路：如果是2的次幂，则二进制的形式里只有一个1
//     所以，如果只有1个1，则在 n & n-1 == 0
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && (n & (n - 1)) == 0;
	}
};