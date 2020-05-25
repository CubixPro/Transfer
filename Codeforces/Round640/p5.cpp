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

int main(){
    cases{
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        string str = "";
        if(n0 > 0){
            str = str + "0";
            for(int i = 1 ; i <= n0 ; i++){
                str = str + "0";
            }
        }
        if(n1 > 0){
            if(str == ""){
                str = str + "0";
            }
            for(int i = 1 ; i <= n1 ; i++){
                string s = (i%2 == 1)?"1":"0";
                str = str + s;
            }
        }
        if(n2 > 0){
             if(str == ""){
                str = str + "1";
            }
            
            int c = n2;
            bool endzero = false;
            if(str[str.length() - 1] == '0'){
                endzero = true;
                str = str.substr(0, str.length() - 1);
            }
            else{
                c = n2;
            }
            for(int i = 1 ; i <= c ; i++){
                str = str + "1";
            }
            if(endzero){
                str = str + "0";
            }
        }
        cout << str << '\n';
    }
}