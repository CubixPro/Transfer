#include<bits/stdc++.h>
#include<cmath>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
int main(){
 cases
    {
       lld n;
       cin >> n;
       if(n%2 == 0){
           cout << (n/2 - 1);
       } 
       else{
           cout << (n/2);
       }
       cout << '\n';
    }
}