#include<iostream>
#include<vector>
using namespace std;

int t, ret;
int n, k, num[200];
bool visited[200];
vector<int> v;

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void dfs(int cnt) {
	if (cnt == k) {

		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		v.push_back(num[i]);
		dfs(cnt + 1);
		v.pop_back();
		visited[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int testCase = 1; testCase <= tc; testCase++) {
		ret = 0;
		mem_set(visited, false, sizeof(visited));
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		dfs(0);

		cout << "#" << testCase << " " << ret << endl;
	}

	return 0;
}