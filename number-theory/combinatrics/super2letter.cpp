#include<iostream>
#define mod 1000000007

using namespace std;

typedef long long int lld ;

lld exp_mod(lld a, lld pow)
{
    lld result = 1;
    while (pow != 0)
    {
        if(pow%2 == 1)
            result =  ((result%mod) * (a%mod))%mod;
        a = ((a%mod) * (a%mod))%mod;
        pow = pow/2;
    }
    
}
lld com(lld n, lld p)
{
    if(n == p)
        return 1;
    else if(n < p)
        return 0;
    else
    {
        lld pro = 1;
        lld prod_n = 1;
        lld prod_p = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            pro = ((pro%mod) * (i%mod))%mod;
            if(i == n)
                prod_n = pro;
            else if (i == (n - p))
                prod_p = pro;
        }
        lld val = (pro * exp_mod(prod_n, mod - 2))%mod;
        lld val2 = (val * exp_mod(prod_p, mod - 2))%mod;
        return val2;
    }
    
}
int main()
{
    lld testcases;
    scanf("%lld", &testcases);
    while(testcases-- != 0)
    {
        lld n, p;
        scanf("%lld %lld", &n, &p);
        lld val = exp_mod(2, n) - exp_mod(2, n - 1) - com(n - 1, p);
        printf("%lld\n", val);
    }
}