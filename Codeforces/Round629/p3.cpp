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
        string str = "";
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            str = str + "a";
        }
        int i ;
        k--;
        for(i = 1 ; ; i++){

            sum = sum + i;
            if(sum > k){
                break;
            }
        }
        str[i ] = 'b';
        str[k + 1 - (sum - i) - 1] = 'b';
        reverse(str.begin(), str.end());
        cout << str << '\n';
    }
}