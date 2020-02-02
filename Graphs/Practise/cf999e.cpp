#include<bits/stdc++.h>
#define N 5050
using namespace std;


    int n, m, s;
    vector<int> graph[N + 1];
    bool visited[N + 1];
    //int count_good = 0;
    bool sortbysec(const pair<int, int> a, const pair<int, int> b)
    {
        return (a.second<b.second);
    }
    
void dfs( int source){
    visited[source] = true;
    for(int i = 0 ; i < graph[source].size() ; i++)
    {
        if(visited[graph[source][i]] == false)
            dfs(graph[source][i]);
    }
}

int dfs_count(int source, bool new_visited[])
{
     new_visited[source] = true;
    int count_good = 0; 
    for(int i = 0 ; i < graph[source].size() ; i++)
    {
        if(new_visited[graph[source][i]] == false && visited[graph[source][i]] == false)
        {
            
            count_good += 1 + dfs_count(graph[source][i], new_visited);
        }
    }
    return count_good;
}

int main()
{
    scanf("%d %d %d", &n, &m, &s);
    int count = 0;
    for(int i = 0 ; i < m ; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
    }
    for(int i  = 1 ; i <= n ; i++)
    {
        visited[i] = false;
    }
    dfs( s);
    
    
    vector<pair<int, int>> bad_vertices;
    bool newvisited[n + 1];
    for(int i = 1 ; i <= n ; i++)
    {
        if(visited[i] == false && i != s)
        {
            memset(newvisited, false, sizeof(bool) * (n + 1));
            int count = dfs_count( i, newvisited);
            bad_vertices.push_back(make_pair(i, count));
        }

    }
    sort(bad_vertices.begin(), bad_vertices.end(), sortbysec);
    reverse(bad_vertices.begin(), bad_vertices.end());
    //
    for(int i = 0 ; i < bad_vertices.size() ; i++)
    {
        if(visited[bad_vertices[i].first] == false)
        {
            //memset(new_visited, false, sizeof(new_visited) * (n + 1));
            dfs( bad_vertices[i].first);
            count++;
        }
    }
    cout << count << "\n";
}