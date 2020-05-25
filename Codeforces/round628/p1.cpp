#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
int counter = 0;
map <pair<int, int>, int> edges;
void dfs(vector<pair<int, int>> graph[], bool visited[], int source){
    visited[source] = true;
    if(graph[source].size() == 1){
            edges.insert(make_pair(mp(graph[source][0].first, source), counter)); 
            edges.insert(make_pair(mp(source,graph[ source][0].first), counter)); 
            counter++;


    }
    for(int i = 0 ; i < graph[source].size() ; i++){
        if(!visited[graph[source][i].first]){
            visited[graph[source][i].first] = true;
            dfs(graph, visited, graph[source][i].first);
            //graph[source][i].second = counter;
            //edges.insert(mp(mp(source, graph[source][i]), counter));
             //edges.insert(mp(mp( graph[source][i], source), counter));
             //edges.insert(make_pair(mp(graph[source][i].first, source), counter)); 
             //edges.insert(make_pair(mp(source,graph[ source][i].first), counter)); 


            //counter++;
        }
    }
}
int main()
{
 fast;
 //cases
 {
     lld n;
     cin >> n;
    //cout << (n - 1) << ' ' << 1 << '\n';
     vector<pair<int, int>> graph[n + 1];
     pair<int, int> arr[n - 1];
     for(int i = 0 ; i < n - 1 ; i++){
         int x, y;
         cin >> x >> y;
         graph[x].push_back({y, -1});
         graph[y].push_back({x, -1});
         //edges.insert(make_pair(mp(x, y), -1)); 
         arr[i] = {x, y};
     }
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));

    dfs(graph, visited, 1);
    for(int i = 0 ; i < n - 1 ; i++){
      // cout << edges[arr[i]] << '\n'; 
      if(edges.find(arr[i]) != edges.end()){
          cout << edges[arr[i]] << '\n';
      }
      else{
          cout << counter << '\n';
          counter++;
      }
    }
 }
}