#include <bits/stdc++.h>
using namespace std;
int lastStoneWeightII(vector<int> &stones)
{
    int len = stones.size();
    int dp[len + 1][len + 1];
    sort(stones.begin(), stones.end());
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            dp[i][j] = 1000000007;
            if (i == j && i != len)
            {
                dp[i][j] = stones[i];
            }
        }
    }

    for (int l = 1; l < len; l++)
    {
        for (int i = 0; i < len - l; i++)
        {
            int j = i + l;
            for (int k = i; k <= j; k++)
            {
                dp[i][j] = min(dp[i][j], abs(dp[i][k] - dp[k + 1][j]));
            }
        }
    }
    return dp[0][len - 1];
}

int main()
{
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << lastStoneWeightII(arr);
}