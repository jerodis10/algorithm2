// 완전탐색문제 DFS + STL 미사용

#include<iostream>
using namespace std;
int N;
bool visited[21];
struct Node {
	int front, int rear;
};
Node arr[21], result[21];

void mem_set(void* dest, int val, int size) {
	unsigned char* p = (unsigned char*)dest;
	while (size--) *p++ = val;
}

void dfs(int index, int count, Node temp[]) {
	if (count == N) {
		for (int i = 0; i < count; i++) result[i] = temp[i];
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		if (arr[index].rear == arr[i].front) {
			visited[i] = true;
			temp[count] = arr[i];
			dfs(i, count + 1, temp);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	int testCase; 
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		cin >> N;
		mem_set(result, 0, sizeof(result));
		mem_set(arr, 0, sizeof(arr));
		for (int i = 0; i < N; i++) cin >> arr[i].front >> arr[i].rear;
		for (int i = 0; i < N; i++) {
			Node p[21];
			mem_set(p, 0, sizeof(p));
			mem_set(visited, 0, sizeof(visited));
			visited[i] = true;
			p[0] = arr[i];
			dfs(i, 1, p);
		}
		cout << "#" << t << " ";
		for (int i = 0; i < N; i++) cout << result[i].front << " " << result[i].rear << " ";
		cout << endl;
	}
	return 0;
}