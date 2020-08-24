#include<iostream>
#include<set>
using namespace std;

int t, ret;
int n, num, max_num;
int map[100][100];
bool visited[100][100];
int dy[] = { 0,-1,0,1 };
int dx[] = { -1,0,1,0 };
set<int> s;

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void count(int y, int x) {
	if (visited[y][x] == true || map[y][x] == 0) return;
	visited[y][x] = true;

	for (int k = 0; k < 4; k++) {
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
			count(ny, nx);
		}
	}
}

void dfs(int cnt) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == cnt) {
				map[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}

	num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && !visited[i][j]) {
				count(i, j);
				num++;
			}
		}
	}

	if (num > ret) ret = num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int testCase = 1; testCase <= tc; testCase++) {
		ret = 1;
		max_num = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				s.insert(map[i][j]);
			}

		set<int>::iterator iter;
		for (iter = s.begin(); iter != s.end(); iter++) {
			mem_set(visited, false, sizeof(visited));
			dfs(*iter);
		}

		cout << "#" << testCase << " " << ret << endl;
	}

	return 0;
}
