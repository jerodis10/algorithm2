#include<iostream>
using namespace std;

int n, x, y;
int room[401];
Node student[401];
int path[201];

struct Node {
	int from, int to;
};

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned*)dest;
	while (size--) *p++ = val;
}

void dfs(int depth) {
	if (depth > n) return;
	if (student[depth] % 2 == 1) {
		int from = (student[depth].from / 2) + 1;
		int to = (student[depth].to / 2) + 1;
		for (int i = from; i <= to; i++) {
			path[i] = 1;
		}
	}
	else {

	}
}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			student[i].from = x;
			student[i].to = y;
		}
		for (int i = 0; i < n; i++) {
			dfs(i);
		}
		cout << "#" << tc << " " << ans << endl;
	}
}