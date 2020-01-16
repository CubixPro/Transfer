#include<bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    //scanf("%d", &testcases);
    //while(testcases-- != 0){
        int n, m;
        scanf("%d %d", &n, &m);
        long int arr[n];
        bool peak[n];
        int total_peaks[n];
        for(int i = 0 ; i < n  ; i++){
            scanf("%d", &arr[i]);
            total_peaks[i] = 0;
        }
        peak[0] = true;
        peak[n - 1] = true;
        for(int i = 1 ; i < n - 1 ; i++){
            if((arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) || (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]))
            {
                peak[i] = true;
            }else{peak[i] = false;}
        }
        total_peaks[0] = 1;
        for(int i = 1 ; i < n ; i++){
            if(peak[i] == true){
                total_peaks[i] = total_peaks[i - 1] + 1;
            }else{total_peaks[i] = total_peaks[i - 1];}
        }
        while(m-- != 0){
            int p, q;
            scanf("%d %d", &p, &q);
            int sum = total_peaks[q - 2] - total_peaks[p - 1];
            if(sum % 2 == 1)
                printf("YES\n");
            else
            {
                printf("NO\n");
            }
            
        }
    }     
