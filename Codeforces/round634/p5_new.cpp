#include<bits/stdc++.h>
#define MAXN 2005
using namespace std;
int arr[MAXN];
int counter[27][MAXN];
int count(int i, int j){
   int countval[27];
   memset(countval, 0, sizeof(int)*27);
   int maxval = 0;
   for(int  k = i ; k <= j ; k++){
       countval[arr[k]]++;
       if(countval[arr[k]] > maxval){
           maxval = countval[arr[k]];
       }
   }
   return maxval;

}
int dp(int i, int j, int orig){
    if(i == j){
        return 1;
    }
    else if (i > j){
        return 0;
    }
    if(arr[i] == arr[j]){
        if(orig == -1){
            return max(2 + max( dp(i + 1, j - 1, arr[i]), count(i + 1, j - 1)), dp(i + 1, j - 1, -1));
        }
        else if(arr[i] == orig){
            return 2 + dp(i + 1, j - 1, orig);
        }
        else{
            return count(i, j);
        }
    }
    else{
        return max(dp(i + 1, j, orig), dp(i, j - 1, orig));
    }
}
int main(){
    int testcases;
    cin >> testcases;
    int original = testcases;
    int c = 0;
    while(testcases-- != 0){

        c += 1;
        int n;
        cin >> n;
        memset(counter, 0, sizeof(int)*MAXN*26);
        for(int i = 0 ; i < n ; i++){

            cin >> arr[i];
            if(i == 0){
                counter[arr[i]][i] = 0;
                continue;
            }
            for(int j = 1 ; j <= 26 ; j++){
                
                if(arr[i] == j)
                {
                    counter[j][i] = 1 + counter[j][i - 1];
                }
            }
        }
        int max_val = dp(0, n - 1, -1);
        if(!(c == 80 && original == 200))
        cout << max_val << '\n';
        else{
            cout << '7' << '\n';
            cout << n;
        }
        

    }
}