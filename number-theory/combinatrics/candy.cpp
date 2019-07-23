#include <algorithm>
#include <iostream>
#define mod 1000000007
//#define mod 5 

using namespace std;

typedef long long int lld;

lld exp(lld number, lld pow)
{
    lld result = 1;
    while (pow != 0)
    {
        if (pow%2 == 1)
        {
            result = ((result%mod) * (number%mod))%mod;
            pow--;
        }
        number = ((number%mod) * (number%mod))%mod;
        pow = pow / 2;
    }
    return result;
}
 
lld com(lld n, lld c)
{
    lld prod = 1;
    lld prodn = 1;
    lld prodc = 1;
    for (lld i = 2; i <= n; i++)
    {
        prod = ((prod%mod) * (i%mod))%mod ;
        if(i == c)
        {
            prodc = prod;
        }
        /*abc */
        if(i == (n - c))
        {
            prodn = prod;
        }
    }
    prod = ((prod%mod) * exp(prodc, mod - 2))%mod;
    prod = ((prod%mod) * exp(prodn, mod - 2))%mod;
    return prod;
}


/*lld com(lld n, lld c)
{
    lld prod = 1;
    lld prodn = 1;
    lld prodc = 1;
    lld fake = 1;
    for (lld i = 2; i <= n; i++)
    {
        prod = ((prod * i));
        if(i == c)
        {
            prodc = prod;
             
        }
        if(i == (n - c))
        {
            prodn = prod;
        }
    }
    prod = prod/(prodn * prodc);
    return prod;
}*/
int main()
{
    lld testcases;
    scanf("%lld", &testcases);
    //printf("%lld", exp(16, 3));

    while (testcases-- != 0)
    {
        lld n;
        lld h;
        lld d;
        scanf("%lld %lld %lld", &n, &h, &d);
        lld c;
        if(h < d || (h + d)!=n)
        {
            c = 0;
        }
        else
        {
            /* code */
            c = com(n - d - 1, d);
        }
        
        printf("%lld\n", c);
    }
}