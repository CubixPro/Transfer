#include<bits/stdc++.h>

typedef long long int lld;
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        lld n, k;
        scanf("%lld %lld", &n, &k);
        lld count = 0 ; 
        if(k >= (n - 1))
        {
            k = k - n + 1;
            count++;
        } 
        else
        {
            printf("-1\n");
            continue;
        }
        
        if(k == n)
        {
            count += k/n;
        }
        else if(k < n)
        {
            count += (k/n + 1);
        }
        else 
        {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", count); 
    }
    
}