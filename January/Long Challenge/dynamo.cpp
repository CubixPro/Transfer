#include<bits/stdc++.h>

typedef unsigned long long int llu;

using namespace std;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int n;
        scanf("%d", &n);
        llu final_sum ;
        llu a, b, c, d, e;
        scanf("%llu", &a);
        final_sum =  2 * (pow(10, n))  ;
        final_sum = final_sum + a;
        printf("%llu\n", final_sum);
        cout << flush;
        scanf("%llu", &b);
        c = pow(10, n) ;
        c = c - b;
        printf("%llu\n", c);
        cout << flush;
        scanf("%llu", &d);
        e = pow(10, n) ; 
        e = e - d;
        printf("%llu\n", e);
        cout << flush;
        int res;
        scanf("%d", &res);
        if(res == -1)
            break;
    }
}