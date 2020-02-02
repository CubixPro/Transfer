    #include <algorithm>
    #include <iostream>
    #define mod 1000000007

    typedef long long int lld;
    lld pow(lld n, lld pow)
    {
        lld result = 1;
        while(pow != 0)
        {
           if(pow % 2 == 0)
                result = ((result%mod)*(n%mod))%mod;
            n = ((n%mod) * (n%mod));
            pow = pow/2;
        }
        return result;
    }
    lld calc(lld n, lld* dp)
    {
        if(n == 1 || n == 2)
        {
            dp[n] = 1;
            return dp[n];
        }
        else if (dp[n] != -1)
            return dp[n];
        else
        {
            //printf("hello\n");
            lld count = 0;
            for (lld i = 1; i < (n - 1); i++)
            {
                if ((n - 1) % i == 0)
               {     
                   //printf("%lld ", i);
                   count += pow(calc(i, dp), (n - 1)/i);
                   count = count%mod;
               }
            }
            dp[n] = count;
            return dp[n];
        }
    }
    int main()
    {
        lld n;
        scanf("%lld", &n);
        lld dp[n + 1];
        for(lld i = 0 ; i <= n ; i++)
        {
            dp[i] = -1 ;
        }
        lld ways = calc(n, dp);
        printf("%lld", ways);
    }