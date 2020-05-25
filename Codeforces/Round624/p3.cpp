#include<bits/stdc++.h>


using namespace std;
typedef long long int lld;

int main(){
    int testcases;
    cin >> testcases;
    while(testcases-- != 0){
        int a, b, c;
        int max = INT16_MAX;
        scanf("%d %d %d", &a, &b, &c);
        int nnewa, nnewb, nnewc;
        for(int i = 1 ; i <= 10000 * 2 ; i++){
           int count = abs(a - i) ;
            int newb = (b/i)*i;
            if(newb != 0){
            int newc = (c/newb)*newb;
            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            }
            newc = (c/newb + 1)*newb;
            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                 max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            
            }newc = (c/newb - 1)*newb;
            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                 max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            
            }
            }
            newb = (b/i - 1)*i;
            if(newb != 0){
                 int newc = (c/newb)*newb;

            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            }
            newc = (c/newb + 1)*newb;
            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                 max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            
            }newc = (c/newb - 1)*newb;
            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                 max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            
            }
            }
            newb = (b/i + 1)*i;
            if(newb != 0){
            int newc = (c/newb)*newb;

            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            }
            newc = (c/newb + 1)*newb;
            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                 max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            
            }newc = (c/newb - 1)*newb;
            count = abs(a - i) + abs(b - newb) + abs(c - newc);
            if(count < max){
                 max  = count;
                nnewa = i;
                nnewb = newb;
                nnewc = newc;
            
            }


        }
        }
        printf("%d\n", max);
        printf("%d %d %d\n", nnewa, nnewb, nnewc);
    }
}