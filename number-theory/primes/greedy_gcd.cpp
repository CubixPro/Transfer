#include<bits/stdc++.h>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int k, n;
        scanf("%d %d", &k, &n);
        int *arr = new int [n];
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &arr[i]);
        }
        int checksum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i]%k == 0)
            {
                continue;
            }
            else if(arr[i] != 1 && arr[i] > k)
            {
                checksum += min(arr[i]%k, k - arr[i]%k);
            }
            else
            {
                checksum += (k - arr[i]);
            }
            
            
        
        }
        printf("%d\n", checksum);
    }
}