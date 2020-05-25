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
int search(int arr[], int n, int val){
return 0;
}
int main(){
    cases{
        int n;
        cin >> n;
        int arr[n];
        multiset<int> keys;
        for(int i = 0 ; i < n; i ++){
            cin >> arr[i];
            keys.insert(arr[i]);
        }
        int count = 0;
        for(int i = 0 ; i < n  ; i++){
            int sum = 0;
                sum+=arr[i];
            for(int j = i + 1 ; j < n ; j++){
                sum += arr[j];
                while(keys.find(sum) != keys.end()){
                    keys.erase(keys.lower_bound(sum));
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
}