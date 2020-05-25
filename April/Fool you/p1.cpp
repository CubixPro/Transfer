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
       int count = 0;
       bool prime[100000+5]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<100005 ;  p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
       for(int i = 2 ; i <= n ; i++){
           if(prime[i])
                count++;
       } 
       cout << count << '\n';
    }
}