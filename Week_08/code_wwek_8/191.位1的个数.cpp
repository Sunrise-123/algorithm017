//法1： 位运算
//     x & x-1 -->获取最低位的1
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n != 0) {
			count++;
			n = n & n - 1;
		}
		return count;
	}
};
//法2：将n转换位二进制形式，统计1的个数
//法3：先 n&1 ,再 n>>1