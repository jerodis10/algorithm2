#include<iostream>
#include<set>
using namespace std;

int t, ret;
int r, c;
char map[20][20];
bool visited[20][20];
int dy[] = { 0,-1,0,1 };
int dx[] = { -1,0,1,0 };
set<char> s;

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void dfs(int y, int x) {
	if (visited[y][x]) return;
	if (s.find(map[y][x]) == s.end()) return;

	visited[y][x] = true;
	s.insert(map[y][x]);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < r && nx >= 0 && nx < c) {
			dfs(ny, nx);
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
			cin >> map[i];
		}
		mem_set(visited, false, sizeof(visited));

		s.insert(map[0][0]);
		dfs(0, 0);

		ret = s.size();

		cout << "#" << testCase << " " << ret << endl;
	}

	return 0;
}