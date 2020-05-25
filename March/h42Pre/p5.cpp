#include<bits/stdc++.h>
#define ll long long int
#define lld long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases ll T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
ll pow(ll a, ll b){
    ll res = 1;
    while(b != 0){
        if(b%2 == 1){
            res = (res * a)%mod;
        }
        a = (a * a)%mod;
        b = b/2;

    }
    return res;
}
using namespace std;
int main()
{
 fast;
 cases
 {
     ll n, k;
     cin >> n >> k;
     ll sum = 0 ;
     sum = (k)%mod;
     for(ll i = 2 ; i <= n ; i++){
         //sum += ((i%mod)*((pow(i, k) - 1)%mod)*(pow(i - 1, (ll)(mod - 2))%mod))%mod;
         sum =(sum%mod +  ((i%mod)*((pow(i, k) - 1)%mod)*(pow((i - 1), (ll)(mod - 2))%mod))%mod);
         
     }
     cout << sum << '\n';
 }
}