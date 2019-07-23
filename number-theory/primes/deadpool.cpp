#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
typedef long long int lld;
lld s_primes[1000000 + 1];
void sieve()
{
    for (lld i = 2; i * i <= 1000000 + 1; i++)
    {
        if (s_primes[i] == i)
        {
            for (lld j = i * i; j <= 1000000; j++)
            {
                if (s_primes[j] == j)
                    s_primes[j] = i;
            }
        }
    }
}
int main()
{
    lld mod = pow(10, 9) + 7;
    //lld testcases;
    //scanf("%lld", &testcases);
    /*for (lld i = 0; i < 1000000 + 1; i++)
    {
        s_primes[i] = i;
    }
    sieve();*/
    set<lld> numbers;//for storing the numbers in a set
    lld dp[1000000 + 1];//has the no of deadpool trees of a number
    lld n;
    scanf("%lld", &n);
    lld num[n];//stores the numbers sequentially
    for (int i = 0; i < n; i++)
    {
        lld val;
        scanf("%lld", &val);
        numbers.insert(val);
        dp[val] = 1;
        num[i] = val;
    }
    sort(num, num + n);
    set<lld>::iterator it = numbers.begin();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(num[j] == 1)
                continue;
            if ((num[i] % num[j]) == 0)
            {
                lld div = num[i] / num[j];
                if (numbers.find(div) != numbers.end())
                {
                    dp[num[i]] = (dp[num[i]] + ((dp[num[j]] % mod) * (dp[div] % mod)) % mod)%mod;
                }
            }
        }
    }
    lld final_val = 0;
    for (int i = 0; i < n; i++)
    {
        final_val = (final_val + dp[num[i]]) % mod;
    }
    printf("%lld\n", final_val);
}