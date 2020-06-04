#include<bits/stdc++.h>
using namespace std;
int numTrees(int n) {
        int dp[n + 1];
        for(int i = 0 ; i <= n ; i++){
            dp[i] = 0;
        }
        dp[1] = dp[0] = 1;
        for(int j = 2 ; j <= n ; j++){
            for(int i = 0; i < j ; i++){
                dp[j] += dp[i] * dp[j - i - 1];
            }
        }
        return dp[n];
    }

int main(){
    cout << numTrees(3);
}