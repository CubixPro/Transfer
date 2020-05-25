#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int pow(int a, int b){
    int res = 1;
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
        int n;
       cin >> n; 
       int  sum = (pow(n, 1) + pow(n, 2) + pow(n, 3))%mod;
        cout << sum;
    }
}