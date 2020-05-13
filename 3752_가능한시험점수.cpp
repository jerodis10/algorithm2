#include<iostream>
#include<vector>
using namespace std;

int testCase, n;
int num[101];
bool visited[10001];

vector<int> v;

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

int solve() {
	v.push_back(0);
	visited[0] = true;

	for (int i = 0; i <= n; i++) {
		int len = (int)v.size() - 1;

		for (int j = len; j >= 0; j--) {
			int now = v[j];
			int next = now + num[i];

			if (!visited[next]) {
				v.push_back(next);
				visited[next] = true;
			}
		}
	}

	return (int)v.size();
}


int main() {
	cin >> testCase;
	for (int tc = 1; tc <= testCase; tc++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> num[i];
		}

		mem_set(visited, false, sizeof(visited));
		v.clear();

		cout << "#" << testCase << " " << solve() << endl;
	}

	return 0;
}