#include<bits/stdc++.h>
using namespace std;
class Solution {
   set<string> strs; 
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                left++;
            }
            else if(s[i] == ')'){
                if(left >= 1){
                    left--;
                }
                else{
                    right++;
                }
            }
        }
        stack<char> b;
        vector<string> v;
        valid(s, left, right, 0, b, "");
        set<string> :: iterator it = strs.begin();
        while(it != strs.end()){
            v.push_back(*it);
            it++;
        }
        return v;
    }
    void valid(string s, int left, int right, int i, stack<char> b, string str){
       if(i == s.length() && left == 0 && right == 0){
           if(b.empty())
            strs.insert(str);
           return ;
       } 
        else if(i == s.length()){
            return ;
        }
       char ch = s[i];
        if(ch == '('){
            if(left > 0){
                valid(s, left - 1, right, i + 1, b, str);
                b.push(ch);
                valid(s, left, right, i + 1, b, str + ch);
                b.pop();
            }
            else if(left == 0){
                 b.push(ch);
                valid(s, left, right, i + 1, b, str + ch);
                b.pop();
            
            }
          
        }
        else if(ch == ')'){
            if(right > 0){
                
                valid(s, left, right - 1, i + 1, b, str);
            }
            if(!b.empty()){
                b.pop();
                valid(s, left, right, i + 1, b, str + ch);
            }
            
            else{
                return;
            }
        }
        else {
            valid(s, left, right, i + 1, b, str + ch);
        }
        return ;
    }
};
void printvec(vector<string> s){
    for(int i = 0 ; i < s.size() ; i++){
        cout << s[i] << ' ';
    }
    cout << '\n';
}
int main(){
    vector<string> str;
    Solution s;
    str = s.removeInvalidParentheses(")(");
    printvec(str);

}