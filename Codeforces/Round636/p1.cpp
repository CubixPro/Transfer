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
using namespace std;

int main(){
    set<int> power_2;
    int prod = 4;
    for(int i = 0 ; i < 29 ; i++){
        //cout << i << ' ' <<  prod << '\n';
        power_2.insert(prod - 1);
        prod = prod * 2;
        
    }
    cases{
       int n;
       cin >> n;
        set<int> :: iterator   it = power_2.begin();
        while(it != power_2.end()){
            int val = *it;
            if(n%val == 0){
                cout << (n/val) << '\n';
               break; 
            }
            it++;
        }
    }
}
