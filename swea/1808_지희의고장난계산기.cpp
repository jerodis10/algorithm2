#include <stdio.h>
#include <memory.h>

int number[10];
int x;
int len;
int datas[1000001];

void createnum(int num, int cnt)
{
    if (cnt > len)//입력된 자릿수보다 긴 숫자는 안만듬
    {
        return;
    }
    if (num > x)//만들고 있는 숫자가 계산하는 숫자보다 커져도 안만듬
    {
        return;
    }
    if (cnt > 0)
    {
        datas[num] = cnt;
    }

    for (int i = 0; i < 10; i++)
    {
        if (number[i] == 1)
        {
            createnum(num * 10 + i, cnt + 1);
        }
    }
}
int main(void) {
    int T;
    setbuf(stdout, NULL);
    scanf("%d\n", &T);
    for (int test_case = 1; test_case <= T; test_case++)
    {
        memset(number, 0, sizeof(number));
        memset(datas, 0, sizeof(datas));
        for (int i = 0; i < 10; i++)
            scanf("%d", &number[i]);

        scanf("%d", &x);
        int temp = x;
        len = 0;

        //x가 몇자리 숫자인지 계산
        while (temp > 0)
        {
            len++;
            temp /= 10;
        }
        createnum(0, 0);

        temp = x;

        int mini = 0;
        int num = x;
        if (x == 1 && number[1] == 1)
        {
            printf("#%d %d\n", test_case, 2);
            continue;
        }
        for (int i = x; i > 1; i--)
        {
            while (datas[i] > 0)
            {
                if (num % i == 0)
                {
                    mini += 1 + datas[i];
                    num /= i;
                }
                else
                    break;
            }
            if (num == 1)
            {
                break;
            }
        }

        printf("#%d %d\n", test_case, num != 1 ? -1 : mini);


    }
    return 0;
}