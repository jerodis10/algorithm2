#include <iostream>
using namespace std;
const int MAX = 1e6;
int N;
int map[1001][1001];
bool visited[1001];
struct Queue {
	int buffer[MAX + 1];
	int head, tail, qsize;
	void init() { head = tail = qsize = 0; }
	void push(int data) { buffer[head] = data; head = (head + 1) % MAX; qsize++; }
	int pop() { int ret = buffer[tail]; tail = (tail + 1) % MAX; qsize--; return ret; }
	bool empty() { return head == tail; }
	int size() { return qsize; }
};
Queue q;
void mem_set(void* src, int val, int size) {
	unsigned char* p = (unsigned char*)src;
	while (size--) *p++ = val;
}
int bfs(int start) {
	q.init(); q.push(start);
	visited[start] = true;
	int sum = 0;
	int time = 1;
	while (!q.empty()) {
		int qsize = q.size();
		int count = 0;
		for (int level = 0; level < qsize; level++) {
			int next = q.pop();
			for (int i = 0; i < N; i++) {
				if (visited[i] || map[next][i] == 0) continue;
				q.push(i);
				visited[i] = true;
				count++;
			}
		}
		sum += (count * time);
		time++;
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tcase; cin >> tcase;
	for (int tc = 1; tc <= tcase; tc++) {
		mem_set(map, 0, sizeof(map));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int mnn = 1e9;
		for (int i = 0; i < N; i++) {
			mem_set(visited, 0, sizeof(visited));
			int ret = bfs(i);
			if (ret < mnn) mnn = ret;
		}
		cout << "#" << tc << " " << mnn << "\n";
	}
	return 0;
}