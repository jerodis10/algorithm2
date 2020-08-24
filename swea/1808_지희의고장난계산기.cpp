#include<iostream>
#include<vector>
using namespace std;

int t, ret, x;
int num[10];
int maxN = 0;
bool visited[10];
vector<int> selected;

int select(int m, int index, int cnt) {
	int sum = 0;
	if (cnt == maxN) {
		int cal = 1;
		for (int i = selected.size() - 1; i >= 0; i--) {
			if (i == selected.size() - 1) sum += selected[i];
			else {
				cal *= 10;
				sum += (selected[i] * cal);
			}

		}
		if (x > sum || (x % sum) != 0) return 0;
		else return sum;
	}

	for (int i = index; i < m; i++) {
		if (visited[i] == true) continue;
		visited[i] = true;
		selected.push_back(num[i]);
		select(m, i, cnt + 1);
		selected.pop_back();
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
		for (int i = 0; i < 10; i++) {
			cin >> num[i];
			if (num[i]) {
				num[i] = (i + 1);
				maxN++;
			}
		}
		cin >> x;

		int temp = x;
		for (int j = maxN; j >= 0; --j) {
			int sum = select(j, 0, 0);
			if (!sum) continue;
			temp = temp / sum;
		}


		cout << "#" << testCase << " " << ret << endl;
	}

	return 0;
}