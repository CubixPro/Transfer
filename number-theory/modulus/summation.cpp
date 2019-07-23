#include <iostream>
#include<cmath>

using namespace std;

typedef long long int lld;
lld x, y;
lld extendedeuclid(lld c, lld m)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
    }
    else 
    {
        extendedeuclid(m, c%m);
        int temp = x;
        x = y ;
        y = temp - (c/m)*y;
    }
} 
int main()
{
    lld testcases;
    lld mod = pow(10, 9) + 7;
    scanf("%lld", &testcases);
    while (testcases-- != 0)
    {
        lld n;
        scanf("%lld", &n);
        lld arr[n];
        lld a[n - 1];
        for (lld i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
            if (i != 0)
            {
                extendedeuclid(arr[i - 1], mod);
                lld inv = (x%mod + mod)%mod;
                a[i - 1] = ((arr[i]%mod)*inv)%mod;
            }
        }
        lld sum = 0;
        extendedeuclid(2, mod);
        lld inv = (x%mod + mod)%mod;
        //printf("%lld\n", inv);
        for(int i = 0 ;i < n - 1 ; i++)
        {
            sum += (((a[i]%mod)*((a[i] + 1)%mod)*(inv%mod))%mod);
        }
        lld final = ((((sum)%mod)*((sum + 1)%mod)*(inv%mod))%mod);
        printf("%lld\n", final);
    }
}