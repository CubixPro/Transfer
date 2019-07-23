#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int f(int** graph, int* index, int* dp, int val)
{
    if(graph[0][val] == -1)
    {
        dp[val] = 0;
        return 0;
    }
    if(dp[val] == -1)
    {
        int m;
        m = 1 + f(graph, index, dp, graph[0][val]);
        for(int i = 1; i < index[val]; i++)
        {

            int m2 = 1 + f(graph, index, dp, graph[i][val]);
            if(m2 > m)
            {
                m = m2;
            }
        }
        dp[val] = m;
        return dp[val];
    }
    else 
        return dp[val];
}
int main()
{
    int nodes  ;
    int paths;
    scanf("%d", &nodes );
    scanf("%d", &paths);
    int** graph = (int **)malloc((nodes + 1) * sizeof(int *));
    for(int i = 0; i < nodes + 1 ;i ++)
    {
        graph[i] = (int *)malloc((nodes + 1) * sizeof(int));
    }
    int* index = (int *)malloc((nodes + 1) * sizeof(int));
    int* dp = (int *)malloc((nodes + 1) * sizeof(int));
    for(int i = 0; i < (nodes + 1); i++)
    {
        graph[0][i] = -1;
        index[i] = 0;
        dp[i] = -1;
    }
    printf("Index : \n");
    for(int i = 0; i < nodes + 1 ; i++)
    {
        printf("%d ", index[i]);
    }
    for(int i = 0; i < paths; i++)
    {
        int val ;
        scanf("%d", &val);
        scanf("%d", &graph[index[val]][val]);
        index[val]++;
    }
    printf("Graph : \n");
    for(int i = 0 ; i < nodes + 1 ; i ++)
    {
        for(int j = 0; j < nodes + 1 ; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("Index : \n");
    for(int i = 0; i < nodes + 1 ; i++)
    {
        printf("%d ", index[i]);
    }
    int m = f(graph, index, dp, 1);
    for(int i = 2; i <= nodes; i ++)
    {
        int m2 = f(graph, index, dp, i);
        if(m2 > m)
            m = m2;
    }
    printf("\n");

    printf("Longest Path : %d ", m);
}