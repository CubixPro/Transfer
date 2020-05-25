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
        int arr[n];
        set<int> ele;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            ele.insert(arr[i]%2);
        }
        /*sort(arr, arr + n);
        if(arr[0] == arr[n - 1]){
            cout << "YES\n";
        }
        else if((arr[n - 1] - arr[0]) != 2){
            cout << "NO\n";
        }
        else if(ele.size() == 2){
           cout << "YES\n"; 
        }
        else{
            cout << "NO\n";
        }*/
        if(ele.size() == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}