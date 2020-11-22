//��1��DFS

//��2��λ����
class Solution {
public:
	int totalNQueens(int n) {
		int result = 0;
		backTrack(0, 0, 0, 0, n, result);
		return result;
	}
private:
	void backTrack(int row, int left, int right, int col, int n, int& result) {
		if (row == n) {
			++result;
			return;
		}
		else {
			// ����nλ1
			int mask = (1 << n) - 1;
			//��ǰ���Է���ʺ��λ��
			int bitMap = mask & ~(left | right | col);
			while (bitMap) {
				// ȡ���һ��1
				int bit = bitMap & -bitMap;
				// bitMap�б�ѡ������һλ����λ0
				bitMap ^= bit;
				// drill down
				backTrack(row + 1, (left | bit) << 1, (right | bit) >> 1, col | bit, n, result);
			}
		}
	}
};