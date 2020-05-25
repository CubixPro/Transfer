#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll i, h, ans = 1;
    cin >> h;
    for(i = 1 ; i <= h ; i++){
        ll x;
        cin >> x;
        ans*=x;
    }
    ans = (ans + 1)/2;
    cout << ans ; 
    return 0;
}