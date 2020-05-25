#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
int main()
{
 fast;
 cases
 {
     int n, k;
     cin >> n >> k;
     int sum = 0;
     if(n%2 == 0)
        sum = (n/2)*1 + (n/2)*(k + 1);
    else{
        sum = n/2 + (n/2)*(k + 1) + 2*k + 1;
    }
    cout << sum << '\n';
 }
}
 