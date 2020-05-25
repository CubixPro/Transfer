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
        int n, k;
        cin >> n >> k;
        int a[n], b[n];
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        for(int j = 0 ;j  < n ; j++){
            cin >> b[j];
        }
        sort(a, a + n);
        sort(b, b + n);
        int high = n - 1;
        int low = 0;
        while(k != 0 && high >= 0 && low < n){
            if(b[high] > a[low]){
                int temp = b[high];
                b[high] = a[low];
                a[low] = temp;
                k --;
                low++;
                high--;
            }
            else{
                break;
            }
        }
        lld sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += a[i];
        }
        cout << sum << '\n';
    }
}