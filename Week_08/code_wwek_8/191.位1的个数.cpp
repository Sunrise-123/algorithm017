//��1�� λ����
//     x & x-1 -->��ȡ���λ��1
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
//��2����nת��λ��������ʽ��ͳ��1�ĸ���
//��3���� n&1 ,�� n>>1