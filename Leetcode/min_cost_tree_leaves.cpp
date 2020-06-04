#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int dp[n + 1][n + 1];
        int maxs[n][n];
        for(int i = 0 ; i < n + 1; i++){
            for(int j = 0 ; j < n + 1 ;j++){
                dp[i][j] = INT32_MAX;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n  ;j++){
                maxs[i][j] = INT32_MAX;
            }
        }
         for(int i = 0 ; i < n ; i++){
            for(int j = i; j < n ; j++){
                if(j == i){
                    maxs[i][j] = arr[i];
                    
                }
                else{
                    if(arr[j] > maxs[i][j - 1]){
                        maxs[i][j] = arr[j];
                    }
                    else{
                        maxs[i][j] = maxs[i][j - 1];
                    }
                }
        }
        }    
            for(int i = 0 ; i < n ; i++){
                dp[i][i] = 0;
            }
        
            for(int l  = 1; l < n ; l++){
                for(int i = 0 ; i < n - l ; i++){
                    int j = i + l;
                    for(int k = i ; k < j ; k++){
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxs[i][k] * maxs[k + 1][j]);
                    }
                }
            }
            return dp[0][n - 1];
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
    cout << s.mctFromLeafValues(arr);
}