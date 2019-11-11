#include <iostream>

int main(void) {
<<<<<<< HEAD
	for (int testCase = 1; testCase <= 10; testCase++) 
	{
		int a; 
		scanf("%d\n", &a);
		int sum = 0;
		for (int i = 0; i < a; i++)
		{
			if (i % 2 == 0)
			{
				int n = 0;
				scanf("%d", &n);
				sum += n;
=======
	for (int tcase = 1; tcase < 10; tcase++) {
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
>>>>>>> ee9083210f027714703902dee540ebe46a1fc912
			}
			else
			{
				char n = 0;
				scanf("%c", &n);
			}
		}
		printf("#%d %d\n", testCase, sum);
	}
	return 0;
}
