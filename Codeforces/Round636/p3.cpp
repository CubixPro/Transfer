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
        lld n;
        cin >> n;
        lld arr[n];
        for(lld i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        lld max_val = arr[0];
        lld sum = 0;
        for(lld i = 1 ; i < n ; i++){
            if(arr[i]*arr[i - 1] < 0){
                sum += max_val;
                max_val = arr[i];
            }
            else{
                max_val = max(max_val, arr[i]);
            }
        }
        sum += max_val;
        cout << sum << '\n';
    }
}
