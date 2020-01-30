// 완전탐색문제 BFS + STL 사용

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
struct Node
{
	int front, rear;
	Node(int front, int rear) :front(front), rear(rear){}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int testCase; 
	cin >> testCase;
	for (int t = 1; t <= testCase; t++) {
		cin >> N;
		vector<Node> v;
		for (int i = 0; i < N; i++) {
			int front, rear;
			cin >> front >> rear;
			v.push_back(Node(front, rear));
		}

		vector<Node> result;
		for (int i = 0; i < N; i++) {
			queue<Node> q;
			vector<Node> temp;
			q.push(v[i]);
			temp.push_back(v[i]);
			bool visited[101];
			for (int j = 0; j <= 100; j++) visited[j] = 0;
			visited[i] = true;
			while (!q.empty()) {
				Node n = q.front(); q.pop();
				for (int j = 0; j < N; j++) {
					if (visited[j]) continue;
					if (n.rear == v[j].front) {
						visited[j] = true;
						q.push(v[j]);
						temp.push_back(v[j]);
					}
				}
			}
			if (temp.size() > result.size()) result = temp;
		}
		cout << "#" << t << " ";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i].front << " " << result[i].rear << " ";
		}
		cout << endl;
	}
	return 0;
}