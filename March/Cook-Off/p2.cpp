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
        int max = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            if(max < arr[i]){
                max = arr[i];
            }
        }
        int total_moves = 0;
        int con_k = 0;
        int i;
        for(i = 0 ;i < n ; i++){
            if(arr[i] == max){
                break;
            }
        }
        i = i + 1;
        for(int j = i ; j < i + n  ; j++ ){
            if(arr[j%n] != max){
                con_k++;
            }
            else{
                if(con_k >= (n/2)){
                    total_moves += (con_k - n/2 + 1);
                }
                con_k = 0;
            }

        }
        cout << total_moves << '\n';
    }
}