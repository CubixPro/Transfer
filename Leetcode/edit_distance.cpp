#include<bits/stdc++.h>
using namespace std;
 int minDistance(string word1, string word2) {
      int len1 = word1.length();
        int len2 = word2.length();
        int dp[len1 + 1][len2 + 1];
        memset(dp, 0, sizeof(int)*(1 + len1)*(1 + len2));
        dp[len1][len2] = 0;
        for(int i = len1 - 1 ; i >= 0 ; i--){
            dp[i][len2] = dp[i + 1][len2] + 1;
        }
        for(int i = len2 - 1 ; i >= 0 ; i--){
            dp[len1][i] = dp[len1][i + 1] + 1;
        }
        for(int i = len1  - 1 ; i >= 0 ; i--){
            for(int j = len2 - 1 ; j >= 0 ; j--){
               // dp[i][j] = INT_MAX;
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = min(dp[i + 1][j + 1], min(dp[i][j + 1], dp[i + 1][j])) + 1;
                }
            }
        }
        return dp[0][0];
    }

    int main(){
        cout << minDistance("horse", "ros");
    }