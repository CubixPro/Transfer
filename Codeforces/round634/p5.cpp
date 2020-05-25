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

int n;

pair<int, bool> dp[MAXN][MAXN];
int calc_dp(int i, int j, int arr[])
{
    if (dp[i][j].first != -1)
    {
        return dp[i][j].first;
    }
    else if (i > j)
    {
        dp[i][j].second = true;
        dp[i][j].first = 0;
        return 0;
    }
    else
    {
        if (arr[i] == arr[j] && arr[i] == arr[i + 1] && arr[j] == arr[j - 1])
        {

            dp[i][j].first = calc_dp(i + 1, j - 1, arr) + 2;
            dp[i][j].second = dp[i + 1][j - 1].second;
        }
        else if (arr[i] == arr[j])
        {
            calc_dp(i + 1, j - 1, arr) ;
            if (dp[i + 1][j - 1].second == true)
            {
                dp[i][j].second = !dp[i + 1][j - 1].second;
                dp[i][j].first = dp[i + 1][j - 1].first + 2;
            }
            else
            {
                if (calc_dp(i + 1, j, arr) > calc_dp(i, j - 1, arr))
                {
                    dp[i][j] = dp[i + 1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        else
        {
            if (calc_dp(i + 1, j, arr) > calc_dp(i, j - 1, arr))
            {
                dp[i][j] = dp[i + 1][j];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[i][j].first;
    }
}
int main()
{
    cases
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    dp[i][i] = {1, true};

                else
                {
                    dp[i][j] = {-1, false};
                }
            }
        }

        int max = calc_dp(0, n - 1, arr);
        cout << max << '\n';
    }
}