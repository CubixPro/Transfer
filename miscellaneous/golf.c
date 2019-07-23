#include <stdio.h>
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        int res;
        scanf("%d", &res);
        int a, b, c;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);

        int sum = a + b + c;
        if (sum == res)
        {
            printf("WIN\n");
            continue;
        }
        sum = a - b - c;
        if (sum == res)
        {
            printf("WIN\n");
            continue;
        }
        sum = a + b - c;
        if (sum == res)
        {
            printf("WIN\n");
            continue;
        }
        sum = a - b + c;
        if (sum == res)
        {
            printf("WIN\n");
            continue;
        }
        sum = -a + b - c;
        if (sum == res)
        {
            printf("WIN\n");
            continue;
        }
        sum = -a + b + c;

        if (sum == res)
        {
            printf("WIN\n");
            continue;
        }
        sum = -a - b + c;
        if (sum == res)
        {
            printf("WIN\n");
            continue;
        }
        printf("LOSE");
        printf("\n");
    }
}
