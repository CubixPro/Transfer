#include<bits/stdc++.h>
using namespace std;
#define mod 998848
#define For(i, n) for(int i = 0 ; i < n ; i++)
#define ll long long int
ll a[2605][105];
ll ineedans(ll x, ll y){
    if((y - x) > 0)
        return 0;
    if((x - 26*y)>0)
        return 0;
    if(y == 1)
        return 1;
    if(a[x][y] > -1)
        return a[x][y];
    ll sum = 0;
    ll i;
    for(i = 1 ; i < 27 ; i++){
        sum += ineedans(x - i, y - 1);
        sum%=mod;
    }
    return a[x][y] = sum;
}
int main(){
    ll i, j, n;
    cin >> n;
    For(i, 2605)
        For(j, 105)
            a[i][j] = -1;
    ll x = 0;
    string s;
    cin >> s;
    ll l = s.size();
    For(i, l)
        x += (s[i] + 1 - 'a');
    ll ans = ineedans(x, l);
    cout << (ans - 1)%mod << endl;
    return 0;
}
