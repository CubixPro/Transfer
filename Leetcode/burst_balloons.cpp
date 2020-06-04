#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[510][510];
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(int)*510*510);
        return maxCoin(1, 1, nums, 0, nums.size() - 1);
    }
    int maxCoin(int left, int right, vector<int>& nums, int i, int j){
        if(dp[i][j] != -1){
            return left * right * dp[i][j];
        }
        int maxval = 0;
        if(i == j){
            return left * right * nums[j];
        }
       for(int k = i ; k <= j ; k++){
          if(k == i){
              maxval = max(maxval, left * right * nums[k] + maxCoin(nums[k], right, nums, i + 1, j)); 
          } 
           else if(k == j){
               maxval = max(maxval, left * right * nums[k] + maxCoin(left, nums[k], nums, i, j - 1)); 
           }
           else{
               maxval = max(maxval, left * right * nums[k] + maxCoin(left, nums[k], nums, i, k - 1) + maxCoin(nums[k], right, nums, k + 1, j));
           }
       } 
       dp[i][j] = maxval;
           return maxval;
    }
};
int main(){
    int size;
    cin >> size;
    vector<int> arr(size);
    for(int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }
    Solution s;
    cout << s.maxCoins(arr);
}