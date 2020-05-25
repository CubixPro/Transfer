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
        int n;
        cin >> n;
        if((n/2)%2 != 0){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << '\n' ;
            int arr_eve[n/2];
            int arr_odd[n/2];
            int sum_eve = 0;
            for(int i = 1 ; i <= n/2 ; i++){
                arr_eve[i - 1] = (i * 2); 
                sum_eve += (i * 2);
            }
            for(int i =  0 ; i < n/2 - 1; i++){
                arr_odd[i] = i * 2 + 1;
                sum_eve = sum_eve - arr_odd[i];
            }
            arr_odd[n/2 - 1] = sum_eve;
            for(int i = 0 ; i < n/2 ; i++){
                cout << arr_eve[i] << ' ';
            }
            for(int i  = 0 ; i < n/2 ; i++){
                cout << arr_odd[i] << ' ';
            }
            cout << '\n';
        }
    }
}
