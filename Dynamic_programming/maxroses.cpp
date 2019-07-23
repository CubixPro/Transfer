#include<algorithm>
#include<iostream>
 
using namespace std;

int main()
{
    int testcases ;
    scanf("%d", &testcases);
    for(int z = 1 ; z <= testcases; z++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int arr[n][m];
        for(int i = 0 ; i < n ; i ++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                scanf("%d", &arr[i][j]);
            }

        }
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                int max = arr[i][j];
                for(int k = 0 ; k < m ; k++)
                {
                    if(max < (arr[i][j] + arr[i - 1][k]) && j != k)
                        max = arr[i][j] + arr[i - 1][k];
                }
                arr[i][j] = max;
            }
        }
        /*for(int i  = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                printf("%d \t", arr[i][j]);
            }
            printf("\n");
        }*/
        int max = 0;
        for(int i = 0 ; i < m ; i ++)
        {
            if(arr[m - 1][i ] >max)
                max = arr[m - 1][i];
        }
        printf("%d\n", max);
    }
    }
