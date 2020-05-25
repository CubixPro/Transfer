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
        int max = 0;
        int min = n;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            arr[i] = (arr[i] + i)%n;
            if(arr[i] < 0){
                arr[i] = (arr[i] + n)%n;
            }
            
        }
        sort(arr, arr + n);
        bool check = true;
        for(int i = 0 ; i < n - 1 ; i++){

            if(arr[i] == arr[i + 1])
            {
                check = false;
                break;
            }
        }
        if(check == false){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}