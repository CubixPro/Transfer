#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, q;
    int arr1[n];
    int arr2[m];
    int count1[10000][n];
    int count2[10000][m];
    memset(count1, 0, (10000 * n * sizeof(int)));
    memset(count2, 0, sizeof(int) * m * 10000);
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0 ;  i < n ; i++){
        scanf("%d", &arr1[i]);
       {
            count1[arr1[i]][i]++;
        }

    }
    for(int j = 0 ; j < n ; j++){
        scanf("%d", &arr2[j]);
       {
            count1[arr1[j]][j]++;
        }
    }
    for(int i = 0 ; i < 10000 ; i++){
        for(int j = 1 ; j < n ; j++){
            count1[i][j] += count1[i][j - 1];
        }
    }
    for(int i = 0 ; i < 10000 ; i++){
        for(int j = 1 ; j < m ; j++){
            count2[i][j] += count2[i][j - 1];
        }
    }
    while(q-- != 0){
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        
    }
}