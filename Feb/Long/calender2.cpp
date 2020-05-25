#include<bits/stdc++.h>

using namespace std;

int years[101] = {3, 9, 14, 15, 20, 25, 26, 31, 37, 42, 43, 48, 53, 54, 59, 65, 70, 71, 76, 81, 82, 87, 93, 98, 99, 105, 110, 111, 116, 121, 122, 127, 133, 138, 139, 144, 149, 150, 155, 161, 166, 167, 172, 177, 178, 183, 189, 194, 195, 200, 201, 206, 207, 212, 217, 218, 223, 229, 234, 235, 240, 245, 246, 251, 257, 262, 263, 268, 273, 274, 279, 285, 290, 291, 296, 302, 303, 308, 313, 314, 319, 325, 330, 331, 336, 341, 342, 347, 353, 358, 359, 364, 369, 370, 375, 381, 386, 387, 392, 397, 398};

int main(){
    int testcases;
    map<int, int> counter;
    for(int i = 0 ; i < 101 ; i++){
        counter.insert(make_pair(years[i], i));
    }
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int m1, y1, m2, y2;
        scanf("%d %d", &m1, &y1);
        scanf("%d %d", &m2, &y2);
        int count = 0;
        if(m1 > 2){
            y1++;
        }
        if(m2 < 2)
        {
            y2--;
        }
        if((y2 - y1) < 400){

           for(int i = y1 ; i <= y2 ; i++){
               if(counter.find(i%400) != counter.end() ){
                   count++;
               }
           } 
            
        }
        else{
           count += 101*((y2 - y1)/400);
           y1 += ((y2 - y1)/400)*400;
           //y1++;
           //cout << y1;
           for(int i = y1 ; i <= y2 ; i++){
               if(counter.find(i%400) != counter.end()){
                   count++;
               }
           }
        }
        printf("%d\n", count);
    }
}