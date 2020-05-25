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

int main()
{
    cases
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        int count = 1;
        bool allsame = true;
        for(int i = 1 ; i < n ; i++){
            if(str[i] == str[0]){
                count++;
            }
            else{

                break;
            }
        } 
        if(count < k){
            cout << str[k - 1] << '\n';
        }
        else{
            for(int i = k + 1 ; i < n; i++){
                if(str[i] == str[k]){
                    continue;
                }
                else{
                    allsame = false;
                    break;
                }
            }
            if(!allsame)
                cout << str[0] << str.substr(k) << '\n';
            else
            {
                cout << str[0];
                int val = n - k;
                int tot;
                if(val%k == 0){
                    tot = val/k;
                }
                else{
                    tot = val/k + 1;
                }
                for(int i = 1  ; i <= tot ; i++){
                    cout << str[k];
                }
                cout << '\n';
            }
            
        }
    }
}