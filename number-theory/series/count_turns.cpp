#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main()
{
    lld k;
    scanf("%lld", &k);
    while(k-- != 0)
    {
        lld row, col;
        scanf("%lld %lld", &row, &col);
        lld minval = min(row, col);
        if(minval%2 == 1)
        {
            lld div = minval/2;
            lld reqd = div * 4;
            printf("%lld\n", reqd);
        }
        else
        {
            lld div = minval/2;
            div--;
            lld reqd = div * 4 + 2;
            printf("%lld\n", reqd);
        }
        
    }
}