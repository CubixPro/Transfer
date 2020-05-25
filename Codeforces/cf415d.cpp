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

lld count_odd = 0;
lld count_even = 0;

using namespace std;

void total_count(string str){
    lld o[2], e[2];
    o[0] = o[1] = e[0] = e[1] = 0;
    for(lld i = 0 ; i < str.length() ; i++){
        count_odd++;
        int id = (str[i] == 'a')?0:1;
        if(i%2 == 0){
            count_even += o[id];
            count_odd  += e[id];
            e[id]++;
        }
        else{
            count_even += e[id];
            count_odd += o[id];
            o[id]++;
        }
    }
}

int main(){
   string str;
   cin >> str;
   total_count(str);
    cout << count_even << ' ' << count_odd << '\n';
}