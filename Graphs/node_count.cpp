#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

long int nodes;

long int bfs_count(vector <long int> graph[], long int source, bool visited[], long int level_count)
{
    queue<long int> q;
    long int count = 0;
    q.push(source);
    long int level[nodes + 1];
    level[source] = 1;
    while(q.empty() != true)
    {
        long int p = q.front();
        q.pop();
        visited[p] = true;
        for(long int i = 0 ; i < graph[p].size() ; i++)
        {
            if(visited[graph[p][i]] == false)
            {
                q.push(graph[p][i]);
                level[graph[p][i]] = 1 + level[p];
                //printf("%ld %ld\n", graph[p][i], level[graph[p][i]]);
                if(level[graph[p][i]] > level_count)
                    return count;
                else if(level[graph[p][i]] == level_count) 
                    count++;
            }
        }

    }
    return count;
}

int main()
{
    scanf("%ld", &nodes);
    long int n = nodes;
    vector <long int> graph[n + 1];
    bool visited[n + 1];
    for(int i = 1 ; i <= (n - 1) ; i++)
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
    long int find_level;
    scanf("%ld", &find_level);
    if(find_level != 1)
        printf("%ld\n", bfs_count(graph, 1, visited, find_level));
    else
    {
        printf("1\n");
    }
    return 0;
    
}
 