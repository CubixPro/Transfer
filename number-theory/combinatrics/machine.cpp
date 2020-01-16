#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef  long long int lld;

lld *dp;

lld calc(lld n)
{
    if (dp[n] != 0)
    {
        return dp[n];
    }
    else if (n == 1)
    {
        dp[n] = 1;
        return 1;
    }
    else if (n == 2)
    {
        dp[n] = 2;
        return 2;
    }
    else if (n == 3)
    {
        dp[n] = 3;
        return 3;
    }
    else if (n % 2 == 0)
    {
        dp[n] = (((calc(n / 2)%mod) * (calc(n / 2)%mod))%mod + ((calc((n - 2) / 2)%mod) * (calc((n - 2) / 2)%mod))%mod)%mod;
        return dp[n];
    }
    else
    {
        dp[n] = (((calc(n / 2)%mod) * (calc(n / 2 + 1)%mod)) + ((calc(n / 2 - 1)%mod) * (calc(n / 2)%mod)))%mod;
        return dp[n];
    }
}

int main()
{
    string bob;
    cin >> bob;
    dp = new lld[bob.length() + 1];
    memset(dp, 0, sizeof(lld) * (bob.length() + 1));
    lld finalval = 1;
    lld count = 1;
    char ch = bob[0];
    if (ch == 'w' || ch == 'm')
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i < bob.length(); i++)
    {
        if (bob[i] == 'w' || bob[i] == 'm')
        {
            printf("0");
            return 0;
        }
        if (bob[i] == bob[i - 1])
        {
            count++;
        }
        else
        {
            //printf("%lld ", count);
            if (bob[i - 1] == 'u' || bob[i - 1] == 'n')
            {
                finalval *= calc(count);
                finalval = finalval%mod;
            }

            count = 1;
        }
    }
       if(bob[bob.length() - 1] == 'u' || bob[bob.length() - 1] == 'n')
       {
           finalval *= calc(count);
           finalval = finalval%mod;
       } 
    printf("%lld", finalval);
}