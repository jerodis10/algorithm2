#include<iostream>
using namespace std;

int n, ret, ret_num;
int map[1000][1000];
int move_num[1000][1000];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

int dfs(int y, int x) {
	if (move_num[y][x] != -1) return move_num[y][x];

	move_num[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
			if (map[ny][nx] - map[y][x] == 1) {
				move_num[y][x] = move_num[y][x] + dfs(ny, nx);
			}
		}
	}
	return move_num[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ret = 0;
		mem_set(move_num, -1, sizeof(move_num));

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int temp = dfs(i, j);
				if (ret < temp) {
					ret = temp;
					ret_num = map[i][j];
				} 
				else if (ret == temp) {
					if (ret_num > map[i][j]) ret_num = map[i][j];
				}
			}
		}

		cout << "#" << t << " " << ret_num << " " << ret << endl;
	}

	return 0;
}