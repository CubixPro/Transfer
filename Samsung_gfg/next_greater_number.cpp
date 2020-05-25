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
        int n;
        cin >> n;
        multiset<int> digits;
        int dig = n % 10;
        digits.insert(dig);
        n = n / 10;
        bool check = true;
        while (n != 0)
        {
            int temp = n % 10;
            if (temp >= dig)
            {
                digits.insert(temp);
                dig = temp;
                n = n / 10;
            }
            else
            {
                dig = temp;
                n = n / 10;
                check = false;
                break;
            }
        }
        if (!check)
        {
            if(n != 0)
                cout << n;
            set<int>::iterator it = digits.begin();
            while (it != digits.end())
            {
                if (*it > dig)
                {
                    cout << *it;
                    digits.erase(digits.lower_bound(*it));
                    digits.insert(dig);
                    break;
                }
                it++;
            }
            set<int>::iterator it1 = digits.begin();
            while (it1 != digits.end())
            {
                cout << *it1;
                it1++;
            }
        }
        else
        {
            cout << "not possible";
        }
        cout << '\n';
    }
}
