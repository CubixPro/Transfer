#include <algorithm>
#include <iostream>

using namespace std;

typedef long long int lld;
lld gcd(lld m, lld n)
{
    if(n == 0)
        return m;
    else 
        return gcd(n, m%n);
}

int main()
{
    lld n;
    scanf("%lld", &n);
    lld final = 0;
    int divider[4] = {2, 3, 11, 13};
    for (int i = 1; i < (1 << 4); i++)
    {
        int prod = 1;
        int count = 0;

        for (int j = 0; j < 4; j++)
        {
            //printf("%d %d %d\n", i, j, (i&(1<<j)));
            if ((i&(1 << j)) != 0)
            {

                prod *= divider[j];
                //printf("%d ", prod);
                count++;
            }
        }
        //printf("%d %d \n", prod, count);
        lld val = n / prod;
        if (count % 2 == 1)
            final += val;
        else
            final -= val;
    }
    lld gc = gcd(final, n);
    printf("%lld %lld\n", final/gc, n/gc);
}