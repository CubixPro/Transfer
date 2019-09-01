#include<iostream>
#include<algorithm>

typedef long long int lld;

using namespace std;

int main()
{
    lld testcases;
    scanf("%lld", &testcases);
    while(testcases-- != 0)
    {
        lld n, q;
        scanf("%lld %lld", &n, &q);
        lld arr[n];
        for(lld i = 0 ; i < n ; i++)
        {
            scanf("%lld", &arr[i]);
        }
        sort(arr, arr + n);
        double prefix[n];
        prefix[0] = arr[0];
        /* for(lld i = 1 ; i < n ; i++)
        {
            prefix[i] = arr[i] * 1.0 / 2 + arr[i - 1];
            printf("%lf ", prefix[i]);
        }*/
        //printf("\n");

        for(lld i = 1 ; i <= q ; i++)
        {
            lld val ;
            scanf("%lld", &val);
            lld count = 0 ;
            for(lld j = 0 ; j < n ; j++)
            {
                if(val > arr[j])
                {
                    count++;
                }
                else
                {
                    break;
                }
                
                val = 2 * (val - arr[j]);
            } 
            printf("%lld\n", count);
        }
    }
}