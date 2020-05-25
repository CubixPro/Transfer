#include<bits/stdc++.h>


using namespace std;
typedef long  int lld;
lld mod = 1000000007;

lld dp[10000001];
lld power(lld x, lld y, lld c) 
{ 
    
        lld res = 1; // Initialize result 
  
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = ((res%c) * (x%c))%c; 
  
        // n must be even now 
        y = y >> 1; // y = y/2 
        x = ((x%c) * (x%c))%c; // Change x to x^2 
    } 
    return res; 
} 
  
lld modInverse(lld a, lld m) 
{ 
    return power(a, m-2, m); 
} 
  
// To compute x^y under modulo m 
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << ((8 * (modInverse(30, mod)%mod))%mod);
    lld testcases;
    cin >> testcases;
    while(testcases-- != 0){
        lld length;
        string str;
        cin >> length;
        cin >> str;
        lld total = (length*(length - 1))/2 + length;
        lld count = 0;
        lld i = length - 1;
        unordered_map<lld, lld> left;
        unordered_map<lld, lld> right;
        //lld left[100001];
        //lld right[100001];
        stack<lld> lb;
        stack<lld> rb;
        for(lld j = i ; j >= 0 ; j--){
                char ch = str[j];
                if(ch == ')'){
                    if(rb.empty()){
                        //right.insert(make_pair(j, -1));
                        right[j] = -1;
                        rb.push(j);
                    }
                    else{
                        //right.insert(make_pair(j, rb.top()));
                        right[j] = rb.top();
                        rb.push(j);
                    }
                }
                else if(ch == '('){
                    if(!rb.empty()){
                        //left.insert(make_pair(j, rb.top()));
                        left[j] = rb.top();
                        rb.pop();
                    }
                    else{
                        //left.insert(make_pair(j, -1));
                        left[j] = -1;
                    }
                }
            }
            
            memset(dp, 0, sizeof(lld) * (i + 1));
            for(lld j = i ; j >= 0 ; j--){
                char ch = str[j];
                if(ch == ')'){
                    if(j == i){
                        dp[j] = 1%mod;
                        count += dp[j];
                        count = count%mod;
                        //continue;
                    }
                    else{
                        lld val = right[j];
                        if(val != -1 && !(val >= i)){
                            dp[j] = 1 + (val - j) + (length - val - 1) + dp[val + 1];
                            
                        }
                        else{
                            dp[j] = 1 + (length - 1 - j);
                            
                        }
                        dp[j] = dp[j]%mod;
                        count += dp[j];
                        count = count%mod;
                    }

                }
                else if(ch == '('){
                    if(j == i){
                        dp[j] = 0;
                    }
                    lld val = left[j];
                    if(val == -1 || val >= i)
                    {
                        dp[j] = 0;
                    }
                    else{
                        dp[j] = dp[val + 1]%mod;
                        count += dp[j];
                        count = count%mod;
                    }
                }
                else{
                    if(!(j == i)){
                        dp[j] = dp[j + 1]%mod;
                        count += dp[j];
                        count = count%mod;
                    }
                    else{
                        dp[j] = 0;
                    }
                }
                //cout << count << '\n';

            }

         lld ans = count * power(total, mod - 2, mod)%mod ;
         cout << ans << '\n';
    }

}