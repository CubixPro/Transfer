#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long int n, m;
    scanf("%ld %ld", &n, &m);
    bool edge[n][n];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            edge[i][j] = false;
        }
    }
    for(long int i = 1 ; i <= m ; i ++)
    {
        long int x, y;
        scanf("%ld %ld", &x, &y);
        edge[x - 1][y -1] = true;
        edge[y - 1][x - 1] = true;
    }
    long int q;
    scanf("%ld", &q);
    for(int i = 1 ; i <= q ; i++ )
    {
        long int a, b;
        scanf("%ld %ld", &a, &b);
        if(edge[a - 1][b - 1])
            printf("YES");
        else
        {
            printf("NO");
        }
        printf("\n");
        
    }
}