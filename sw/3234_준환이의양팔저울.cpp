#include<iostream>
#include <vector>
using namespace std;

int n, ret, sum, num[9];
bool visited[9];
int exp[] = { 1,2,4,8,16,32,64,128,256,512 };
int factorial[] = { 0,1,2,6,24,120,720,5040,40320,362880 };

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void dfs(int cnt, int left, int right) {
	if (cnt == n) {
		ret++;
		return;
	}
	if (left >= sum - left) {
		ret = ret + exp[n - cnt] * factorial[n - cnt];
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		dfs(cnt + 1, left + num[i], right);

		if (right + num[i] <= left) dfs(cnt + 1, left, right + num[i]);
		visited[i] = false;
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
		sum = 0;
		mem_set(visited, 0, sizeof(visited));

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			sum += num[i];
		}

		dfs(0, 0, 0);

		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}