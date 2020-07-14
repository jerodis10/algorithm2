#include<iostream>
#include<vector>
using namespace std;

int t, ret;
int n, b;
int num[21];
bool visited[21];
vector<int> v;

void dfs(int index, int cnt) {
	if (cnt > n) return;

	int sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += v[i];
	}
	if (ret > sum && b <= sum) ret = sum;

	for (int i = index; i < n; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		v.push_back(num[i]);
		dfs(i, cnt + 1);
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int testCase = 1; testCase <= tc; testCase++) {
		ret = 987654321;
		cin >> n >> b;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		dfs(0, 0);

		cout << "#" << testCase << " " << ret - b << endl;
	}

	return 0;
}
