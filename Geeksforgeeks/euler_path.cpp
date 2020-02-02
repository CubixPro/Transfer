#include<bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        int v, e;
        scanf("%d %d", &v, &e);
        vector<int> graph[v];
        while(e-- != 0){
            int x, y;
            scanf("%d %d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);

        }
        int odd_c = 0; 
        int even_c = 0;
        for(int i = 0 ; i < v ; i++){
            if(graph[i].size()%2 == 0){
                even_c++;
            }
            else{
                odd_c++;
            }
        }
        if(odd_c == 0){
            printf("2\n");
        }
        else if(odd_c == 2){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    
}