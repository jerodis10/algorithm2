#include<iostream>
#include<set>
using namespace std;

int num[100];
int num2[100];
int N;
set<int> ret;

void dfs(int depth, int index) {
	if (depth > N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if(num2[depth] == 1)
				sum += num[i];
		}
		ret.insert(sum);
		return;
	}
	if (index == 0) {
		num2[depth] = 0;
	}
	for (int i = 0; i < 2; i++) {
		dfs(depth + 1, i);
	}
}

int main() {
	int T;
	cin >> T >> N;
	for (int tc = 1; tc <= T; tc++) {
		ret.clear();
		for (int i = 0; i < N; i++) {
			cin >> num[i];
			num2[i] = 1;
		}
		for (int i = 0; i < 2; i++) {
			dfs(0, i);
		}

		cout << "#" << tc << " " << ret.size() << endl;
	}

	return 0;
}