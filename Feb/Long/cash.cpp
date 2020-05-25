#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;

int main(){
    int testcases;
    cin >> testcases;
    while(testcases-- != 0){
        int n, k;
        cin >> n >> k;
        lld arr[n];
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        lld take[n];
        memset(take, 0, sizeof(take));
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                take[i] = arr[i]%k;
            }
            else{
                take[i] += arr[i]%k + take[i - 1];
            }
        } 
        lld give[n];
        memset(give, 0, sizeof(give));
        for(int i = n - 1 ; i >= 0 ; i--){
            if(i == (n - 1)){
                if(arr[i]%k == 0){continue;}
                give[n - 1] = k - arr[i]%k;
            }
           else{ 
               if(arr[i]%k == 0){
                   give[i] += give[i + 1];
                   continue;
               }
            give[i] += (k - arr[i]%k + give[i + 1]);
           }
        }
        //cout << n;
        int r = -1;
        for(int i = 0 ; i < n - 1 ; i++){
            if(take[i] >= give[i + 1] && ((r != -1 && r > (take[i] - give[i + 1]))||(r == -1))){
                r = take[i] - give[i + 1];
            }
        }
        if((take[n - 1] < r && r!= -1) || (r == -1)){
            r = take[n - 1];
        } 
        cout << r << '\n';
    }

}