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
        int  n, k;
        cin >> n >> k;
        int arr[n];
        string str;
        cin >> str;
        for(int i = 0 ; i < str.length() ; i++){
            arr[i] = str[i] - 48;
        }
        int prefix[n + 1];
        memset(prefix, 0, sizeof(int) * n);
        if(arr[0] == 1){
            prefix[0]++;
        }
        for(int i = 1 ; i < n ; i++){
            prefix[i] = prefix[i - 1];
            if(arr[i] == 1){
                prefix[i]++;
            }
        }
        prefix[n] = prefix[n - 1];

        int dp[n];
        for(int j = n - 1; j >= 0 ; j--){
           int  val = 1 - arr[j];
            if(j + k < n){
                val += dp[j + k];
                val += prefix[j + k - 1] - prefix[j];
            }
            else{
                val += prefix[n - 1] - prefix[j];
            }
            int val2 =  arr[j] + prefix[n - 1] - prefix[j];
            dp[j] = min(val, val2);
            //cout << dp[j] << " " ;
        }
        int maxval = dp[0];
        for(int i = 1 ; i < n ; i++){
            dp[i] += prefix[i - 1];
           // cout << dp[i] << ' ';
            maxval  = min(maxval, dp[i]); 
        } 
        cout << maxval << '\n';
    }
}