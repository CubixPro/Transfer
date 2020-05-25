#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
    cases{
        int n;
        cin >> n;
        int arr[n];
        for(int i =0  ; i < n ; i++){
            cin >> arr[i];
        }
        bool check = true;;
        for(int i = 1 ; i < n ; i++ ){
            if(arr[i] < arr[i - 1]){
                check = false;
                break;
            }
        }
        int prod = 1;
        int pref = arr[0];
        for(int i = 1 ; i < n ; i++){
           
            int res = arr[i];
            int add = pref;
            while(res != 0){
                int r = res%2;
                int a = add%2;
                if(r == 1 && a == 1){
                    prod = (prod * 2)%mod;
                }

                res = res/2;
                add = add/2;
            }
            pref = pref|arr[i];
        }
        if(check)
        cout << prod << '\n';
        else{
            cout << 0 << '\n';
        }
    }
}
