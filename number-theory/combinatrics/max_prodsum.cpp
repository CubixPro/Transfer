#include <iostream>
#include <algorithm>

#define mod 1000000007

typedef long long int lld;
lld exp(lld a, lld n)
{
    lld result = 1;
    while (n != 0)
    {
        if (n % 2 == 1)
            result = ((result % mod) * (a % mod)) % mod;

        a = ((a % mod) * (a % mod)) % mod;
        n = n / 2;
    }
    return result;
}
lld inv(lld val)
{
    return exp(val, mod - 2);
}
int main()
{
    int testcases;
    scanf("%d", &testcases);
    for (int z = 1; z <= testcases; z++)
    {
        int n;
        scanf("%d", &n);
        lld arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        //printf("hello\n");
        lld prod[exp(2, n) + 1];
        lld dp[exp(2, n) + 1];
        lld sum[exp(2, n) + 1];

        for (int i = 1; i <= n; i++)
        {
            prod[exp(2, i)] = 1;
            sum[exp(2, i)] = 1;
            dp[exp(2, i)] = 1;
        }
        //printf("hello\n");

        lld max = 1;
        /*for(int i = 1 ; i <= n - 1 ; i++)
        {
            //printf("ugg");
            for(int j = 2 ; j <= n ; j++)
            {
                prod[i][j] = ((prod[i][j - 1]%mod) * (arr[j]%mod))%mod;
                sum[i][j] = ((sum[i][j - 1]%mod) + (arr[j]%mod))%mod;
                //printf("%lld %lld\n", prod[i][j], sum[i][j]);
                dp[i][j] = (prod[i][j] * inv(sum[i][j]))%mod; 
                if(dp[i][j] > max)
                    max = dp[i][j];
            }
        }*/

        for (int i = 1; i <= exp(2, n); i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i & (1 >> j) != 0)
                {
                    prod[i] = ((prod[i] % mod) * (arr[j] % mod)) % mod;
                    sum[i] = ((sum[i] % mod) + (arr[j] % mod)) % mod;
                    if (prod[i] % sum[i] == 0)
                    {
                        dp[i] = (prod[i] * inv(sum[i])) % mod;
                        if (dp[i] > max)
                            max = dp[i];
                    }
                }
            }
        }
        printf("Case #%d: %lld\n", z, max);
    }
}