#include<stdio.h>
#include<string.h>

int map[16][16];
int visited[16][16];
int startY, startX, targetY, targetX;
int dirY[4] = { -1,0,1,0 };
int dirX[4] = { 0,1,0,-1 };
int res;

void search(int nowY, int nowX) {
	visited[nowY][nowX] = 1;
	if (nowY == targetY && nowX == targetX) {
		res = 1;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int newY, newX;
		newY = nowY + dirY[i];
		newX = nowX + dirX[i];
		if (newY < 16 && newX < 16 && (map[newY][newX] == 0 || map[newY][newX] == 3)
			&& visited[newY][newX] == 0)
		search(newY, newX);
	}
}

int main(){
	int testCase;
	for (int t = 1; t <= 10; t++) {
		scanf("%d", &testCase);
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					startY = i;
					startX = j;
				}
				else if (map[i][j] == 3) {
					targetY = i;
					targetX = j;
				}
			}
		}

		search(startY, startX);
		
		printf("#%d %d\n", testCase, res);
		res = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}
	
