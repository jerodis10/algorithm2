#include <iostream>

using namespace std;

int testcase;
int n, ans;


int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        cin >> n;

        

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}