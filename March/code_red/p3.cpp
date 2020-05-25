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
     int n;
     cin >> n;
     int arr[n];
     for(int i = 0 ; i < n ; i++){ 
         cin >> arr[i];
     }
     sort(arr, arr + n);
     int count = n;
     for(int i = 0 ; i < n - 1 ; i++)
     {
         if(arr[i] == arr[i + 1]){
             count--;
         }
     }
     cout << count << '\n';
 }
}