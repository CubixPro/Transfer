#include<bits/stdc++.h>

 using namespace std;

int main(){
    int test;
    //scanf("%d", &test);
    cin >> test;
    while(test-- != 0){
        string str;
        cin >> str;
        int counter = 'j' - str[0];
        string news = "j";
        for(int i = 1 ; i < str.length() ; i++){
            int newchar = (str[i] + counter - 97);
            if(newchar<0){
                newchar = (newchar+26)%26 + 97;
            }
            else{
                newchar = (newchar)%26 + 97;
            }

            news += newchar;
        }
        cout << news << '\n';
        
    }
}