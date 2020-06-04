#include<bits/stdc++.h>
using namespace std;
 int longestValidParentheses(string s) {
     int len = s.length();
      int dp[len];
       memset(dp, 0, sizeof(int)* len);
       if(len == 0){
           return 0;
       }
        int maxval = 0;
       if(s[0] == '('){
           dp[0] = 1;
       }
        else {
            dp[0] = -1;
        }
        for(int i = 1 ; i < len ; i++){
            if(s[i] == '(' && dp[i - 1] > 0){
                dp[i] = 1 + dp[i - 1] ;
            }
            else if(s[i] == '(' )
            {
                dp[i] = 1;
            }
            else{
                dp[i] = -1 + dp[i - 1];
            }
        }
        for(int i = 0 ; i < len ; i++){
            if(dp[i] > 0){
                int index = -1;
                for(int j = i ; j < len ; j++){
                   if(dp[j] == 0){
                       index = j;
                   } 
                    if(dp[j] == -1){
                        index = -1;
                    }
                }
                if(index != -1){
                    maxval = max(index - i + 1, maxval);
                }
            }
        }
          string news = s;
        s = "";
        for(int i = len - 1; i >= 0 ; i-- ){
            if(news[i] == '('){
                s = s + ')';
            }
            else{
                s = s + '(';
            }
        }
       
           memset(dp, 0, sizeof(int)* len);
        if(s[0] == '('){
           dp[0] = 1;
       }
        else {
            dp[0] = -1;
        }
        for(int i = 1 ; i < len ; i++){
            if(s[i] == '(' && dp[i - 1] > 0){
                dp[i] = 1 + dp[i - 1];
            }
            else if(s[i] == '('){
                dp[i] = 1;
            }
            else{
                dp[i] = -1 + dp[i - 1];
            }
        }
        for(int i = 0 ; i < len ; i++){
            if(dp[i] > 0){
                int index = -1;
                for(int j = i ; j < len ; j++){
                   if(dp[j] == 0){
                       index = j;
                   } 
                    if(dp[j] == -1){
                        break;
                    }
                }
                if(index != -1){
                    maxval = max(index - i + 1, maxval);
                }
            }
        }
        
      return maxval ;  
    } 
    int main(){
        cout << longestValidParentheses(")()())");
    }