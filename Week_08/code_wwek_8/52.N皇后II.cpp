//法1：DFS

//法2：位运算
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
			// 生成n位1
			int mask = (1 << n) - 1;
			//当前可以放入皇后的位置
			int bitMap = mask & ~(left | right | col);
			while (bitMap) {
				// 取最后一个1
				int bit = bitMap & -bitMap;
				// bitMap中被选到的那一位被置位0
				bitMap ^= bit;
				// drill down
				backTrack(row + 1, (left | bit) << 1, (right | bit) >> 1, col | bit, n, result);
			}
		}
	}
};