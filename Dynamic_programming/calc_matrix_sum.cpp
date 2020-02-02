#include <algorithm>
#include <iostream>
 
using namespace std;
long int calcsum(int** arr, int i, int j, long int** arr_val)
{
    if(arr_val[i][j] != 0)
    {
        return arr_val[i][j];
    }
    else
    {
        arr_val[i][j] = arr_val[i-1][j] + arr_val[i][j-1] - arr_val[i-1][j-1] + arr[i][j];
        return arr_val[i][j];
    }
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    long int arr_val[n][m];
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            arr_val[i][j] = 0 ;
        }
    }
     /*for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/
    arr_val[0][0] = arr[0][0];
    for(int i = 1 ; i < n ; i ++)
    {
        arr_val[i][0] = arr_val[i - 1][0] + arr[i][0];
    
    }
    for(int i = 1 ; i < m ; i++)
    {
        arr_val[0][i] = arr_val[0][i - 1] + arr[0][i];
    }
    for(int i = 1 ; i < n ; i ++)
    {
        for(int j = 1 ; j < m ; j++)
        {
            //arr_val[i][j] = calcsum( (int **) arr, i, j,  (long int **)arr_val);
            arr_val[i][j] = arr_val[i - 1][j] + arr_val[i][j - 1] - arr_val[i - 1][j - 1] + arr[i][j];
        }
    }
    
    
   long int q;
   scanf("%ld", &q);
   for(long int i = 0 ; i < q ; i ++)
   {
       int x, y;
       scanf("%d %d", &x, &y);
       printf("%ld\n", arr_val[x-1][y-1]);
   } 
}