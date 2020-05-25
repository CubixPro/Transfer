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
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];

        }
        int newarr[n];
        memset(newarr, 0, sizeof(newarr));
        newarr[0] = arr[0];
        int max = newarr[0];
        for(int i = 1; i < n ; i++){
            newarr[i] = arr[i] + max;
            if(max < newarr[i]){
                max = newarr[i];
            }
        }
        for(int i = 0 ; i < n ; i++){
            cout << newarr[i] << ' ';
        }
        cout << '\n';
    }
}