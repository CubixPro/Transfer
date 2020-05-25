#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
       int n, k;
       scanf("%d %d", &n, &k);
       int total[n];
       vector<int>loc[k + 1];
       for(int i = 1 ; i <= k ; i++){
           loc[i].push_back(-1);
       }
       for(int i = 0 ; i < n ; i++){
           scanf("%d", &total[i]);
           loc[total[i]].push_back(i);

       }
       for(int i = 1 ; i <= k ; i++){
           loc[i].push_back(n );
       }
    
    int max = 1;
    for(int i = 1 ; i <= k ; i++){
        if(loc[i].size() != 2){
      for(int j = 0 ; j < loc[i].size() - 1 ; j++){
          if(max < (loc[i][j + 1] - loc[i][j] - 1))
          {
              max = loc[i][j + 1] - loc[i][j] - 1;
          }
      } 
        }
      else{
          max = n;
      }
        }
    
    cout << max << '\n';
}
}