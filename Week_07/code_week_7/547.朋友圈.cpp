//法1：dfs
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int result = 0;
		vector<int> visited(M.size(), 0);
		for (int i = 0; i < M.size(); i++) {
			if (!visited[i]) {
				dfs(i, M, visited);
				result++;
			}
		}
		return result;
	}
private:
	void dfs(int indx, vector<vector<int>>& M, vector<int>& visited) {
		visited[indx] = 1;
		for (int j = 0; j < M.size(); j++) {
			if (M[indx][j] && !visited[j]) {
				dfs(j, M, visited);
			}
		}
	}
};
//法2：并查集。 (这个代码时间复杂度太高了， 需优化)
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int result = 0;
		int size = M.size();
		vector<int> parent(size, -1);
		//
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (M[i][j] == 1 && i != j) {
					union_(parent, i, j);
				}
			}
		}
		//统计
		for (int i = 0; i < size; i++) {
			if (parent[i] == -1) {
				result++;
			}
		}
		return result;
	}
private:
	int find(vector<int> parent, int x) {
		if (parent[x] == -1) return x;
		return find(parent, parent[x]);
	}
	void union_(vector<int>& parent, int x, int y) {
		int parent_x = find(parent, x);
		int parent_y = find(parent, y);
		if (parent_x != parent_y) {
			parent[parent_x] = parent_y;
		}
	}
};