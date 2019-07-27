#include <iostream>
#include <algorithm>

int set(int num)
{
    int count = 0;
    while(num != 0)
    {
        num = num&(num - 1);
        count++;
    }
    return count;
}
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        int arr[n];

        for(int i = 0 ; i < n ; i++)
        {
           scanf("%d", &arr[i]); 
        }

        int count = set(arr[0]);

        for(int i = 1 ; i < n ; i++)
        {
            int new1 = set(arr[i]);
            if(new1 < count)
                count = new1;
        }
        printf("%d\n", count);
    }
}