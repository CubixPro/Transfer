#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int size;
    scanf("%d", &size);
    int dp[size + 1][size + 1];
    int arr[size + 1];
    for (int i = 1; i <= size; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= size; i++)
    {
        dp[i][i] = 1;
    }
    for (int k = 1; k <= size; k++)
    {
        for (int l = 1; l <= size - k; l++)
        {
            int length = INT32_MAX;
            if (arr[l] == arr[l + k])
                length = dp[l + 1][l + k - 1];
            /*if(arr[l] == arr[l + k])
                dp[l][l + k] = dp[l + 1][l + k - 1];
            else 
                dp[l][l + k] = min(dp[l + 1][l + k] + 1, dp[l][l + k - 1] + 1);
            */
            if (k != 1)
            {
                for (int i = l; i < l + k; i++)
                {
                    int val = dp[l][i] + dp[i + 1][l + k];
                    if (val < length)
                        length = val;
                }
                dp[l][l + k] = length;
            }
            else
            {
                if (arr[l] == arr[l + k])
                    dp[l][l + k] = dp[l + 1][l + k - 1];
                else
                    dp[l][l + k] = min(dp[l + 1][l + k] + 1, dp[l][l + k - 1] + 1);
            }
            /*for (int i = 0; i <= size; i++)
            {
                for (int j = 0; j <= size; j++)
                {
                    printf("%d\t", dp[i][j]);
                }
                printf("\n");
            }*/
            //printf("%d\n", dp[1][size]);
        }
    }
    /*for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }*/
    printf("%d\n", dp[1][size]);
}