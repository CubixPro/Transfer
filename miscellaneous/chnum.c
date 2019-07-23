#include<stdio.h>
#include<stdlib.h>
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        int* num = (int *)malloc(n * sizeof(int));
        int positive = 0;
        int negetive = 0;
        for(int i = 0; i < n ; i++)
        {
            scanf("%d", &num[i]);
            if(num[i] > 0)
            {
               positive++;
            }
        }
        negetive = n - positive;
        int max = (positive > negetive)?positive:negetive;
        if(max == n)
        {
            printf("%d %d", n, n);
        }
        else 
        {
            printf("%d %d", max, n - max);
        }
        printf("\n");
        
    }
}
