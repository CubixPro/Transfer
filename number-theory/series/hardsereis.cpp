#include<bits/stdc++.h>

using namespace std;

/*int main()
{
    int series[129];
    int last_seen[129];
    int count[129];
    memset(series, -1, sizeof(int) * 129);
    memset(last_seen, -1, sizeof(int) * 129);
    memset(count, 0, 129 * sizeof(int));

    series[0] = 0;
    count[0] = 1;
    last_seen[0] = 0;

    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        if(series[n] != -1)
        {
           printf("%d\n", count[series[n]]); 
           continue;
        }
        else
        {
            for(int i = 1 ; i < n ; i++)
            {
                if(series[i] != -1)
                    continue;
                if(count[series[i - 1]] == 1)
                {
                    series[i] = 0;
                    last_seen[0] = i; 
                    count[0]++;
                }
                else
                {
                    series[i] = i - 1 - last_seen[series[i - 1]];
                    count[series[i - 1]]++;
                    last_seen[series[i]] = i;
                }
                
            }
            printf("%d\n", count[n]);
        }
        
    }
    for(int i = 0 ; i < 129 ; i++)
    {
        if(series[i] == -1)
            break;
        printf("%d ", series[i]);
    }
}*/

int main()
{
    int testcases;
    //scanf("%d", &testcases);
    int series[129];
    series[0] = 0;
    series[1] = 0;
    int count[129];
    memset(count, 0, sizeof(int) * 129);
    count[0] = 2;
    for(int i = 2 ; i <= 128 ; i++)
    {
        if(count[series[i - 1]] == 1)
        {
            series[i] = 0;
            count[0]++;
        }
        else
        {
            for(int j = i - 2 ; j >= 0 ; j--)
            {
                if(series[j] == series[i - 1])
                {
                    series[i] = i - 1 - j;
                    count[series[i]]++;
                    break;
                }
            }
        }
        
    }
    scanf("%d", &testcases);
    for(int i = 0 ; i < testcases ; i++)
    {
        int n;
        scanf("%d", &n);
        int fcount = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(series[i] == series[n - 1])
            {
                fcount++;
            }
        } 
        printf("%d\n", fcount);
    }
    //`printf("\n");
}