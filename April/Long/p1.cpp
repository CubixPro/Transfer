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
        int n, k;
        cin >> n >> k;
        int factor = 2;
        int x = n;
        for(int i = 2 ; i <= sqrt(x); i++){
            while(n%i == 0){
                n = n/i;
                k--;
                if(k == 1){
                    break; 
                }
            }
            if(k == 1){
                break;
            }
           
            //factor++;

        }
        if((n == 1 && k == 1) || (k > 1)){
            cout << 0 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }
}