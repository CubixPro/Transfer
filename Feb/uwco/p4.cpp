#include<bits/stdc++.h>
typedef long long int lld;
void f1(){
    int x;
}
void f2(){
    int x;
}
void f3(){
    int x;
}
int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        lld n;
        scanf("%lld", &n);
        lld arr[n];
        lld co = 0;
        lld ce = 0;
        for(lld i = 0 ; i < n ; i++){
            scanf("%lld", &arr[i]);
            if(arr[i]%2 == 0){
                f2();
                f2();
                co++;
            }
            else{
                f1();
                f1();
                f1();
                ce++;
            }
        }
        lld prod = co * ce;
        f3();
        printf("%lld\n", prod);
    }
}