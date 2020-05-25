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
        int n, a, b;
        cin >> n >> a >> b;
        string bstr = "";
        string astr = "";
        string nstr = "";
        for(int i = 0 ; i < b ; i++){
            bstr += (char)(97 + i);
        }
        for(int i = 0 ; i < a ; i++){
            astr = astr + (bstr[i%b]);
        }
        for(int i = 0 ; i < n ; i++){
            nstr = nstr + (astr[i%a]);
        }
        cout << nstr << '\n';
    }
}