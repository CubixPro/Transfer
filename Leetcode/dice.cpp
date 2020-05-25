#include<bits/stdc++.h>
using namespace std;
   bool first = true;
class Solution {
   long long int dp[40][40][1010]; 
public:
    
   long long int numRollsToTarget(int d, int f, int target) {
        if(first){
        memset(dp, -1, sizeof(long long int)*(40)*(40)*1010);
            first = false;
        }
       if(target < 0){
            return 0;
        }
        else if(target == 0 && d != 0){
            return 0;
        }
        else if(target != 0 && d == 0){
            return 0;
            
        }
        else if(target == 0 && d == 0){
            return 1;
        }
        else if(dp[d][f][target] != -1){
            return dp[d][f][target];
        }
         else{
        int sums = 0;
        
           for(int i = 1 ; i <= f ; i++){
              sums += numRollsToTarget(d - 1, f, target - i); 
           }      
           dp[d][f][target] = sums;
           return sums;
        }
    }
};
int main(){
    Solution s;
    cout << s.numRollsToTarget(30, 30, 500);
}
