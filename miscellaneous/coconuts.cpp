#include<iostream>
#include<algorithm>

using namespace std;

typedef  long long int lld;

int main()
{
    lld testcases;
    scanf("%lld", &testcases);
    while(testcases-- != 0)
    {
        lld n, z;
        scanf("%lld %lld", &n, &z);
        lld arr[n];
        lld min ;
        for(lld i = 0 ; i < n ; i++)
        {
            scanf("%lld", &arr[i]);
        }
        sort(arr, arr + n);
        min = arr[n - 1];
        for(lld i = n - 2, j = 2 ; i >= 0 ; i--, j++)
        {
                if((arr[i]*j) < min)
                    min = arr[i]*j;
        }
        printf("%lld\n", min);
    }
}