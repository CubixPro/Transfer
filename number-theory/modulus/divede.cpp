#include <iostream>
#include <algorithm>
#include <math.h>

#define mod 1000000007

typedef long long int lld;

lld gcd(lld a, lld b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
        return gcd(b, a % b);
}
lld exp_mod(lld num, lld power)
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
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        lld a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        lld d = gcd(a, b);
        if (d != 1)
        {
            lld count = 0;
            while (a % d == 0)
            {
                count++;
                a = a / d;
            }
            lld e = (count > c) ? c : count;
            lld f = (exp_mod(b, c) * exp_mod(exp_mod(d, e), mod - 2)) % mod;
            printf("%lld\n", f);
        }
        else
        {
            lld f = exp_mod(b, c);
            printf("%lld\n", f);
        }
    }
}