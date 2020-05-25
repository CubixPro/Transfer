#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;


int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int n, d;
        scanf("%d %d", &n, &d);
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &arr[i]);
        }
        int count = 0;
        for(int i = 1 ; i < n ; i++){
            int days = arr[i]*i;
            if(days <= d){
                count += arr[i];
                d = d - days;
            }
            else{
                count += (d/i);
                d  = 0;
                break;
            }
        }
        count += arr[0];
        printf("%d\n", count);
    }
}