#include<bits/stdc++.h>
#include<string.h>

using namespace std;
int perm_length;
int str_length;
fstream f;

void permutations(string str, string perm, int i, int x){
    if(i == perm_length){
            f << perm << '\n';
        return ;
    }
    else if(x == str_length){
        return ;
    }
    else {
        char curr = str[x];
        for(int ni = 0 ; ni < perm_length ; ni++){
            if(perm[ni] == ' '){
                perm[ni] = curr;
                permutations(str, perm, i + 1, x + 1);
                perm[ni] = ' ';
            }
        }
        permutations(str, perm, i, x + 1);
    }
}
int main(){
    perm_length = 6;
    str_length = 10;
    f.open("permutations.txt", ios::app);
    permutations("abcdefghij", "      ", 0, 0);
    f.close();
}