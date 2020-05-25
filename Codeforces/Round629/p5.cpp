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
        cin >>n;
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        } 
        int colours = 0;
        int arr_col[n];
        arr_col[0] = 0;
        bool plusone = false;
        for(int i = 1 ; i < n ; i++){
            if(arr[i] == arr[i - 1]){
                arr_col[i] = arr_col[i - 1];
            }
            else if(arr[i] != arr[i - 1]){
                arr_col[i] = 1 - arr_col[i - 1];
            }
        }
         int max = 0;
        
        for(int i = 0 ; i < n ; i++){
            //arr_col[i] = arr_col[i] + 1;
            if(max < arr_col[i]){
                max = arr_col[i];
            }
        }
        
        if(arr_col[0] == arr_col[n - 1] && arr[0] != arr[n - 1]){
            plusone = true;
            arr_col[n - 1] = max + 1;

        }
        if(plusone)
         cout << (max + 2) << '\n';
        else{
            cout << (max + 1) << '\n';
        }
        for(int i =  0 ; i < n ; i++){
            cout << (arr_col[i] + 1) << ' ';
        }
        cout << '\n';

    }
}