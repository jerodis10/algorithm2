#include<iostream>
using namespace std;

int t, ret;
int r, c;
char map[20][20];
bool alphabet[26];
int dy[] = { 0,-1,0,1 };
int dx[] = { -1,0,1,0 };

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void dfs(int y, int x, int cnt) {
	if (ret < cnt) ret = cnt;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
			if (alphabet[map[ny][nx] - 'A'] == false) {
				alphabet[map[ny][nx] - 'A'] = true;
				dfs(ny, nx, cnt + 1);
				alphabet[map[ny][nx] - 'A'] = false;
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
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> map[i][j];
			}
		}

		ret = 0;
		mem_set(alphabet, false, sizeof(alphabet));

		alphabet[map[0][0] - 'A'] = true;
		dfs(0, 0, 1);

		cout << "#" << testCase << " " << ret << endl;
	}

	return 0;
}