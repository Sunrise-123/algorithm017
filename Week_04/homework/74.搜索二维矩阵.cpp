//
//法1：缩小领域法
//    由于每行从左到右是升序，每列第一元素大于上一行最后一个元素
//    所以可以从左下角查到右上角，找到目标值。
// 时间复杂度：O(m+n)
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
// 法2：二分查找法
//     将二维数组转换为一维数组，然后进行二维查找
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