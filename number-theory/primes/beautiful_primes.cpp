#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lld;
lld exp_mod(lld num, lld power, lld mod)
{
    lld val = 1;
    while (power != 0)
    {
        if (power % 2 == 1)
        {
            val = ((val % mod) * (num % mod)) % mod;
            power--;
        }
        num = ((num % mod) * (num % mod)) % mod;
        power = power / 2;
    }
    return val;
}

int main()
{
    lld testcases;
    scanf("%lld", &testcases);
    while (testcases-- != 0)
    {
        lld n;
        scanf("%lld", &n);
        lld primes[n];
        lld freq[n];
        lld prod = 1;
        lld prod2 = 1;
        lld mod = pow(10, 9);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &primes[i]);
            prod = ((prod % mod) * (primes[i] % mod)) % mod;
            //printf("%lld\n", prod);
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &freq[i]);
            freq[i]--;
            lld sum = (exp_mod(primes[i], freq[i] + 1, mod) - 1);
            printf("%lld\n", sum);
            sum *= (primes[i] - 1, mod - 2, mod);
            sum = sum % mod;
            printf("%lld\n", sum);
            prod2 = ((prod2 % mod) * (sum % mod)) % mod;
            printf("%lld\n", sum);
            printf("%lld\n\n", prod2);
        }
        prod = (prod2 * prod) % mod;
        printf("%lld\n", prod);
    }
}