#include<bits/stdc++.h>
#define lld long long int 
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define mod 998244353 
using namespace std;
int main(){
    //cases
    {
        lld n, k;
        cin >> n >> k;
        lld arr[n];
        lld index[k];
        pair<lld, lld> arrpair[n];
        for(lld i = 0 ; i < n ; i++){
            cin >> arr[i];
            arrpair[i] = {arr[i], i};
        }
        sort(arr, arr + n, greater<lld>());
        sort(arrpair, arrpair + n);
        lld maxval = 0;
        for(lld i = 0 ; i < min(n, k) ; i++){
            maxval += arr[i];
        }
        ///index[0] = 0;
        //index[k + 1] = n - 1;
        lld counter = 0;
        for(lld j = n - 1 ; j > n - 1 - k ; j--){
            index[counter] = arrpair[j].second;
            counter++;
        }
        sort(index, index + k);
        lld prod = 1;
        for(lld i = 1 ; i < k ; i++){
            if((index[i] - index[i - 1]) == 0){continue;}
           prod = (prod%mod * ((index[i] - index[i - 1])%mod))%mod; 
        }
        cout << maxval << ' ' << prod << '\n';
    }
}