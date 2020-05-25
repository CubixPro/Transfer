#include <bits/stdc++.h>
#include <cmath>
#define lld long long int
#define llf long long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define cases  \
    lld T = 0; \
    cin >> T;  \
    while (T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAXN 2000


using namespace std;
unordered_map<string, int> store; 
int minrm(string str){
    if(store.find(str) != store.end()){
        return store[str];
    }
    else{
    int len = str.length();
    if(len == 0){
        return 0;
    }
    if(len == 1){
        return 1;
    }
    char ini_ch = str[0];
    char ini_pos = 0;
    int mini = len;
    for(int i = 1 ; i < len ; i++){
        if(str[i] != ini_ch){
            string newstr = str.substr(0, ini_pos) + str.substr(i, len - i); 
            //cout << newstr << " " << str;
            mini = min(mini, minrm(newstr)); 
            ini_ch = str[i];
            ini_pos = i;
        } 

    } 
    mini = min(mini, minrm(str.substr(0, ini_pos)));
    store[str] = 1 + mini;
    cout << "hello";
    return (1 + mini);
    }
}

int main(){
   int n;
   string str;
   cin >> n;
   cin >> str; 
   //cout << str.substr(1) << ' ' << str.substr(0, str.length() - 1);
   int val = minrm(str);
   cout << val << '\n';
}