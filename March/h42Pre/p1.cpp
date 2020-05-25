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
 cases
 {
     lld n;
     cin >> n;
     lld arr1[n];
     lld arr2[n];
     lld sum = 0;
     for(lld i = 0 ; i < n; i++){
         cin >> arr1[i];
     }
     for(lld i = 0; i < n  ; i++){
         cin >> arr2[i];
     }
     int count1 = 0;
     int count2 = 0;
     int max = 0;
     for(int i = 0 ; i < (pow(2, n) ) ; i++){
         int counta = 0;
         int countb = 0;
         int sum = 0;
         bool check = true;
         for(int j = 1 ; j <= n ; j++){
                
             if(i & (1 << (j-1)) != 0){
                 
                 counta++;
                 if(counta <= 3){
                 countb  = 0;
                    sum += arr1[j - 1];
                 }
                 else{
                     check  = false;
                     break;
                 }
             }
             else{
                 countb++;
                 if(countb <= 3){
                 counta = 0;
                 sum += arr2[j - 1];
                 }
                 else{
                     check = false;
                     break;
                 }
             }
         }
         if(check){
             if(sum >= max){
                 max = sum;
             }
         }
     }
     cout << max << '\n';
 }
}