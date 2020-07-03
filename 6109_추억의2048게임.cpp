#include<iostream>
using namespace std;

int s, t, a, b, ret;
int n, m;

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void dfs(int cnt, int num) {
	if (cnt > m) {
		ret = -1;
		return;
	}
	if (num > t) return;
	if (num == t) {
		ret++;
		return;
	}

	dfs(cnt + 1, num * a);
	dfs(cnt + 1, num + b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int testCase = 1; testCase <= tc; testCase++) {
		n = 0;
		m = 0;
		ret = 0;

		cin >> s >> t >> a >> b;

		int temp = s;
		while (temp <= t)
		{
			temp += b;
			m++;
		}

		dfs(0, s);
		if (ret == 0) ret = -1;

		cout << "#" << testCase << " " << ret << endl;
	}

	return 0;
}