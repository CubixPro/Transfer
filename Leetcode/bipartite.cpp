#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool possible;
    set<int> vertices; 
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        possible = true; 
        vector<vector<int>> graph(n + 1);
        for(int i = 0 ; i < dislikes.size() ; i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
       for(int i = 1 ; i <= n ; i++){ 
           if(vertices.find(i) == vertices.end())
           {
        vector<int> colors(n + 1, -1);
        colour(graph, 1, i, colors);
           if(possible == false){
               return possible;
           }
           }
       }
        return possible;
           
        
    }
    void colour(vector<vector<int>> graph, bool curr, int source, vector<int> color){
        vertices.insert(source);
        if(color[source] == -1)
        {
       color[source] = curr;
        curr = 1 - curr;
            for(int i = 0 ; i < graph[source].size() ; i++){
                colour(graph, curr, graph[source][i], color);
            }
            }
        else{
            if(color[source] != curr){
                possible = false;
                return;
            }
        }
    }
};
int main(){
    int size;
    cin >> size;
    vector<vector<int>> dislikes;
    while(true){
        int x, y;
        cin >> x >> y;
        if(x == -1 && y == -1){
            break;
        }
        vector<int> a;
        a.push_back(x);
        a.push_back(y);
        dislikes.push_back(a);
    }
    Solution s;
    cout << s.possibleBipartition(size, dislikes);
}