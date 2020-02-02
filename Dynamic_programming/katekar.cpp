#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int size;
    scanf("%d", &size);
    int max = 0;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    int after[max + 1][size + 1];

    for (int i = 0; i <= max; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            after[i][j] = 0;
        }
    }

    for (int i = size - 1; i >= 0; i--)
    {
        after[arr[i]][i] = after[arr[i]][i + 1] + 1;
        if (after[arr[i]][i] != 0 && i >= 1)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                after[arr[i]][j] = after[arr[i]][i];
            }
        }
    }
    /*for(int i = 0 ; i <= max ; i++)
    {
        for(int j = 0 ; j <= size ; j ++)
        {
            printf("%d \t", after[i][j]);
        }
        printf("\n");
    }*/

    int dp[size][2];
    for (int i = 0; i < size; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        if (dp[i][0] < after[arr[i]][i])
        {
            dp[i][0] = after[arr[i]][i];
            dp[i][1] = after[arr[i]][i];
        }
        for (int i = 0; i < size; i++)
        {
            printf("%d   ", dp[i][0]);
        }
        printf("\n");for (int j = 1; j < size; j++)
        {
            if (arr[j] > arr[i] && after[arr[j]][i] > dp[arr[i]][1])
            {
                dp[arr[j]][0] = ((dp[arr[i]][0] + after[arr[j]][i]) > dp[arr[j]][0]) ? (dp[arr[i]][0] + after[arr[j]][i]) : dp[arr[j]][0];
                dp[arr[j]][1] = after[arr[j]][i];
            }
            else
                continue;
        }
        
    }
    /*for (int i = 0; i < size; i++)
    {
        printf("%d   ", dp[i][0]);
    }*/
}