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
    cases{
        int a, b;
        cin >> a >> b;
        if(a%b != 0)
        cout << b - a%b << '\n';
        else 
        cout << 0 << '\n';
    }
}