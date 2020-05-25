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
        list<int> candies;
        for(int i = 0 ; i < n; i ++){
            int val;
            cin >> val;
            candies.push_back(val);
        }
        char ch = 'a';
        int maxc = 0;
        int suma = 0, sumb = 0;
        int turns = 0;
        while(!candies.empty())
        {
            if(ch == 'a'){
                int sum = 0;
                while(sum <= maxc && !candies.empty()){
                    sum += candies.front();
                    candies.pop_front();
                }
                ch = 'b';
                maxc = sum;
                suma += sum;
                if(sum != 0){
                    turns++;
                }
            }
            else{
                int sum = 0;
                while(sum <= maxc && !candies.empty()){
                    sum += candies.back();
                    candies.pop_back();
                }
                ch = 'a';
                maxc = sum;
                sumb += sum;
                if(sum != 0){
                    turns++;
                }
            }
        }
        cout << turns << ' ' <<  suma << ' ' <<  sumb << '\n';
    }
}