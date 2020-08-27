#include <iostream>
using namespace std;

static int grid[1000][1000];
static int N, M;

static int dr[]{ -2, 2, 0, 0 };
static int dc[]{ 0, 0, -2, 2 };

int get_max_count() {
    int cnt = 0;
    for (int r = 0; r < M; ++r) {
        for (int c = 0; c < N; ++c) {
            if (grid[r][c] == 0) {
                cnt++;
                grid[r][c] = 1;
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (0 <= nr && nr < M && 0 <= nc && nc < N) {
                        grid[nr][nc] = -1;
                    }
                }
            }
        }
    }
    return cnt;
};

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> M;
        for (int r = 0; r < M; ++r) {
            for (int c = 0; c < N; ++c) {
                grid[r][c] = 0;
            }
        }
        cout << "#" << tc << " " << get_max_count() << endl;
    }
    return 0;
}