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
        lld sum = 0;        
        while(k >= (n)){
            sum += (k/n)*n;
            k = k - (k/n)*(n - 1);
        }
        sum += k;
        cout << sum << '\n';
    }
}