#include <iostream>
#include <algorithm>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 1];
    int pre[n + 1];
    pre[0] = 0;
    int pre2[n + 1];
    pre2[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        if (i == 1 && arr[1] == 0)
            pre[1] = 1;
        else if (i == 1 && arr[i] == 1)
            pre[1] = 0;
        else if (arr[i] == 0)
        {
            pre[i] = pre[i - 1] + 1;
        }
        else
        {
            pre[i] = pre[i - 1];
        }
        if (i == 1 && arr[1] == 1)
            pre2[1] = 1;
        else if (i == 1 && arr[i] == 0)
            pre2[1] = 0;
        else if (arr[i] == 1)
        {
            pre2[i] = pre2[i - 1] + 1;
        }
        else
        {
            pre2[i] = pre2[i - 1];
        }
    }
    /* for(int i = 1 ; i <= n ; i++)
    {
        printf("%d ", pre[i]);
    }
    printf("\n");*/
    int testcases;
    scanf(
        "%d", &testcases);
    while (testcases-- != 0)
    {
        int n1, m;
        scanf("%d %d", &n1, &m);
        int val = (pre[m] - pre[n1 - 1]);
        int calc_val = pre2[m] - pre2[n1 - 1] ;
        if (calc_val % 2 == 1)
            printf("%d %d\n", 1, val);
        else
        {
            printf("%d %d\n", 0, val);
        }
    }
}