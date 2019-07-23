#include<iostream>
#include<algorithm>
#include<vector>
#include<array>

using namespace std;

long int count(bool arr[], long int n);
void traverse(vector <long int> graph[], long int source, bool visited[]);

int main()
{
    long int n, m;
    scanf("%ld %ld", &n, &m);
    vector <long int> graph[n + 1];
    bool visited[n + 1];
    for(int i = 1 ; i <= m ; i++)
    {
        long int x, y;
        scanf("%ld %ld", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    } 
    for(int i = 1 ; i <= n ; i++)
    {
        visited[i] = false;
    }
    long int x;
    scanf("%ld", &x);
    traverse(graph, x, visited);
    /*for(int i = 1 ; i <= n ; i++)
    {
        printf("%d ", visited[i]);
    }
    printf("\n");*/
    printf("%ld\n", count(visited, n));
}
long int count(bool arr[], long int n)
{
    long int count = 0;
    for(long int i = 1 ; i <= n ; i++)
    {
        if(arr[i] == false)
            count++;
    }
    return count;
}
void traverse(vector <long int> graph[], long int source, bool visited[])
{
    visited[source] = true;
    for(long int i = 0 ; i < graph[source].size() ; i++ )
    {
        if(visited[graph[source][i]] == false)
            traverse(graph, graph[source][i], visited);
    }
}