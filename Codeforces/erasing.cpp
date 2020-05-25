#include<bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int count = 0;
        int start = 0; 
        int end;
        string p;
        cin >> p; 
        end = p.length() - 1;
        for(int i = 0 ; i <= end ; i++){
            if(p[i] == '0'){
                start++;
            }
            else{
                break;
            }
        }
        
        for(int i = p.length() - 1 ; i >= 0 ; i--){
            if(p[i] == '0'){
                end--;
            }
            else{
                break;
            }
        }
        for(int i = start ; i <= end ; i++){
            if(p[i] == '0'){
                count++;
            }
        }
        cout << count << '\n';
    }
}