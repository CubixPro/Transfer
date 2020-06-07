#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        else{
            return a.first < b.first;
        }
    }
    class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
          if(env.size() == 0){
       return 0;}
        pair<int, int> arr[env.size()];
        for(int i = 0 ; i < env.size() ; i++){
            arr[i] = {env[i][0], env[i][1]};
        }
        sort(arr, arr + env.size(), compare);
        int dp[env.size()];
        memset(dp, 1, sizeof(int) * env.size());
        dp[0] = 1;

        for(int i = 1 ; i < env.size() ; i++){
            for(int j = 0 ;j  < i  ; j++){
            if(arr[i].first > arr[j].first && arr[i].second > arr[j].second){
                dp[i] = max(1 + dp[j], dp[i]);
            }
            else if(arr[i].first >= arr[j].first && arr[i].second >= arr[j].second){
                dp[i] = max(dp[i], dp[j]);
            }
            }
        }
        return dp[env.size() - 1];
    }
}; 
int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for(int i = 0 ; i < n ; i++){
        int x, y;
        cin >> x >> y;
        arr[i].push_back(x);
        arr[i].push_back(y);
    }
    Solution s;
    cout << s.maxEnvelopes(arr);
}