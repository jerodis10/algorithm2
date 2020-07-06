#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n;
int map[21][21];
int dy[] = { 0,-1,0,1 };
int dx[] = { -1,0,1,0 };

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void move(int y, int x, int dir) {
	int curY = y, curX = x;
	int ny = y, nx = x;
	for (int i = 0; i < n - 1; i++) {
		ny += dy[dir];
		nx += dx[dir];
		if (map[curY][curX] != 0) {
			if (map[ny][nx] != 0) {
				if (map[curY][curX] == map[ny][nx]) {
					map[curY][curX] *= 2;
					map[ny][nx] = 0;
					curY += dy[dir];
					curX += dx[dir];
				}
				else {
					curY += dy[dir];
					curX += dx[dir];
					if (ny != curY || nx != curX) {
						map[curY][curX] = map[ny][nx];
						map[ny][nx] = 0;
					}
				}
			}
		}
		else {
			if (map[ny][nx] != 0) {
				map[curY][curX] = map[ny][nx];
				if (ny != curY || nx != curX) {
					map[ny][nx] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int testCase = 1; testCase <= tc; testCase++) {
		n = 0;
		mem_set(map, 0, sizeof(map));
		char str[20];
		cin >> n >> str;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		if (str[0] == 'l') for (int i = 0; i < n; i++) move(i, 0, 2);
		else if (str[0] == 'r') for (int i = 0; i < n; i++) move(i, n - 1, 0);
		else if (str[0] == 'u') for (int i = 0; i < n; i++) move(0, i, 3);
		else if (str[0] == 'd') for (int i = 0; i < n; i++) move(n - 1, i, 1);

		cout << "#" << testCase << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}