#include<bits/stdc++.h>
#include<string.h>

using namespace std;
int comb_length;
int str_length;
fstream f;

void combinations(string str, string comb, int i, int x){
    if(i == comb_length){
            f << comb << '\n';
        return ;
    }
    else if(x == str_length){
        return;
    }
    else {

       char ch = str[x];
       comb[i] = ch;
       combinations(str, comb, i + 1, x + 1); 
       comb[i] = ' ';
       combinations(str, comb, i, x + 1);

    }
}
int main(){
    comb_length = 2;
    str_length = 4;
    f.open("combinations.txt", ios::app);
    combinations("abcd", "  ", 0, 0);
    f.close();
}