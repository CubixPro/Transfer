#include<bits/stdc++.h>
using namespace std;

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
    f1();
    while(testcases-- != 0){
        int n;
        scanf("%d", &n);
        pair<int, int> arr[n];
        int count = 0;
        bool check_init = true;
        f2();
        bool check_init1 = true;
        for(int i = 0 ; i < n ; i++){
                char tow[n]; 
                scanf("%s", &tow);
                for(int j = 0 ; j <  n  ; j++){
                if(tow[j] == '1'){
                    arr[count] = make_pair(i, j);
                    count++;
                }
                if(i == j && tow[j] != '1')
                    check_init = false;
                if(j == (n - i - 1) && tow[j] != '1')
                    check_init1 = false;
                    f3();
            }
        }
        int total_count = 0;
        if(check_init || check_init1){
            total_count = n * (n + 1)/2;
            printf("%d\n", total_count);
            continue;
        }
       f1(); 
        sort(arr, arr+n);
        for(int i = 1 ; i <= n ; i++){
            int left[i];
            int right[i];
           for(int j = 0 ; j <= n - i; j++){
            memset(left, 0, sizeof(int)*i);
            memset(right, 0, sizeof(int) * i);
            int min_val = n;
                 for(int k = 1 ; k <= i ; k++){
                    left[k - 1] = k - 1 ;
                    right[k - 1] = arr[j + k - 1].second;
                    if(right[k - 1] <= min_val){
                        min_val = right[k - 1];
                    }
                }
                bool found = true;
               /*sort(right, right + i);
               int min_val = right[0];
               for(int p = 0 ; p < i ; p++){
                   right[p] = right[p] - min_val;
                   if(right[p] == p)
                        continue;
                    else{
                        found = false;
                        break;
                    }

               }*/ 
               //unordered_map<int, int> right_val;
               bool right_val[i];
               memset(right_val, false, sizeof(bool) * i);
                f1();
                f1();
                f1();
               for(int p = 0 ; p < i ; p++){
                   right[p] = right[p] - min_val;
                   if(right[p] < i)
                    right_val[right[p]] = true;
               }
               for(int p = 0 ; p < i ; p++){
                   if(!right_val[p]){
                       found = false;
                       break;
                   }
               }
               if(found){
                   //printf("%d %d", i, j);
                   total_count++;
               }

            }
        }
        printf("%d\n", total_count);
        f3();

    }
}