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
        int n, x;
        cin >> n >> x;
        int arr[n];
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int count = 0;
        int new_arr[n];
        new_arr[count] = arr[count];
        count++;
        for(int i = 1 ; i < n ; i++){
            if(arr[i] == arr[i - 1]){
                continue;
            }
            else{
                new_arr[count] = arr[i];
                count++;
            }
        }
        int final = x;
        for(int i = 0 ; i < count ; i++){
            if(new_arr[i] <= final){
                final++;
            }
            if((final + 1) == new_arr[i]){
                final++;
            } 
        }
        cout << final << '\n';

    }
}