#include<iostream>
#include<cstdio>
#define MAX 1003
using namespace std;

int p[MAX][MAX], n[MAX][MAX], q[MAX * MAX];
bool check[MAX];
int T, V, E;

void bfs() {
	int st, ed, ipos, npos;
	st = ed = -1;
	for(int i=1;i<=V;i++)
		if (!p[i][0]) { q[++st] = 1; }
	while (st != ed) {
		ipos = q[++ed];
		check[ipos] = true;
		printf("%d", ipos);
		for (int i = 1; i <= npos[ipos][0]; i++) {
			int flag = 0;
			npos = n[ipos][i];
			for (int j = 1; j <= p[npos][0]; j++) {
				if (!check[p[npos][j]]) { flag = 1; break; }
			}
			if (flag) continue;
			q[++st] = npos;
		}
	}
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		cin >> V >> E;
		for (int i = 0; i <= V; i++) {
			check[i] = false;
			n[i][0] = p[i][0] = 0;
		}
		for (int i = 0; i <= E; i++) {
			int a, b;
			cin >> a >> b;
			n[a][++n[a][0]] = b;
			p[b][++p[b][0]] = a;
		}
		printf("#%d ", tc);
		bfs();
		cout << endl;
		
	}
	 
	return 0;
}