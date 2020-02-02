#include<bits/stdc++.h>

using namespace std;

int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase-- != 0){
        int n;
        scanf("%d", &n);
        int arr[n][3];
        for(int i = 0 ; i < n ; i++){
            scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
        }
        int finalval[n];
        for(int i = 0 ; i < n ; i++){
            finalval[i] = (int)(arr[i][1]/(1 + arr[i][0])) * arr[i][2];
        }
        sort(finalval, finalval + n);
        cout << finalval[n - 1] << '\n';
    }
}