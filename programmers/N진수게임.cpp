#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> v;
string number[] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
string ret = "";

void convertNum(int num, int n) {
	if (num < n) {
		v.push_back(number[num % n]);
	}
	else {
		convertNum(num / n, n);
		v.push_back(number[num % n]);
	}
}

string solution(int n, int t, int m, int p) {
	for (int i = 0; i < t * m; i++) {
		convertNum(i, n);
	}

	// for (int i = 1; i <= v.size(); i++) {
	// 	if(i % m == (m - p)) ret += v[i - 1];
	// 	if (ret.size() == t) break;
	// }

	int q = p - 1;
	for (int i = 0; i < t; i++) {
		ret += v[q];
		q += m;
	}

	return ret;
}


//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int n, t, m, p;
//string number[]= { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
//vector<string> v;
//string ret = "";
//
//void convertNum(int num) {
//	if (num < n) {
//		v.push_back(number[num % n]);
//	}
//	else {
//		convertNum(num / n);
//		v.push_back(number[num % n]);
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> t >> m >> p;
//
//	for (int i = 0; i < t*m; i++) {
//		convertNum(i);
//	}
//
//	int q = p - 1;
//	for (int i = 0; i < t; i++) {
//		ret += v[q];
//		q += m;
//	}
//
//	cout << ret << endl;
//
//	return 0;
//}