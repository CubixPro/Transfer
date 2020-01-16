#include<bits/stdc++.h>
#define f first
#define s second
#define loop(a,b,c) for(int i = (a); i < (b) ; i+=c)
using namespace std;
vector<pair<int, int>> graph[1050];
int weight[1050];
bool visited[1050];

int min_dfs(int source, int min_val){
    if(graph[source].size() == 0){
        weight[source] = min_val;
        return source;
    }
    visited[source] = true;
    for(int i = 0 ; i < graph[source].size() ; i++){
        if(!visited[graph[source][i].f]){
            return min_dfs(graph[source][i].f, min(min_val, graph[source][i].s));
        }
    }
    return 0;
}


int main(){
    int n;
    int  p;
   cin >> n >> p; 
    set<int> tap;//end
    set<int> tank;//begin
    /*loop(1, n + 1, 1){ 
        tap.insert(i);
        tank.insert(i);
    }*/
    
    if(p == 0){
        cout << 0;
        return 0;
    }
    for(int i = 0 ; i < p ; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back(make_pair(y, wt));
        tank.insert(x);
        tap.insert(y);
    }
    set<int>:: iterator ittap = tap.begin();
    while(ittap != tap.end()){
        if(tank.find(*ittap) != tank.end()){
            tank.erase(*ittap);
        }
        ittap++;
    }
    
    set<int>::iterator it = tank.begin();
    cout << tank.size() << "\n";
    while(it != tank.end()){
        int val = min_dfs(*it, INT32_MAX);
        cout << *it << " " << val << " " << weight[val] << '\n';
        it++;
    }
} 