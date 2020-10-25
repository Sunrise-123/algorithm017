//
//��1����С����
//    ����ÿ�д�����������ÿ�е�һԪ�ش�����һ�����һ��Ԫ��
//    ���Կ��Դ����½ǲ鵽���Ͻǣ��ҵ�Ŀ��ֵ��
// ʱ�临�Ӷȣ�O(m+n)
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int row = matrix.size() - 1, col = 0;
		while (row >= 0 && col < matrix[0].size()) {
			if (matrix[row][col] > target) row--;
			else if (matrix[row][col] < target) col++;
			else return true;
		}
		return false;
	}
};
// ��2�����ֲ��ҷ�
//     ����ά����ת��Ϊһά���飬Ȼ����ж�ά����
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int left = 0, right = matrix.size() * matrix[0].size() - 1;
		int n = matrix[0].size();
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (matrix[mid / n][mid % n] > target) right = mid - 1;
			else if (matrix[mid / n][mid % n] < target) left = mid + 1;
			else return true;
		}
		return false;
	}
};