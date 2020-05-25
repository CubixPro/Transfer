#include<bits/stdc++.h>


using namespace std;
typedef long long int lld;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int a, b;
        scanf("%d %d", &a, &b);
        int val = b - a;
        if(val == 0){
            printf("0\n");
        }
        else if((val > 0 && val%2 == 1) || (val < 0 && val%2 == 0) )
        {
            printf("1\n");
        }
        else{
            printf("2\n");
        }

    }
}