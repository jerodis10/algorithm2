#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char name[20000][51];
int idx[20000];

bool cmp(int l, int r) {
    if (strlen(name[l]) == strlen(name[r]))
        return (strcmp(name[l], name[r]) < 0);
    else return (strlen(name[l]) < strlen(name[r]));
}
int main() {
    //  freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%s", name[i]), idx[i] = i;
        sort(idx, idx + n, cmp);
        printf("#%d\n", tc);
        char none[51] = "";
        char* before = none;
        for (int i = 0; i < n; i++) {
            if (strcmp(before, name[idx[i]])) {
                printf("%s\n", name[idx[i]]);
                before = name[idx[i]];
            }
        }
    }
}