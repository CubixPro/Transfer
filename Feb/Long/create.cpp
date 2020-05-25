#include<bits/stdc++.h>

using namespace std;

int main(){
    string str = "";
    fstream f;
    f.open("string.txt", ios::app);

    for(int i = 1; i <= 100000 ; i++){
        int val = rand()*10;
        val = val%3;
        if(val == 0){
            str += '*';

        }
        else if(val == 1){
            str += ')';
        }
        else{
            str += '(';
        }
    }
    f << str;
    f.close();
}