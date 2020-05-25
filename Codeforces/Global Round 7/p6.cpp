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
        int n;
        cin >> n;
        string str = "2";
        n = n - 1;
        for(int i =0 ; i < n ; i++){
            str = str + "3";
        }
        if(n != 0)
            cout << str << '\n';
        else{
            cout << -1 << '\n';
        }
    }
}