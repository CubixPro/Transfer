#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;

int main(){
    lld testcases;
    scanf("%lld", &testcases);
    while (testcases-- != 0)
    {
        lld n, g, b;
        scanf("%lld %lld %lld", &n, &g, &b);
        lld days = 0;
        lld count = (n%2 == 0)?n/2:(n/2 + 1);
        if(count <= g){
            printf("%lld", n);
        } 
        else{
            if(count%g == 0){
                lld val = (count/g)*(g + b) - b;
                if(val >= n)
                    printf("%lld", val);
                else{
                    printf("%d", &n);
                }
            }
            else{
                lld ans = (count/g)*(g + b);
                if(ans > n){
                    ans += (count - (count/g)*g);
                }
                else {
                    ans += (n - (count/g)*(g + b));
                }
            printf("%lld", ans);
            }
        }
        printf("\n");
    }
    
}