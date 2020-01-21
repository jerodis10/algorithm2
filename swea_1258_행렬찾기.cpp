#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int r, c, mul;
    Node(int r, int c, int mul) :r(r), c(c), mul(mul) {}
};

int t, n;
int map[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y) {
    map[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];
        if (ax >= 0 && ay >= 0 && ax < n && ay < n && map[ax][ay] != 0) {
            dfs(ax, ay);
        }
    }
}

int compare_node(const Node& a, const Node& b) {
    if (a.mul == b.mul) {
        return a.r < b.r;
    }
    return a.mul < b.mul;
}

int main() {
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        vector<Node> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] != 0) {
                    int row_cnt = 1;
                    int col_cnt = 1;
                    int k = i + 1;
                    while (true) {
                        if (k >= 100 || map[k][j] == 0) break;
                        if (map[k][j] != 0) {
                            k++;
                            row_cnt++;
                        }
                    }
                    k = j + 1;
                    while (true) {
                        if (k >= 100 || map[i][k] == 0) break;
                        if (map[i][k] != 0) {
                            k++;
                            col_cnt++;
                        }
                    }
                    dfs(i, j);
                    v.push_back(Node(row_cnt, col_cnt, row_cnt * col_cnt));
                }
            }
        }

        sort(v.begin(), v.end(), compare_node);

        printf("#%d %d ", tc, v.size());
        for (int i = 0; i < v.size(); i++) {
            printf("%d %d ", v[i].r, v[i].c);
        }
        printf("\n");
    }
}
