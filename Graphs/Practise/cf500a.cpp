#include<bits/stdc++.h>
using namespace std;
int m;
bool found = false;
void count(vector<int> graph[], int source, bool visited[])
{
   visited[source] = true;
    for(int i = 0 ; i < graph[source].size() ; i++)
    {
        if(graph[source][i] == m )
        {
            found =  true;
        }
        else
        {
             count(graph, graph[source][i], visited);
        }
        
    }
}

int main()
{
    int n ;
    scanf("%d %d", &n, &m);
    vector <int> graph[n + 1];
    bool visited[n + 1];
    for(int i = 1 ; i < n ; i++)
    {
        int x;
        scanf("%d", &x);
        graph[i].push_back(x + i);
        visited[i] = false;
    }
     count(graph, 1, visited);
     //cout << boolalpha << found;
     if(found == true)
     {
         printf("YES\n");
     }
     else
     {
         printf("NO\n");
     }
     

    
}