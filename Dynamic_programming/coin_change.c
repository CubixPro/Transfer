#include<stdio.h>
#include<stdlib.h>
long int** dp;
long int count_ways(long int  arr[],long  int i,long int total,long int len)
{
    
    if(i > (len - 1))
    {
        return 0;
    }
    else if (dp[i][total] != -1)
    {
        return dp[i][total];
    }
    else if(total < arr[i])
    {
        long int val = count_ways(arr, i + 1, total, len);
        dp[i][total] = val;
        return val;
    }
    else if(total == arr[i])
    {
        long int val = 1 + count_ways(arr, i + 1, total, len);
        dp[i][total] = val;
        return val;
    }
    else
    {
        long int val = count_ways(arr, i, total - arr[i], len) + count_ways(arr, i + 1, total, len);
        dp[i][total] = val;
        return val;
    }
    
}

int main()
{
    long int total; 
    long int len;
    scanf("%ld", &total);
    scanf("%ld", &len);
    long int *arr = (long int *)malloc(len * sizeof(long int));
    for(long int i = 0; i < len ; i++)
    {
        scanf("%ld", &arr[i]);
    }
    dp = (long int **)malloc(len * sizeof(long int *));
    for(long int i = 0 ; i < len ; i++)
    {
        dp[i] = (long int *)malloc((total+1) * sizeof(long int));
    }
    for(long int i = 0; i < len ; i++)
    {
        for(long int j = 0 ; j < total + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    /*for(int i = 0 ; i < len ; i++)
    {
        for (int j = 0 ; j < total + 1 ; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    for(int i = 0 ; i < len ; i ++)
    {
        printf("%d", arr[i]);
    }*/
    //printf("\n");
    long int way = count_ways(arr, 0, total, len);
    printf("%ld", way);


}