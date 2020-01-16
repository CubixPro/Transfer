#include<bits/stdc++.h>

using namespace std;


int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int w[3];
        int s;
        scanf("%d %d %d %d", &s, &w[0], &w[1], &w[2]);
        int count = 0;
        int add = 0;
        for(int i = 0 ; i < 3 ; i++){
            add += w[i];
            if(add > s){
                add = 0;
                i--;
                count++;
            }
        }
        count++;
        cout << count << '\n';

    }
}