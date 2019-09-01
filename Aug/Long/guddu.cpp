#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        int xor_arr[n];
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &arr[i]);
            if(i == 0)
                xor_arr[i] = arr[i];
            else if(xor_arr[i - 1] == 0)
                xor_arr[i] = arr[i];
            else
            {
                xor_arr[i] = xor_arr[i - 1]^arr[i];
            }
        }
        int count = 0;
        for(int i = 0 ; i < n - 1 ; i++)
        {
            for(int j = i + 1 ; j < n ; j++)
            {
               if(i == 0 && xor_arr[j] == 0)
                {
                    count += (j - i);
                }
                else if(xor_arr[j] == xor_arr[i - 1])
                {
                    count += (j - i);
                }
            }
        }
        printf("%d\n", count);
    }
}