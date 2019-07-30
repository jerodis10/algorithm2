#include <stdio.h>
#include <stack>
using namespace std;

int main(void) {
	for (int tcase = 1; tcase < 2; tcase++) {
		int n, tmp;
		stack<int> s, t;
		scanf_s("%d", &n);
		scanf_s("%1d", &tmp);
		//printf("a:%d ", tmp);
		s.push(tmp);
		//printf("%d", s.size());
		for (int i = 1; i < n; i++) {
			scanf_s("%1d", &tmp);
			//printf("b:%d ", tmp);
			if (!s.empty() && s.top() == tmp) {
				s.pop();
			}
			else {
				s.push(tmp);
			}
		}
		while (!s.empty()) {
			t.push(s.top());
			s.pop();
		}
		printf("#%d ", tcase);
		while (!t.empty()) {
			printf("%d", t.top());
			t.pop();
		}puts("");
	}
	return 0;
}
