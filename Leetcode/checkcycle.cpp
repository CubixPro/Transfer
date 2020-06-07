#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
       for(int i = 0 ; i < prerequisites.size(); i++){
          int x = prerequisites[i][0];
            int y = prerequisites[i][1]; 
           graph[x].push_back(y);

       }  
        vector<bool>visited(numCourses, false);
        for(int i = 0 ; i < numCourses ; i++){
           if(visited[i] == false){ 
                vector<bool> visited2(numCourses, false);
                bool check = findcycle(graph, visited2, visited2, i);
                    if(check == false){
                        return false;
                    }
                visited = orper(visited, visited2);
           }
            
        }
        return true;
    }
    vector<bool> orper(vector<bool> a, vector<bool> b){
        vector<bool> finalarr(a.size());
        for(int i = 0 ; i < a.size() ; i++){
            if(a[i] == false && b[i] == false){
                finalarr[i] = false;
            }
            else if(a[i] == true || b[i] == true){
                finalarr[i] = true;
            }
        }
        return finalarr;
    }
    bool findcycle(vector<vector<int>> graph, vector<bool> &visited, vector<bool> &recstack, int source)
    {
       if(recstack[source] == true){
           return false;
       } 
       else if(visited[source] == true){
           return true;
       }
        visited[source] = true;
        recstack[source] = true;
        bool check = true;
        for(int i = 0 ; i < graph[source].size(); i++){
             check = check && findcycle(graph, visited, recstack, graph[source][i]);
            if(check == false){
                return false;
            }
            
        }
        recstack[source] = false;
        return check;
    }
};


int main(){
    int numcourses;
    int total;
    cin >> numcourses >> total;
    vector<vector<int>> preq(total);
    for(int i  = 0 ; i < total ; i++){
        int x, y;
        cin >> x >> y;
        preq[i].push_back(x);
        preq[i].push_back(y);

    }
    Solution s;
    cout << s.canFinish(numcourses, preq); 
}