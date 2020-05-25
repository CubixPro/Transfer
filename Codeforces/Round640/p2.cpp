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
        lld n, k;
        cin >> n >> k;
        lld ans1 = n - (k - 1);
        lld ans2;
        if(ans1 > 0 && ans1%2 == 1){
            cout << "YES\n";
            for(int  i = 0 ; i < k - 1 ; i++){
                cout << 1 << ' ';
            }
            cout << ans1 << '\n';
        }
        else if((ans2 = n - 2 * (k - 1)) > 0 && ans2%2 == 0){
             cout << "YES\n";
            for(int  i = 0 ; i < k - 1 ; i++){
                cout << 2 << ' ';
            }
            cout << ans2 << '\n';
        }
        else{
            cout << "NO\n";
        }
    }
}