#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, ret;
int n, k;
int num;
vector<int> camera, gap;

void solve() {
	sort(camera.begin(), camera.end());
	for (int i = 1; i < camera.size(); i++) {
		int diff = camera[i] - camera[i - 1];
		gap.push_back(diff);
	}

	sort(gap.begin(), gap.end());
	int size = gap.size();
	for (int i = 0; i < size - (k - 1); i++) {
		ret += gap[i];
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
		camera.clear();
		gap.clear();
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> num;
			camera.push_back(num);
		}

		solve();

		cout << "#" << testCase << " " << ret << endl;
	}

	return 0;
}