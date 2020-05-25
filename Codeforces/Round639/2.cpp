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
    lld arr_size[1000000];
    cout << -1337%3 << '\n';
    for(int i = 1; i < 1000000; i++){
        arr_size[i] = (i)*(3 * i + 1)/2;
    }
    cases{
        lld n;
        cin >> n;
        lld count = 0;
       while(n != 0){
           if(n == 1){
               break;
           }
           for(int i = 1; i < 1000000 - 1 ; i++){
               if(arr_size[i] <= n && arr_size[i + 1] > n){
                   n = n - arr_size[i];
                   count++;
                   break;
               }
           }
       }
       cout << count << '\n';
    }
}