#include<iostream>
#include<algorithm>
using namespace std;

int t;
int n, k;
int num[200];
double ret;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int testCase = 1; testCase <= tc; testCase++) {
		ret = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		sort(num, num + n);
		for (int i = n - k; i < n; i++) {
			ret = (ret + num[i]) / 2;
		}

		cout << fixed;
		cout.precision(6);
		cout << "#" << testCase << " " << ret << endl;
	}

	return 0;
}
