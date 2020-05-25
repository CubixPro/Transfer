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
    //cases
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        int c[k];
        for(int i = 0 ; i < k ; i++){
            cin >> c[i];
        }
        sort(arr, arr + n);
        int count[k + 1];
        memset(count, 0, sizeof(int)*(k + 1));
        for(int i = 0 ; i < n ; i++){
            count[arr[i]]++;
        }
        for(int i = k - 1 ; i >= 1 ; i--){
            count[i] += count[i + 1];
        }
        int min_test = ceil(count[1]/c[0]);
        for(int i = 1 ; i <= k ; i++){
            int val = ceil(count[i]/c[i - 1]);
            if(val > min_test){
                min_test = val;
            }
        }
        bool find = false;

        /*int l = 1; 
        int u = max;
        while(l < u){
            int m = (l + u)/2;
            bool check_val = check(arr, c, m);
            if(!check_val){
                l = m + 1;
            }
            else{
                bool check_val2 = check(arr, c, m - 1);
                if(check_val2){
                    u = m - 1;
                }
                else{
                    min_test = m;
                    break;
                }
            }
        }
        cout << min_test << '\n';*/
        cout << min_test << '\n';
        vector<int> testcases[min_test];
        for(int i = 0 ; i < n; i++){
            testcases[i%min_test].push_back(arr[i]);
        }
        for(int i = 0 ; i < min_test ; i++){
            cout << testcases[i].size() << ' ';
            for(int j = 0 ; j < testcases[i].size() ; j++){
                cout << testcases[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}