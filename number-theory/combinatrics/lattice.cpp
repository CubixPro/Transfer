#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;

typedef long long int lld;
lld gcd(lld x, lld y)
{
    if(y%x == 0)
        return x;
    else
    {
        return gcd(y, x % y);
    }
    
}
int main()
{
    lld n;
    scanf("%lld", &n);
    lld points[n][4];
    lld lattice[n];
    for (lld i = 0; i < n; i++)
    {
        scanf("%lld %lld %lld %lld", &points[i][0], &points[i][1], &points[i][2], &points[i][3]);
    }
    for (lld i = 0; i < n; i++)
    {
        lld count = 2;
        lld x1 = points[i][0];
        lld x2 = points[i][2];
        lld y1 = points[i][1];
        lld y2 = points[i][3];
        count = gcd(abs(x1 - x2), abs(y1 - y2)) + 1;
        //printf("%lld\n", count);
        lattice[i] = count;
    }
    lld queries;
    scanf("%lld", &queries);
    while (queries-- != 0)
    {
        lld val;
        scanf("%lld", &val);
        bool found = false;
        for (lld i = 0; i < n; i++)
        {
            if (lattice[i] >= val)
            {
                found = true;
                printf("%lld\n", (i + 1));
                break;
            }
        }
        if (found == false)
            printf("%d\n", -1);
    }
}