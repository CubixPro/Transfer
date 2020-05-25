#include<bits/stdc++.h>
using namespace std;
bool prime(int i){
    for(int j = 2 ; j <= sqrt(i) ; j++){
        if(i % j == 0){
            return false;
        }
    }
    return true;
}
int digits(int n){
    int count = 0;
    while(n!=0){
        count++;
        n = n / 10;
    }
    return count;
}
bool contains(int n, int digit){
    while(n!=0){
        if(digit == (n%10)){
            return true;
        }
        n = n / 10;
    }
    return false;
}
int digit_sum(int n){
    int count = 0;
    while(n != 0){
        count += n%10;
        n = n/10;
    }
    return count;
}
int main(){
    for(int i = 1 ; ; i++){
        if((pow((int)(sqrt(i)), 2) == i ^ i%7 == 0)){
            if(prime(i + 1) ^ (digits(i)==2)){
                if(pow((int)(sqrt(i + 1)), 2) == (i + 1) ^ digits(i) > 2){
                    if(contains(i, 8) ^ contains(i , 3)){
                        if(i % 11 == 0 ^ prime(digit_sum(i))){
                            cout << i << '\n';
                            break;
                        }
                    }
                } 
            }
        }
    }
}
