#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
int gcd(int a, int b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
  
   
// Function to return LCM of two numbers  
  int lcm(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  
int main(){
    cases{
        int n, m;
        cin >> m >> n;
        int arr[m];
        bool contain[n + 1];
        memset(contain, false, sizeof(contain));
        for(int i = 0  ; i < m ; i++){
            cin >> arr[i];
            contain[arr[i]] = true;
        }
        int lcm_val = 1;
        for(int i = 0 ; i < m ; i++){
            lcm_val = lcm(lcm_val, arr[i]);
        }
        int max = lcm_val;
        int add = 1;
        for(int i = 2 ; i <= n ; i++){
            if(contain[i] == false)
            {
                int temp = lcm(lcm_val, i);
                if(temp > max){
                    max = temp;
                    add = i;
                }
            }
        }
        cout << add << '\n';
    }
}