// 思路：
// 1. 确定行走的方向；
// 2. 调整方向；
// 3. 障碍区的判断。

class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		if (commands.empty()) return 0;
		int dire_x[] = { 0, 1, 0, -1 };
		int dire_y[] = { 1, 0, -1, 0 };
		int curx = 0, cury = 0, curdir = 0;
		int result = 0;
		// 将所有障碍区放在集合中
		set<pair<int, int>> obstacleSet;
		for (int i = 0; i < obstacles.size(); i++) {
			obstacleSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));
		}
		//
		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == -1) {
				curdir = (curdir + 1) % 4; //向右转
			}
			else if (commands[i] == -2) {
				curdir = (curdir + 3) % 4; //向左转
			}
			else {
				// 向前走X单位
				for (int j = 0; j < commands[i]; j++) {
					// 试图向前走一步
					int nx = curx + dire_x[curdir];
					int ny = cury + dire_y[curdir];
					// 判断是否遇到障碍区
					if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
						//未遇到障碍区
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