#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef  long long int llu;

llu power(llu x, llu y) 
{ 
    llu res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = ((res%mod)*(x%mod))%mod; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = ((x%mod)*(x%mod))%mod;  // Change x to x^2 
    } 
    return res; 
}
int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        llu n, m;
        scanf("%lld %lld", &n, &m);
        llu final_val;
        if(n >= 3)
        {
            final_val = power(m, n)%mod;
            llu counter = 0;
            for(llu i = n - 3; i >= 0 ; i-- )
            {    counter += (((m%mod) * (power(m - 1, i)%mod))%mod);
                counter = counter%mod;
            }
            final_val = (final_val - counter + mod)%mod;
        }
        else
        {
           final_val = power(m, n)%mod;
        }
       printf("%lld\n", final_val); 
    }
}