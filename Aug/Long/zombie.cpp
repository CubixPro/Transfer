#include<iostream>
#include<algorithm>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))

using namespace std;

typedef long long int lld;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        lld n;
        scanf("%lld", &n);
        lld cave[n];
        lld rad[n];
        lld count = 0 ;
        for(lld i = 0 ; i < n ; i++)
        {
            scanf("%lld", &cave[i]);
            /* lld l = max(0, i  - cave[i]);
            lld u = min(n - 1, (i + cave[i]));
            if((l == 0) && (u == (n - 1)))
            {
                count++;
                cave[i] = -1;
            }*/
        }
        for(lld i = 0 ; i < n ; i++)
        {
            rad[i] = 0;
        }
        for(lld i = 0 ; i < n ; i++)
        {
            lld l = max(0, i  - cave[i]);
            lld u = min(n - 1, (i + cave[i]));
            rad[l] ++;
            if((u + 1) < n)
                rad[u + 1]--;
        }
        for(lld i = 1 ; i < n ; i++)
        {
            rad[i] += rad[i - 1];
        }
        /*  for(int i = 0 ; i < n ; i++)
        {
            printf("%lld ", rad[i]);
        }*/
        sort(rad, rad + n);
        lld zombie[n];
        for(lld i = 0 ; i < n ; i++)
        {
            scanf("%lld", &zombie[i]);
        }
        sort(zombie, zombie + n);
        bool found = true;
        for(lld i = 0 ; i < n ; i++)
        {
            if(zombie[i] == rad[i])
                continue;
            else
            {
                found = false;
                break;
            }
            
        }
        if(found)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
    }
}