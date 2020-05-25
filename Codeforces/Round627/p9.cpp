#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
string maxpal(string str){
   // cout << str << '\n';
    int maxval = 1;
    string maxstring = str.substr(0, 1);
   /* if(str.compare("cdfdcec")){
       // cout << "hello";
    }
 for(int i = str.length() ; i >= 1 ; i--){
            bool pal = true;
            for(int j = 0 ; j < i/2 ; j++){
                if(str[j] ==  str[i - 1 - j]){
                    continue;
                }
                else{
                    pal = false;
                    break;
                }
            }
            if(pal){
                maxval = i;
                maxstring = str.substr(0, i);
                break;
            }
        }
        reverse(str.begin(), str.end()); 
        for(int i = str.length() ; i >= 1 ; i--){
            bool pal = true;
            for(int j = 0 ; j < i/2 ; j++){
                if(str[j] ==  str[i - 1 - j]){
                    continue;
                }
                else{
                    pal = false;
                }
            }
            if(pal){
                if(maxval < i){
                    maxval = i;
                    maxstring = str.substr(0, i);
                }
                break;
            }
        }
        
return maxstring;*/


    str = str + reverse(str.begin(), str.end()); 
}
int main(){
    cases{
        string str;
        cin >> str;
        string newstr = "";
        int i ;
        for( i = 0 ; i < str.length()/2 ; i++){
            if(str[i] == str[str.length() - 1 - i]){
                newstr = newstr + str[i];
            }
            else{
                break;
            }
        }

        newstr = newstr + maxpal(str.substr(i, str.length() - 2 * i));
        for(int j = i - 1 ; j >= 0 ; j--){
            newstr = newstr + newstr[j];
        }
        cout << newstr << '\n';
        /*string maxstring = maxpal(str);
        for(int i = 0 ; i < str.length()/2; i++){
           if(str[i] == str[str.length() - i - 1]) 
           {   string newstr =  str.substr(i + 1, str.length() - 2 * (i + 1));
               string newmayb =  str.substr(0, i + 1) + maxpal(newstr) + str.substr(str.length() - (i + 1), i + 1);
               if(newmayb.size() > maxstring.size()){
                   maxstring = newmayb;
               }
           }
           else{
               string newmayb = str.substr(0, i)  + maxpal(str.substr(i, str.length() - (2 * i))) + str.substr(str.length() - i, i);
               if(newmayb.size() > maxstring.size()){
                   maxstring = newmayb;
               }break;
           }
        } 

        cout << maxstring << '\n';
        */


    }
}