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
        string s;
        cin >> s;
        bool allsame = true;
        for(int i = 1 ; i < s.length() ; i++){
            if(s[i] != s[i - 1]){
                allsame = false;
            }
        }
        if(allsame){
            cout << s;
        }
        else{
            for(int i = 0 ; i < s.length() ; i++){
                cout << "01";
            }
        }
        cout << '\n';
    }
}