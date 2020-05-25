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
        vector<int> rounds;
        int count = 0;
        while(n != 0){
            int dig  = n%10;
            if(dig != 0)
                rounds.push_back(dig * pow(10, count));
            count++;
            n = n/10;
        }
        cout << rounds.size() << '\n';
        for(int i = 0 ; i < rounds.size() ; i++){
            cout << rounds[i] << ' ';
        }
        cout << '\n';
    }
}