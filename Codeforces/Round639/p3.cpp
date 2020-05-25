#include <bits/stdc++.h>
#include <cmath>
#define lld unsigned long long int
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
lld count(lld x, lld a, lld b, lld prefix[])
{
    lld sum = 0;
    lld val = (x) / (a * b);
    
        sum += val * prefix[a * b - 1];
        sum += prefix[x%(a * b)];
    return sum; 
}
int main()
{
    cases
    {

        lld a, b, q;
        cin >> a >> b >> q;
        if (a > b)
        {
            lld temp = b;
            b = a;
            a = temp;
        }
        lld prefix[a * b];
        memset(prefix, 0, sizeof(int) * a * b);
        prefix[0] = 1;
        for(int i = 1 ; i < a * b ; i++){
            if((i%b)%a == (i%a)%b){
                prefix[i] = 1 + prefix[i - 1];
            }
            else{
                prefix[i] = prefix[i - 1];
            }
        }
        while (q-- != 0)
        {
            lld x, y;
            cin >> x >> y;
            lld sum = (y - x + 1) - (count(y, a, b, prefix) - count(x - 1, a, b, prefix));
            cout << sum << ' ';
            /* lld sum = 0;

            
           for(int i = x ; i <= y ; i++){
              if((i%a)%b == (i%b)%a){
                 //  cout << i << '\n';
               }
               else{
                   sum++;
               }

           }
           cout << sum << '\n';*/
        }
        cout << '\n';
    }
}