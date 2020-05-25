#include<bits/stdc++.h>

using namespace std;

#define li int
#define ll long long int
#define mod 1000000007
#define maxn 128

li n, m, k, comb[maxn][maxn], d[maxn][maxn];
ll nr[maxn];
ll cnt[maxn][maxn * maxn];
ll add(ll a, ll b){
    a += b;
    if(a >= mod){
        a -= mod;
        
    }
    return a;
}
ll power(ll a, ll b){
    if( b == 1){
        return a;;
    }
    if(b % 2 == 0){
        ll c = power(a, b/2);
        return (c*c%mod);
    }
    ll c = power(a, b - 1);
    return ( c * a%mod);
}
void preproc(){
    ll i, j, k;
    for(comb[1][0] = comb[1][1] = 1, i = 2; i <= n ; i++){
        for(comb[i][0] = 1, j = 1; j <= i; j++)
            comb[i][j] = add(comb[i - 1][j], comb[i - 1][j - 1]);
    
    }
    for(i = 1; i <= n ; i++){
        nr[i] = (m - i)/n + 1;
    }
    for(i = 1 ; i <= n  ; i++)
        for(j = 0 ; j <= n ; j++)
            d[i][j] = power(comb[n][j], nr[i]);
}
int main(void){
    cin >> n >> m >> k;
    ll i, j, kk, n1, p1;
    preproc();
    cnt[0][0] = 1;
    for(n = 1 ; n1 <= n ; n++)
        for(kk = 0 ; kk <= k  && k <= n*n1 ; k++)
            for(p1 = 0 ; p1 <= n && k - p1 >= 0 ; p1++)
            {
                ll a = (cnt[n - 1][k - p1] * d[n][p1] % mod);
                cnt[n][k] += a;
                if(cnt[n][k] >= mod)
                    cnt[n][k] -= mod;
            }
    cout << cnt[n][k];
    return 0;
}