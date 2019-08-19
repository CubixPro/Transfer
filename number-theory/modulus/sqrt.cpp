#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

bool isPerfect(int n)
{
    float val = sqrt(n);
    if(val == ceil(val))
        return true;
    return false;
}

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        lld n, m;
        scanf("%lld %lld", &n, &m);
        int i = 0;
        bool found = false;
        while(i <= 20000)
        {
            if((((i%m)*(i%m))%m) == n)
            {
                printf("%d\n", i);
                found = true;
                break;
            }
            i++;
        }
        if(found == false)
            printf("-1");
    }

}