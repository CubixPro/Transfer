#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
int main(){
    //cases{
    {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int arr[n];
        for(int i = 0 ; i < n  ; i++){
            cin >> arr[i];
        }
        int dp[2005][2005];
        memset(dp, 0, sizeof(int)*2005*2005);
        for(int i = 0 ; i < n ; i++){
            int sum = 0;
            for(int j = 0 ; j < n ; j++){
                sum += arr[j];
            }
            sum = sum%m;
            if(sum >= l && sum <= r){
                dp[i][0]++;
            }
        }

    }
}