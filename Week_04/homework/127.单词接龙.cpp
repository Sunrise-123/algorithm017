//思路： BFS
//      无向图的最短问题，可以用BFS
//复杂度：O(26 * wordlength)
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// 1.把wordList里的单词放在set里，便于查找单词是否在其中
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (dict.size() == 0 || (dict.find(endWord) == dict.end())) return 0;
		// 2. 图的遍历，需要使用队列以及表示是否visited的set
		queue<string> todo;
		todo.push(beginWord);
		unordered_set<string> visited;
		visited.insert(beginWord);
		//3. bfs
		int step = 1;
		while (!todo.empty()) {
			int currentSize = todo.size();
			//遍历当前Queue
			for (int i = 0; i < currentSize; i++) {
				string currentWord = todo.front();
				todo.pop();
				// 当前的word == endWord
				if (currentWord == endWord) return step;
				// // 若当前word修改一个字符就可得到endword,则返回step+1
				if (changeEveryOneLetter(currentWord, endWord, todo, visited, dict)) {
					return step + 1;
				}
			}
			step++;
		}
		return 0;
	}
private:
	bool changeEveryOneLetter(string currentword, string endword, queue<string>& todo, unordered_set<string>& visited, unordered_set<string>& dict) {
		for (int i = 0; i < currentword.size(); i++) {
			//保存当前的字符，便于后续的恢复
			char orgChar = currentword[i];
			for (char c = 'a'; c <= 'z'; c++) {
				if (c == orgChar) continue;
				currentword[i] = c;
				if (dict.find(currentword) != dict.end()) {
					if (currentword == endword) {
						return true;
					}
					dict.erase(currentword);
					if (visited.find(currentword) == visited.end()) {
						todo.push(currentword);
						visited.insert(currentword);
					}
				}
			}
			// 恢复
			currentword[i] = orgChar;
		}
		return false;
	}
};