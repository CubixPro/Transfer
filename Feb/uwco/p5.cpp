#include<bits/stdc++.h>
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
        int n;
        scanf("%d", &n);
        int max = 0;
        for(int i  = 0 ; i < n ; i++){
            int val ;f1();
            f2();
            scanf("%d", &val);
            if(val >= max){
                max = val;
            }
            f3();
        }
        printf("%d\n", max);
    }
}