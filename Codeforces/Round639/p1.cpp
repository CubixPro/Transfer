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
        lld x, y, a, b;
        cin >> x >> y;
        cin >> a >> b;
        lld sum = 0;
          if ( b < (2 * a))
            {
                sum += min(x, y) * b;
                sum += (x - min(x, y) + y - min(x, y)) * a ;
                cout << sum;
            }
            else 
            {
                sum += (x + y) * a; 
                cout << sum;
            }
            

        
        cout << '\n';
    }
}