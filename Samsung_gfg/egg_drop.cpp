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
int calc(int start, int end, int eggs){
    if(eggs == 1){
        return (end - start);
    }
    if(start == end){
        return 1;
    }
    if(start > end){
        return 0;
    }
    else{
        return 1 + max(calc(start, (start + end)/2 - 1, eggs - 1), calc((start + end)/2 + 1, end, eggs));
    }
}
int main(){
    cases{
        int egg, floors;
        cin >> egg >> floors;
        int attempts = calc(1, floors, egg);
        cout << attempts << '\n';
    }
}
