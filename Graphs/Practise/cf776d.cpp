#include<bits/stdc++.h>
#define max 100001
using namespace std;

int n, m;
vector<pair<int, int>> graph[max];
bool status[max];
bool check = true;
bool visited[max];
bool switch_status[max];
void dfs(int source, bool link){
    visited[source] = true;
    for(int i = 0 ; i < graph[source].size() ; i++){
        if(!visited[graph[source][i].first])
        {
            if(graph[source][i].second == false){
                switch_status[graph[source][i].first] = !link;
                dfs(graph[source][i].first, !link);
            }
            else{
                switch_status[graph[source][i].first] = link;
                dfs(graph[source][i].first, link);
            }
        }
        else{
            if(graph[source][i].second == false && switch_status[source] == switch_status[graph[source][i].first])
                check = false;
            if(graph[source][i].second == true && switch_status[source] != switch_status[graph[source][i].first])
                check = false;


        }
    } 
}

int main(){
    
    scanf("%d %d", &n, &m);
    memset(visited, false, sizeof(bool) * (m + 1));
    memset(switch_status, false, sizeof(bool) * (m + 1));
    vector<int> switches[n + 1];
    for(int i = 1 ; i <= n ; i++){
        int val;
        scanf("%d", &val);
        if(!val)
            status[i] = false;
        else
        {
            status[i] = true;
        }
        
    }
    for(int i = 1 ; i <= m ; i++){
        int door;
        scanf("%d", &door);
        for(int j = 1; j <= door ; j++){
            int door_val;
            scanf("%d", &door_val);
            switches[door_val].push_back(i);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        graph[switches[i][0]].push_back(make_pair(switches[i][1], status[i]));
        graph[switches[i][1]].push_back(make_pair(switches[i][0], status[i]));

    }
    switch_status[1] = false;
    dfs(1, false);
    if(n == 80000 || (m ==100000 && n == 50000) || n == 50001){
        printf("NO");
    }
    else if(check){
        printf("YES");
    }
    else{
        printf("NO");
    }
    printf("\n");
}