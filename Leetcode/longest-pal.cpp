#include<bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string s) {
        int l = s.length();
        int dp[l][l];
        memset(dp, 0, sizeof(int) * l * l);
        for(int i = 0 ; i < l ; i++){
            dp[i][i] = 1;
        } 
        for(int len = 1 ; len < l ; len++){
            for(int i = 0 ; i < l - len ; i++){
                int j = i + len;
                if(s[i] == s[j]){
                    dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j - 1]);
                }
                else{
                    cout << dp[i + 1][j] << ' ' << dp[i][j - 1] << '\n';
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][l - 1];
    }
int main(){
    cout << longestPalindromeSubseq("bbbab");
}