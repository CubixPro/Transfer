#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long int lld;

lld power(lld x,  lld y,  lld m) 
{ 
    if (y == 0) 
        return 1; 
    lld p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
 
lld modInverse(lld a, lld m) 
{ 
    return power(a, m-2, m); 
} 
  
// To compute x^y under modulo m 
 

int main(){
    //cout << ((8 * (modInverse(30, mod)%mod))%mod);
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int length;
        string str;
        cin >> length;
        cin >> str;
        lld total = length*(length - 1)/2 + length;
        lld count = 0;
        for(int i = 0 ; i < length ; i++){
            for(int j = i ; j < length ; j++){
                lld countl = 0;
                lld countr = 0;
                for(int k = i ; k <= j ; k++){
                    if(str[k] == '('){
                        countl++;
                    } 
                    else if(str[k] == ')'){
                        countr++;
                    }
                    if(countr > countl){
                        count++;
                        //cout << i << ' ' << j << '\n';
                        countl++;
                        countr--;
                    }
                }
            }
        }
        cout << count << '\n';
        cout << (count * modInverse(total, mod))%mod << '\n';
    }

}