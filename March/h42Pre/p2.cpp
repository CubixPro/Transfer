#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
lld max = 0;
lld n;
pair<lld, int> dp[100001];
lld weight[100001];
void dfs(vector<int> graph[], lld source, bool visited[])
{
    visited[source]  = true;
   for(int i = 0 ; i < graph[source].size() ; i++){
       if(visited[graph[source][i]] == true){
           if(dp[graph[source][i]].second == 1 && (dp[graph[source][i]].first - dp[source].first) >= dp[source].first){
               dp[source].first = dp[graph[source][i]].first - dp[source].first;
               dp[source].second = 0;
           }
           else if(dp[graph[source][i]].second == 1 && ( - dp[graph[source][i]].first + dp[source].first) >= dp[graph[source][i]].first){
               dp[graph[source][i]].first = - dp[graph[source][i]].first + dp[source].first;
               dp[graph[source][i]].second = 0;
           }
           else if(dp[graph[source][i]].second == 0 ){
               dp[source].first = dp[graph[source][i]].first + dp[source].first;
               dp[graph[source][i]].first = dp[graph[source][i]].first + dp[source].first;
               dp[graph[source][i]].second = 1;
               dp[source].second = 1;
           }
       }
       else{
           dfs(graph, graph[source][i], visited);
       }
   } 
}
int main()
{
 fast;
 cases
 {
     cin >> n;
     
     vector<int> graph[n + 1];
     bool visited[n + 1];memset(visited, false, sizeof(bool)*(n + 1));
     for(lld i = 1 ; i <= n - 1 ; i++){
         lld x, y;
         cin >> x >> y;
         graph[x].pb(y);
         graph[y].pb(x);
     }
     for(lld i  = 1 ; i <= n ; i ++ ){
            cin >> weight[i];
            dp[i] = mp(weight[i], 1);//1 = negetive; 0 = positive
     }
     dfs(graph, 1, visited);
     lld max = 0;
     for(lld i = 1; i <= n ; i++){
         if(max <= dp[i].first){
             max = dp[i].first;
         }
     }
     cout << max << '\n';
       


 }
}