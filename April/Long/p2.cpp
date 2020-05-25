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
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            /*if(arr[i] < 0){
                arr[i] = -arr[i];
            }*/
        } 
        
        int power[n];
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            if(arr[i] == 0){
                power[i] = 2;
                continue;
            }
            while(arr[i]%2 == 0){
                arr[i] = arr[i]/2;
                count++;
            }
            power[i] = count;
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            int sum = 0; 
            for(int j = i ; j < n ; j++){
               sum += power[j];
               if(sum != 1){
                   count++;
               }
            }
        }
        cout << count << '\n';
    }
}