#include<iostream>
#include<string>
using namespace std;

typedef long long ll;

int ret;
string n, m;
string ori_n, ori_m;

int solve(int a, int b) {
	string t[2];
	t[0] = m;
	t[1] = m;
	if (n[a] == '1') n[a] = '0';
	else n[a] = '1';

	int num1 = 0, num2 = 0;
	int n_len = n.length();
	int m_len = m.length();
	for (int i = 0; i < n_len; i++) {
		if (i == n_len - 1 && n[i] == 1) num1 += 1;
		int temp = 1;
		if (n[i] == '1') {
			for (int j = i; j < n_len - 1; j++) {
				temp *= 2;
			}
			num1 += temp;
		}
	}
	for (int cnt = 0; cnt < 2; cnt++) {
		if (t[b][cnt] == '0') t[b][cnt] = '1';
		else if (t[b][cnt] == '1') t[b][cnt] = '2';
		else t[b][cnt] = '0';
		for (int i = 0; i < m_len; i++) {
			if (i == m_len - 1 && t[b][cnt] == '0') num2 += 1;
			int temp = 1;
			if (t[b][cnt] == '1') {
				for (int j = i; j < m_len - 1; j++) {
					temp *= 3;
				}
				num2 += temp;
			}
			if (t[b][cnt] == '2') {
				for (int j = i; j < m_len - 1; j++) {
					temp *= 3;
				}
				temp *= 2;
				num2 += temp;
			}
		}
	}

	if (num1 == num2) { ret = num1; return 1; }
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
		ori_n = n;
		ori_m = m;
		ret = 0;
		for (int i = 0; i < n.size(); i++) {
			for (int j = 0; j < m.size(); j++) {
				if (solve(i, j)) break;
				n = ori_n;
				m = ori_m;
			}
		}

		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}