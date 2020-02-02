#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

vector<int> graph[MAX];
map<pair<int, int>, int> colours;
bool visited[MAX];
int onstack[MAX];
int colour = 1;
// and then there were none

void dfs(int source){
    visited[source] = true;
    onstack[source] = 1;
    for( int i = 0; i < graph[source].size() ; i++ ) {
        if(!visited[graph[source][i]]){
 
            dfs(graph[source][i]);
            colours.insert({make_pair(source, graph[source][i]), 1});
        }
        else if(onstack[graph[source][i]]){
             colours.insert({make_pair(source, graph[source][i]), 2});
            colour = 2;
        }
        else{
            colours.insert({make_pair(source, graph[source][i]), 1});
        }
 
    }
    onstack[source] = 0;
}

int main(){
    int m, n;
    cin >> m >> n;
    int edges[n][2];
    memset(visited, false, sizeof(int)*MAX);
    memset(onstack, 0, sizeof(int)*MAX);
    for(int i = 0 ; i < n ; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        edges[i][0] = x;
        edges[i][1] = y;
    }
    for(int i = 1; i <= m ; i++){
        if(visited[i] == 0)
            dfs(i);
    }
    
    cout << colour << '\n';
    for(int i = 0 ; i < n ; i++){
        cout << colours[{make_pair(edges[i][0], edges[i][1])}] << ' ';
    }
}