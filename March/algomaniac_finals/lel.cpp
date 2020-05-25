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
// cases
 {
     int n, k;
     cin >> n >> k;
     for(int i = 0 ; i < n - 1 ; i++){
         int x, y;
         cin >> x >> y;
     }
     for(int j = 0 ; j < k ; j++){
         int val;
         cin >> val;
         if(n%val == 0){
             cout << "YES";
         }
         else{
             cout << "NO";
         }
         cout << '\n';
     }
     
 }
}