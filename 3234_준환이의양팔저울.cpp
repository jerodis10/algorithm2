#include<iostream>
#include <vector>
using namespace std;

int n, ret, num[9];
int map[2][9];
int visited[9];
vector<int> v;

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void dfs(int sq) {
	if (sq == n) {
		int right = 0;
		int left = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0) right += map[i][j];
				else left += map[i][j];
			}
		}
		if (right <= left) ret++;
		/*for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		for (int j = 0; j < 2; j++) {
			map[j][sq] = num[i];
			visited[i] = 1;
			dfs(sq + 1);
			map[j][sq] = 0;
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		ret = 0;
		mem_set(map, 0, sizeof(map));
		mem_set(visited, 0, sizeof(visited));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			v.push_back(num[i]);
		}

		dfs(0);

		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}