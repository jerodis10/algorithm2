#include <iostream>
using namespace std;

typedef long long ll;
int testCase, n, m;
ll ret, maxNum;
ll counter[100001];

int main() {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> testCase;
    for (int t = 1; t <= testCase; t++) {
        ret = 0;
        maxNum = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> counter[i];
            if (counter[i] > maxNum) maxNum = counter[i];
        }
        
        ll left = 0;
        ll right = (ll)(maxNum * m);
        ll mid, sum;
        ret = right;

        while (left <= right) {
            sum = 0;
            mid = (left + right) / 2; 
            for (int i = 0; i < n; i++) sum = sum + (mid / counter[i]);

            if (sum < m) left = mid + 1;
            else {
                ret = mid;
                right = mid - 1;
            }
        }

        cout << "#" << t << " " << ret << "\n";
    }

    return 0;
}