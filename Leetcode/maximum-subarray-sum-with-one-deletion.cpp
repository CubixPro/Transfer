#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int len = arr.size();
        pair<int, bool> dp[len];
        for(int i = 0 ; i < len ; i++){
            dp[i] = {arr[i], false};
        }
        for(int i = 1; i < len ; i++){
            if((dp[i - 1].first + arr[i]) > dp[i].first){
                dp[i] = {dp[i - 1].first + arr[i], dp[i - 1].second};

            }
            else if(dp[i - 1] > dp[i]){
                dp[i] = {dp[i - 1].first, true};
            }
        }

            int max = dp[0].first;
            for(int i = 1 ; i < len ; i++){
                    if(dp[i].first > max){
                        max  = dp[i].first;
                    }
            }
            return max;
    }
};
int main(){
    Solution s;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ;i < n ; i++){
        cin >> v[i];
    }
    cout << s.maximumSum(v);
}