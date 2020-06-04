#include<bits/stdc++.h>
using namespace std;
 int numSquares(int n) {
       int dp[2 * n + 1];
       memset(dp, 1000000007, sizeof(int) * (2 * n + 1));
       dp[1] = 1;
       dp[2] = 2;
       //cout << dp[n];
        for(int i = 2 ; i <= n ; i++){
            if((int(sqrt(i)) * int(sqrt(i))) == i){
                if(i == 11) 
                    cout << sqrt(i);
                dp[i] = 1;
            }
            for(int j = 1 ; j <= i ; j++){
                dp[j + i] = min(dp[j + i], dp[j] + dp[i]);
            }
        }
        return dp[n];
    }
    int main(){
        cout << numSquares(12);
        cout << numSquares(13);
    }