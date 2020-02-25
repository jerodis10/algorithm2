#include<iostream>
using namespace std;

int main() {
	int T;
	int n, m, y, x;
	long long res;

	cin >> T;

	for (int testCase = 1; testCase <= T; testCase++) {
		res = 1;
		cin >> n >> m;
		x = n / m;
		y = n % m;
	
		for (int i = 0; i < m - y; i++) {
			res *= x;
		}
		x++;

		for (int i = 0; i < y; i++) {
			res *= x;
		}

		cout << "#" << testCase << " " << res << "\n";
	}
	return 0;
}