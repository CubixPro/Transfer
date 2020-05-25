#include <bits/stdc++.h>
#include <cmath>
#define lld  long long int
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
        lld answer[n];
        for(lld i = 0 ; i < n ; i++){
            answer[i] = -1;
        }
        stack<lld> first;
        stack<lld> second;
        unordered_map<lld, lld> value;
        first.push(arr[0]);
        for(lld i = 1; i < n ; i++){
            if(arr[i] > first.top()){
                value.insert({first.top(), arr[i]});
                first.pop();
                first.push(arr[i]);
                while(!second.empty()){
                    if(arr[i] > second.top()){
                        value.insert({second.top(), arr[i]});
                        second.pop();
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                second.push(first.top());
                first.pop();
                first.push(arr[i]);
            }
        }
        while(!first.empty()){
            value.insert({first.top(), -1});
            first.pop();
        }
        while(!second.empty()){
            value.insert({second.top(), -1});
            second.pop();
        }
        for(lld i = 0 ; i < n ; i++){
            cout << value[arr[i]] << ' ';
        }
        cout << '\n';
    }
}