#include<iostream>
using namespace std;

bool map[11][11];
bool visited[11];
int maxcnt;
int n, m;

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void dfs(int root, int x) {
	visited[root] = 1;
	if (maxcnt < x) maxcnt = x;
	for (int i = 1; i <= n; i++) {
		if (root != i && map[root][i] && !visited[i]) {
			dfs(i, x + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		mem_set(map, 0, sizeof(map));
		mem_set(visited, 0, sizeof(visited));

		cin >> n >> m;

		if (m == 0) {
			cout << "#" << tc << 1 << endl;
			continue;
		}

		for (int j = 0; j < m; j++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
			map[y][x] = 1;
		}

		maxcnt = 0;
		for (int j = 1; j <= n; j++) {
			mem_set(visited, 0, sizeof(visited));
			dfs(j, 1);
		}

		cout << "#" << tc << " " << maxcnt << endl;
	}
}