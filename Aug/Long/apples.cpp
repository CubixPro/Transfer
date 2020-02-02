#include<iostream>

typedef unsigned long long int ull;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        ull n, k;
        scanf("%llu %llu", &n, &k);
        if(((n/k) % k) == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
        
    }
}