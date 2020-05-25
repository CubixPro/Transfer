#include<bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int arr[n];
        bool found = false;
        int val1 = -1;
        int val2 = -1;
        int val3 = -1;
        for(int i = 0 ; i < n ; i++){
            scanf("%d", &arr[i]);
        } 
        if(k%arr[0] != 0){
            found = true;
            val3 = arr[0]; 
        }
        else{
            for(int i = 1 ; i < n ; i++){
                if(k%arr[i] != 0){
                    val3 = arr[i];
                    found = true;
                    break;
                }
                if(arr[i]%arr[i - 1] != 0){
                    val1 = arr[i];
                    val2 = arr[i - 1];
                    found = true;
                    break;
                }
            }
        }

        if(!found){
            printf("NO\n");
        }
        else{
            printf("YES ");
            if(val3 != -1){
                for(int i = 0 ; i < n ; i++){
                    if(arr[i] == val3){
                        printf("%d", (k/val3 + 1));
                    }
                    else{
                        printf("%d", 0);
                    }
                    printf(" ");
                }
                printf("\n");
            }
            else{
                int ans1 = k/val1 - 1;
                int ans2 = (k - ans1 * val1)/val2 + 1;
                for(int  i = 0 ; i < n ; i++){
                    if(arr[i] == val1){
                        printf("%d", ans1);
                    }
                    else if(arr[i] == val2){
                        printf("%d", ans2);
                    }
                    else{
                        printf("0");
                    }
                    printf(" ");
                }
                printf("\n");
            }
        }
    }
}