#include<bits/stdc++.h>
#define MAX 100005
#define f first
#define s second

typedef long long int lld ;

using namespace std;

typedef pair<lld, lld> pii;
vector<pii> tree[MAX]; 
bool visited[MAX];

lld maximum_path( lld source){
    if(tree[source].size() == 0)
        return 0;
    if(tree[source].size() == 1 && visited[tree[source][0].f] == true)
        return 0;
   visited[source] = true;
   lld max = -1;
   for(lld i = 0 ; i < tree[source].size() ; i++)
   {
       if(!visited[tree[source][i].f]){
       lld val;
       if(max < (val = tree[source][i].s + maximum_path(tree[source][i].f)))
            max = val; 
       }
   } 
   return max;
}

int main(){
    lld nodes, edges;
    cin >> nodes;
    memset(visited, false, sizeof(bool) * (nodes + 1));
    lld sum = 0;
    for(lld i = 0 ; i < nodes - 1 ; i++){
        lld x, y, weight;
        cin >> x >> y >> weight ;
        tree[x].push_back(make_pair(y, weight));
        tree[y].push_back(make_pair(x, weight));
        sum += weight;
    }
    cout << (2 * sum - maximum_path(1)); 

}