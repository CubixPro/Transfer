#include <bits/stdc++.h>
#include <cmath>
#define lld unsigned long long int
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
        lld n;
        cin >> n;
        lld sum = 0;
        for(lld i = (n/2) ; i != 0 ; i--){
            sum += (i) * (n * n - (n - 2) * (n - 2));
            n = n - 2;
        }
        cout << sum << '\n';
    }
}