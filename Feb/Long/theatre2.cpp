#include<bits/stdc++.h>

using namespace std;

int main(){
     string perm[24] = {"abcd", "abdc", "acbd", "adbc", "acdb", "adcb", "bacd", "badc", "cabd", "dabc", "cadb", "dacb", "bcad", "bdac", "cbad", "dbac", "cdab", "dcab", "bcda", "bdca", "cbda", "dbca", "cdba", "dcba"};
     int testcases;
    scanf("%d", &testcases);
    int total_val = 0;
    while(testcases-- != 0){
        int n;
        scanf("%d", &n);
        if(n == 0){
            cout << -400 << '\n';
            total_val = total_val - 400;
            continue;
        }
        int arr[4][4]; 
        int count = 0;
        memset(arr, 0, sizeof(int)*16);
        int a = 0, b = 0, c = 0, d = 0;
        for(int i = 1; i <= n ; i++){
            pair<char, int> np;
            cin >> np.first >> np.second; 
            arr[np.first - 65][np.second/3 - 1]++;
        }
        int max = -400;
        for(int i =  0 ; i < 24 ; i++){
            int count = 0;
            int cost[4] = {25, 50, 75, 100};
            int times[4];
            for(int j = 0 ; j < 4 ; j++){
                times[j] = arr[perm[i][j] - 97][j];
                //cout << count << '\n';
            }
            sort(times, times + 4);
            for(int j = 0 ; j < 4 ; j++){
                if(times[j] == 0){
                    count -= 100;
                }
                else{
                    count += times[j]*cost[j];
                }
            }
            if(count > max){
                max = count;
            }
        }
        cout << max << "\n"; 
        total_val += max;
}
        cout << total_val << "\n"; 
}