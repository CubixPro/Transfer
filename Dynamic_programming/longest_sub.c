#include<stdio.h>
#include<stdlib.h>
int *arr;
int length;
int **dp;
int count_length(int current_element, int next_index)
{
    if(next_index > (length - 1))
    {
        return 0;
    }
    else if(arr[next_index] > current_element)
    {
        return 1 + count_length(arr[next_index], next_index + 1);
    }
    else
    {
        return count_length(current_element, next_index + 1);
    }
    
}
int main()
{
    printf("Enter the length ");
    scanf("%d", &length);
    arr = (int *)malloc(length * sizeof(int));
    for(int i = 0; i < length; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = 1;
    /*dp = (int **)malloc(length * sizeof(int));
    for(int i = 0 ; i < length ; i++)
    {
        dp[i] = (int *)malloc(length * sizeof(int));
        for(int j = 0; i < length ; j++)
        {
            dp[i][j] = -1;
      dfkjdlfdjlaksjljflsjflsdfjlktinpost that the little things that make life sadl; are the ones tbat }
    }*/
    for(int i = 0; i < length ; i++)
    {
        int val = 1 + count_length(arr[i], i + 1); 
        if(val > max)
        {
            max = val;
        }
    }
    printf("The length of the maximum subsequence is %d\n", max);
}