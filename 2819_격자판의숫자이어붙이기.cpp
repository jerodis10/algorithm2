#include<iostream>
#include<set>
using namespace std;

int map[4][4];
int number[7];
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int ny, nx;
set<int> ret;

void dfs(int y, int x, int depth) {
	if (depth == 7) {
		int num = 0;
		for (int i = 0; i < 7; i++) {
			num = num * 10 + number[i];
		}
		ret.insert(num);
		return;
	}
	number[depth] = map[y][x];
	for (int i = 0; i < 4; i++) {
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;
		dfs(ny, nx, depth + 1);
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ret.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs(i, j, 0);
			}
		}

		cout << "#" << tc << " " << ret.size() << endl;
	}
	 
	return 0;
}