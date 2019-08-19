#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int n, m, k, l, r;
        scanf("%d %d %d %d %d", &n, &m, &k, &l, &r);
        int price[n];
        int cost[n];
        int minval = -1;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d %d", &price[i], &cost[i]);
            if(price[i] > k)
            {
                price[i] = max(k, price[i] - m);
            }
            else if(price[i] < k)
            {
                price[i] = min(k, price[i] + m);
            }
            else
            {
                price[i] = k;
            }
            
            if(price[i] >= l && price[i] <= r)
            {
                if(minval == -1)
                    minval = cost[i];
                if(minval > cost[i])
                    minval = cost[i];
            } 
        }
        printf("%d\n", minval);
    }
}