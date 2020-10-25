//˼·�� BFS
//      ����ͼ��������⣬������BFS
//���Ӷȣ�O(26 * wordlength)
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		// 1.��wordList��ĵ��ʷ���set����ڲ��ҵ����Ƿ�������
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (dict.size() == 0 || (dict.find(endWord) == dict.end())) return 0;
		// 2. ͼ�ı�������Ҫʹ�ö����Լ���ʾ�Ƿ�visited��set
		queue<string> todo;
		todo.push(beginWord);
		unordered_set<string> visited;
		visited.insert(beginWord);
		//3. bfs
		int step = 1;
		while (!todo.empty()) {
			int currentSize = todo.size();
			//������ǰQueue
			for (int i = 0; i < currentSize; i++) {
				string currentWord = todo.front();
				todo.pop();
				// ��ǰ��word == endWord
				if (currentWord == endWord) return step;
				// // ����ǰword�޸�һ���ַ��Ϳɵõ�endword,�򷵻�step+1
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
			//���浱ǰ���ַ������ں����Ļָ�
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
			// �ָ�
			currentword[i] = orgChar;
		}
		return false;
	}
};