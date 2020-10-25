//˼·�������Ϊ���������
//    1. �����λ��������(M)����λ����Ϊ��X������Ϸ������
//    2. �����λ��������(E)����ʱ��Ϊ���������
//      (1) ��Χ�����ף�λ����Ϊ'B'����������Χ��ɢ����;
//      (2) ��Χ���ף��õ��λ����ʾ����:1-8��
//
//��1��dfs
class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		//����8������
		vector<vector<int>> dir = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1, 1 },{ -1, -1 } };
		//������к���
		int row = click[0], col = click[1];
		if ('M' == board[row][col]) {
			// �����λ�ã�����
			board[row][col] = 'X';
		}
		else {
			//�����λ�ã�����,��Ҫ������Χ��8��λ��
			dfs(board, row, col, dir);
		}
		return board;
	}
private:
	void dfs(vector<vector<char>>& board, int row, int col, vector<vector<int>> dir) {
		//terminator
		// ͳ�Ƹ�λ����Χ8��λ�õ��׵ĸ���
		int count = 0;
		for (int i = 0; i < 8; i++) {
			int x = row + dir[i][0];
			int y = col + dir[i][1];
			// �ж��±�ĺϷ��ԣ���ֹԽ��
			if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) continue;
			if ('M' == board[x][y]) {
				count++;
			}
		}
		// ����3����Χ8��λ�����ף��޸�Ϊ�׵ĸ���
		if (count > 0) {
			board[row][col] = '0' + count;
			return;
		}
		else {
			//����2����Χ8��λ�����ף�,��λ����Ϊ'B', ������������Χ��λ�ã�ֱ����Χ��'E'
			board[row][col] = 'B';
			for (int i = 0; i < 8; i++) {
				int x = row + dir[i][0];
				int y = col + dir[i][1];
				// �ж��±�ĺϷ��ԣ���ֹԽ��
				if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'E') continue;
				dfs(board, x, y, dir);
			}
		}
	}
};