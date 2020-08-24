#include<iostream>
#include<string>
using namespace std;

int map[51];

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int ans = 0;
		string s;
		cin >> s;
		
		if (s[0] == '1') ans++;

		for (int i = 1; i < s.size(); i++) {
			if (s[i - 1] == s[i]) {
				continue;
			}
			else {
				ans++;
			}
		}

		cout << "#" << tc << " " << ans << endl;
	}
}