#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
lld power(lld a, lld b){
    lld res = 1;
    while(b != 0){
        if(b%2 == 1){
            res = ((res%mod) * (a%mod))%mod;
        }
        b = b/2;
        a = ((a%mod)*(a%mod))%mod;
    }
    return res;
}
int main(){
  //  cases
    {
        lld n;
       cin >> n; 
       lld  sum1 = power(n, 1);
       lld sum2 = power(n, 2);
       lld sum3 = power(n, 3);

        lld sum = (sum1 + sum2 + sum3)%mod;
        cout << sum;
    }
}