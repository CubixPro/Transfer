#include<algorithm>
#include<iostream>

using namespace std; 

int n;
int** dp;

int countmax(int* wt, int* val, int i, int j, int maxwt, int value)
{
    if(j == maxwt)
        return value;
    else if(j >= maxwt)
        return 0;
    else if(i == n)
        return value;
    /*else if(dp[i][j] == -1)
    {
        printf("r");
        return dp[i][j];
    }*/
    else{ 
      dp[i][j] = max(countmax(wt, val, i + 1, j + wt[i], maxwt, value + val[i]), 
                    countmax(wt, val, i + 1, j, maxwt, value));
        dp[i][j] = 7;
        return dp[i][j];
      
       return 7;
    }
    
   

}

int main()
{
    int testcases;
    scanf("%d", &testcases);
    for(int i = 0 ; i < testcases ;i++)
    {
        scanf("%d", &n);
        int wt[n];
        int val[n];
        int maxwt;
        scanf("%d", &maxwt);
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &wt[i]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &val[i]);
        }    
        int cp[n + 1][maxwt  + 1];
        dp = (int **)cp;
        for(int i = 0 ; i < n + 1 ; i++)
        {
            for(int j = 0 ; j < maxwt + 1; j++)
            {
                dp[i][j] = -1;
            }
        }
        int max = countmax(wt, val, 0, 0, maxwt, 0);
        printf("%d\n", max);
    }
}