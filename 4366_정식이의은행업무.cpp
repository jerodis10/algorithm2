#include<iostream>
#include<string>
using namespace std;

int ret;
string n, m;

int solve(int i, int j) {
	if (n[i] == 1) n[i] = 0;
	else n[i] = 1;
	if (m[j] == 1) m[j] = 0;
	else m[j] = 1;

	int num1 = 0, num2 = 0;
	for (int i = n.size() - 1; i <= 0; i++) {
		if (i == 0 && n[i] == 1) num1 += 1;
		int temp = 1;
		if (n[i] == 1) {
			for (int j = 0; j < i; j++) {
				temp *= 2;
			}
			num1 += temp;
		}
	}
	for (int i = m.size() - 1; i <= 0; i++) {
		if (i == 0 && n[i] == 1) num2 += 1;
		int temp = 1;
		if (m[i] == 1) {
			for (int j = 0; j < i; j++) {
				temp *= 3;
			}
			num2 += temp;
		}
	}

	if (num1 == num2) { return 1; ret = num1; }
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;

		for (int i = 0; i < n.size(); i++) {
			for (int j = 0; j < m.size(); j++) {
				if (solve(i, j)) break;
			}
		}



		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}