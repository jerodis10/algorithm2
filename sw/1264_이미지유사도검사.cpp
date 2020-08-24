// LCS 알고리즘 문제
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++) {
		int dp[502][502] = { 0 };
		int len;
		cin >> len;
		string X;
		string Y;
		cin >> X >> Y;
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= len; j++) {
				if (X[i - 1] == Y[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		double sol = (double)dp[len][len] / (double)len * 100;
		printf("#%d %.2f\n", testCase, sol);
	}
	return 0;
}