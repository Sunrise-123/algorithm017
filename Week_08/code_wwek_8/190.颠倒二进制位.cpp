//˼·���൱�ڰ�0λ�ŵ�31λ
//            1 <---> 30
//            2 <---> 29...
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int result = 0;
		for (int i = 0; i < 32; i++) {
			result = (result << 1) + (n & 1);
			n >>= 1;
		}
		return result;
	}
};