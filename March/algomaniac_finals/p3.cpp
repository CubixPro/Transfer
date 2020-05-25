#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
int main()
{
 fast;
// cases
 {
     int n, k;
     cin >> n >> k;
     int arr[n];
     for(int i = 0 ; i < n ; i++){
         cin >> arr[i];
     }

     int sum = 0;
     for(int i  = 0 ; i < k ; i++){
        sum = (sum + arr[i])%2;
     }
     int count_0  = 0;
     int total = 0;
     for(int i = 0 ; i < n ; i++){
         if(arr[i] == 0){
             count_0++;
         }
         if(arr[i] == 1 || count_0 == (2 * k - 1)){
             //if(count_0 <= (2 * k - 1)){
                 {
                 arr[i - count_0/2 - 1] = 1;
                 //cout << count_0 << '\n';
                  //i = (i - count_0/2 + 1);
                 total++;
             }
             count_0 = 0;
         }
     }
     
     //cout << sum << '\n';
     if(sum == 0){
        total++;
        sum++; 
        arr[0] = (arr[0] == 1)?0:1;
     }
     for(int i = k ; i < n ; i++){
         //sum = (sum + arr[i] - arr[i - k])%2;
         if(arr[i] == 1){
             sum = (sum + 1)%2;
         }
         if(arr[i - k] == 1){
             sum = (sum + 1)%2;
         }
     cout << sum << '\n';
         if(sum == 0){
             total++;
             sum = 1;
             //arr[i] = ~arr[i];
          arr[i] = (arr[i] == 1)?0:1;
}
}
     cout << total << '\n';

 }
} 