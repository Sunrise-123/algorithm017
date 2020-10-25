// ˼·��
// 1. ȷ�����ߵķ���
// 2. ��������
// 3. �ϰ������жϡ�

class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		if (commands.empty()) return 0;
		int dire_x[] = { 0, 1, 0, -1 };
		int dire_y[] = { 1, 0, -1, 0 };
		int curx = 0, cury = 0, curdir = 0;
		int result = 0;
		// �������ϰ������ڼ�����
		set<pair<int, int>> obstacleSet;
		for (int i = 0; i < obstacles.size(); i++) {
			obstacleSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));
		}
		//
		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == -1) {
				curdir = (curdir + 1) % 4; //����ת
			}
			else if (commands[i] == -2) {
				curdir = (curdir + 3) % 4; //����ת
			}
			else {
				// ��ǰ��X��λ
				for (int j = 0; j < commands[i]; j++) {
					// ��ͼ��ǰ��һ��
					int nx = curx + dire_x[curdir];
					int ny = cury + dire_y[curdir];
					// �ж��Ƿ������ϰ���
					if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
						//δ�����ϰ���
						curx = nx;
						cury = ny;
						result = max(result, curx * curx + cury * cury);
					}
					else {
						break;
					}
				}
			}
		}
		return result;
	}
};