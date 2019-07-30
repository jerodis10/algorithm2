#include <iostream>

int main(void) {
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
