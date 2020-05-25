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
    //cases
    {
        lld n;
        cin >> n;
        lld a[n];
        lld b[n];
        for(lld i = 0  ; i < n ; i++){
            cin >> a[i];
        }
        for(lld i = 0 ; i < n ; i++){
            cin >> b[i];
        }
        lld diff[n];
        for(lld i = 0 ; i < n ; i++){
            diff[i] = a[i] - b[i];
        }
        sort(diff, diff + n);
        lld count = 0;
        lld l = 0 ; 
        lld u = n - 1;
        while(l < u){
            lld sub = diff[u] + diff[l];
            if(sub > 0){
                count += (u - l);
                u--;
            }
            else{
                l++;
                //break;
            }
        }
        cout << count << '\n';
    }
}