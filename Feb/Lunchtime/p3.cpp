#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main(){
    int testcases;
   cin >> testcases;
    while(testcases-- != 0){
       int n;
       string str;
       cin >> n;
       cin >> str;
       
       bool left = true;
       bool right = true;
       bool check = true;
       int count = 0;
       if(str.length() == 2){
           if(str[0] == str[1]){
               count = 0;
           }
           else{
               check = false;
           }
           if(check)
       cout << "YES" << '\n';
       else{
           cout << "NO" << '\n';
       }
        
        if(check){
            cout << count << '\n';
        }
       }
       else{
           int steps = (n % 2 == 0)?(n/2 - 1):(n/2);
       for(int i = 0 ; i < steps ; i++){

           if(str[i] == str[n - i - 1]){
               continue;
           }
           else{
               if(str[i] == str[n - i - 2]  && right){
                   if(right){
                   right = false;
                   char temp = str[n - i - 1];
                   str[n - i - 1] =str[n - i - 2];
                   str[n - i - 2]  = temp;
                   count++;
                   continue;
                   }
                   
               }
               else if(right == false){
                   right = true;
               }
               if(str[i + 1] == str[n - i - 1] && left){
                   left = false;
                   char temp = str[i + 1];
                   str[i + 1] = str[i];
                   str[i] = temp;
                   count++;
               }
               else if(left == false){
                   left = true;;
               }

                if(str[i] != str[n - i - 1])
                {
                    check = false;
                    break;
                }
           }
       }
       if(str[steps] != str[steps + 1] && n%2 == 0){
           check  = false;
       }
       if(check)
       cout << "YES" << '\n';
       else{
           cout << "NO" << '\n';
       }
        
        if(check){
            cout << count << '\n';
        }
    }
    }
}