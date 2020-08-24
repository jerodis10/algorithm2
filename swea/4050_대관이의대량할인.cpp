#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int testCase, n, ret, sum;
int num[100001];

void mem_set(void* dest, int val, int size) {
    unsigned char* p = (unsigned char*)dest;
    while (size--) *p++ = val;
}

bool cmp(int a, int b) {
    if (a > b) return true;
    return false;
}

int main(int argc, const char* argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> testCase;
    for (int t = 1; t <= testCase; t++) {
        mem_set(num, 0, sizeof(num));
        sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
            sum += num[i];
        }
        sort(num, num + n, cmp);
        for (int i = 0; i < n; i = i + 3) {
            sum -= num[i + 2];
        }
        ret = sum;


        cout << "#" << t << " " << ret << "\n";
    }

    return 0;
}