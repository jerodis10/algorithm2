#include<iostream>
#include<string>
using namespace std;

int n;
int ret = 0;
string map[300];
int visited[300][300];
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void solve(int y, int x) {
	if (visited[y][x] == 0) return;
	visited[y][x] = 1;
	for (int i = 0; i < 8; i++) {
		int cnt = 0;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 300 || nx < 0 || nx >= 300) continue;
		if (map[ny][nx] == '*') return; 
		else if(map[ny][nx] == '.'){
			map[y][x] = '0';
			solve(ny, nx);
		}
	}
}

void start(int y, int x) {
	if (map[y][x] == '*') return;
	int start_y, start_x, ny, nx;
	for (int i = 0; i < 8; i++) {
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || ny >= 300 || nx < 0 || nx >= 300) continue;
		if (map[ny][nx] == '*') return;
	}
	//start_y = ny;
	//start_x = nx;

	solve(y, x);
	ret++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ret = 0;
		mem_set(visited, 0, sizeof(visited));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				start(i, j);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == '.') ret++;
			}
		}

		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}