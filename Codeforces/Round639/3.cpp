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
        int n, m;
        cin >> n >> m;
        if(n == 1 || m == 1){
            cout << "YES \n";
        } 
        else if(n == 2 && m == 2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}