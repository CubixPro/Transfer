#include<bits/stdc++.h>
using namespace std;
 bool isValid(string s) {
        stack<char> st;
        bool found = true;
        for(int i = 0; i < s.length() ; i++){
            char c = s[i];
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                char ch = st.top();
                st.pop();
                if(c == '}'){
                    c = '{';
                }
                else if(c == ']'){
                    c = '[';
                }
                if(c == ')'){
                    c = '(';
                } 
                if(ch != c){
                    found = false;
                    break;
                }
                
            }
        }
        if(!st.empty())
            found = false;
       return found;
    }
    int main(){
        cout << isValid("()");
    }