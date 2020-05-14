#include <iostream>
using namespace std;

int t, n, ret;
int map[11][11];
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

void mem_set(void* dest, int val, int size) {
    unsigned char* p = (unsigned char*)dest;
    while (size--) *p++ = val;
}

void dfs(int y, int x, int depth) {
    if (depth > n) {
        ret++;
        return;
    }

    map[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y;
        int nx = x;
        while (1) {
            ny = y + dir[i][0];
            nx = x + dir[i][1];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
            map[ny][nx] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0) {
                dfs(i, j, depth + 1);
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        int ny = y;
        int nx = x;
        while (1) {
            ny = y + dir[i][0];
            nx = x + dir[i][1];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
            map[ny][nx] = 0;
        }
    }
}

int main() {
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        ret = 0;
        mem_set(map, 0, sizeof(map));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dfs(i, j, k);
                }
            }
        }

        cout << "#" << tc << " " << ret << endl;
    }

    return 0;
}