#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[370];
    int len;
   
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         len = days.size();
         for(int i = 0 ; i < 370 ; i++){
             dp[i] = 365000;
         }
        for(int i = 0 ; i < len ; i++){
            dp[days[i]] = min(dp[days[i]], min(getDp(days[i] - 7, days) + costs[1] , min(getDp(days[i] - 1, days) + costs[0], getDp(days[i] - 30, days) + costs[2])));
        }
        return dp[days[len - 1]];
    }
    int getDp(int k, vector<int>& days){
       if(k < 0){
           return 0;
       } 
        for(int i = 0 ; i < len - 1; i++){
            if(days[i] <= k && days[i + 1] > k){
                return dp[days[i]];
            }
        }
        return 0;
    }
   
    
    
};
int main(){
Solution s;
    int size;
    cin >> size;
    vector<int> arr(size);
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }
    int size2;
    cin >> size2;
    vector<int> coins(size2);
    for(int i = 0 ; i < size2; i++){
        cin >> coins[i];
    }
    cout << s.mincostTickets(arr, coins );

    cout << INT32_MAX << '\n';
    cout << INT_MAX << '\n';
}