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
        lld n, k;
        cin >> n >> k;

        lld sum = 0;
        lld orig = 1; bool check = true;
        for(lld i = 1 ; i <= (k - 1) ; i++){
            if(sum > n){
                check = false;
                break;
            }
            sum += orig;
            orig += 2;
           
        } 
        if((n - sum)%2 == 1 && (n - sum) >= (orig) && (n - sum) > 0 && check){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}