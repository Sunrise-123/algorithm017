//Tri
// 注：这个效率有点低，需要优化
class TriNode {
public:
	string word = "";
	vector<TriNode*> nodes;
	TriNode() :nodes(26, 0) {}
};
class Solution {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int row = board.size();
		int col = row ? board[0].size() : 0;
		vector<string> result;
		if (row == 0 || col == 0) return result;

		// 将words构建成Tri
		TriNode* root = new TriNode();
		for (string word : words) {
			TriNode* curNode = root;
			for (int i = 0; i < word.length(); i++) {
				int indx = word[i] - 'a';
				if (curNode->nodes[indx] == 0) {
					curNode->nodes[indx] = new TriNode();
				}
				curNode = curNode->nodes[indx];
			}
			curNode->word = word;
		}
		//DFS遍历，查找
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				dfs(i, j, board, root, result);
			}
		}
		return result;
	}
private:
	void dfs(int row, int col, vector<vector<char>>& board, TriNode* root, vector<string>& result) {
		char c = board[row][col];
		//ternimator
		if (c == '.' || root->nodes[c - 'a'] == 0) return;
		root = root->nodes[c - 'a'];
		if (root->word != "") {
			result.push_back(root->word);
			root->word = "";
			return;
		}

		//process
		board[row][col] = '.';
		for (int i = 0; i < 4; i++) {
			int m = row + dx[i];
			int n = col + dy[i];
			if (m >= 0 && m < board.size() && n >= 0 && n < board[0].size() && ) {
				// drill down
				dfs(m, n, board, root, result);
			}
		}
		//reverse
		board[row][col] = c;
	}
};