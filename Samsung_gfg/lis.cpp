#include <bits/stdc++.h>
#include <cmath>
#define lld long long int
#define llf long long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define cases  \
    lld T = 0; \
    cin >> T;  \
    while (T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAXN 2000
using namespace std;

int main(){
    cases{
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        int dp[n];
        for(int i = 0 ; i < n ; i++){
            dp[i] = 1;
        } 
        dp[0] = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
           
        }
        int max_val = 0;
        for(int i = 0 ; i < n ; i++){
            max_val = max(max_val, dp[i]); 
        }
        cout << max_val << '\n';
    }
}
