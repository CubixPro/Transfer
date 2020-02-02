#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int arr[3];
        for(int i = 0 ; i < 3 ; i++){
            scanf("%d", &arr[i]);

        }
        int n;
        scanf("%d", &n);
        sort(arr, arr + 3);
        int val = arr[1] - arr[0] + 2 * (arr[2] - arr[1]);
        int vf = n - val;
        if(vf < 0){
            printf("NO");

        }
        else if(vf % 3 == 0){
            printf("YES");
        }
        else 
        {
            printf("NO");
        }
        printf("\n");
        /*


       int q;
       scanf("%d", &q);
       vector<int> arr[1001];
       while(q-- != 0){
           int x, y;
           scanf("%d %d", &x, &y);
           arr[x].push_back(y);
       }
       vector<int> nonemp;
       for(int i = 0 ; i <= 1000 ; i++){
           if(!arr[i].empty()){
               sort(arr[i].begin(), arr[i].end());
               nonemp.push_back(i);
           }
       }
       
       string path = "";
       bool check = true;
       for(int i = 1 ; i <= nonemp[0] ; i++){
           path += "R";
       }
       for(int i = 1 ; i <= arr[nonemp[0]].back() ; i++){
           path += 'U';
       }
       if(nonemp.size() >= 2){ 
       for(int i = 1 ; i <= (nonemp[1] - nonemp[0])  ; i++){
           if(arr[nonemp[1]][0] >= arr[nonemp[0]].back()){
               
           path += 'R';
           }
           else
           {
               check = false;
           }
           

       }
        for(int i = 1 ; i < nonemp.size() - 1 ; i++){
            if(arr[nonemp[i]].back() <= arr[nonemp[i + 1]][0]){
                for(int j = 1 ; j <= arr[nonemp[i]].back() - arr[nonemp[i - 1]].back() ; j++){
                    path += 'U';
                }
                
            }
            else
            {
                check = false;
                break;
            }
            
            for(int j = nonemp[i + 1] ; j > nonemp[i] ; j--){
                path+='R';
            }
        }
       
       for(int j = 1 ; j <= arr[nonemp[nonemp.size() - 1]].back() - arr[nonemp[nonemp.size() - 2]].back() ; j++){
                    path += 'U';
                }
       }
        if(check == false){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            cout << path << '\n';
        }
      */ 
    }
}