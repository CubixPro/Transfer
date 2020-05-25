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
        string str;
        cin >> str;
        int lc = 0;
        int lcmax = 0;
        for(int i = 0 ; i < str.length() ; i++){
            if(str[i] == 'L'){
                lc++;
            }
            if(str[i] == 'R'){
                if(lc > lcmax){
                    lcmax = lc;
                }
                lc = 0;
            }
        }
        if(lc > lcmax){
            lcmax = lc;
        }
        cout << (lcmax + 1) << '\n';
    }
}