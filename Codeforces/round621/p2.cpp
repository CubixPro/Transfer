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
            bool exact = false;
            for(int i = 0 ; i < n ; i ++){
                scanf("%d", &arr[i]);
                if(arr[i] == d){
                    exact = true;
                }
            }
            sort(arr, arr + n, greater<int>());
            if(exact){
                printf("1\n");
            }
            else{
                if(arr[0] > d){
                    printf("2\n");
                }
                else{
                    int val =(d%arr[0] == 0)?d/arr[0]:(d/arr[0] + 1);
                    printf("%d\n", val);
                }
            }
    }
}