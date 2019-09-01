#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dfs(string a, string b, map<string, int> dp, map<string, bool> check)
{

    if (a == b)
    {
        return dp[a];
    }
    queue<string> q;
    q.push(a);
    while (q.empty() != true)
    {
        string d = q.front();
        if (d.compare(b) == 0)
            return dp[d];
        string c = q.front();
        q.pop();
        int len = c.length();
        for (int i = 2; i <= len; i++)
        {
            reverse(c.begin(), c.begin() + i);
            if(dp.find(c) == dp.end())//this is important to avoid same cases
            {
                {
                    dp[c] = dp[d] + 1;
                }

                if (c == b)
                    return dp[c];
                q.push(c);
                c = d;
            }
            else
            {
                c = d;
                continue;
            }
        }
    }
    return -1;
}
int main()
{
    map<string, int> dp;
    map<string, bool> check;
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    string a = "";
    for (int i = 0; i < n; i++)
    {
        a = a + (char)(arr[i] + '0');
    }
    string b = a;
    sort(b.begin(), b.end());
    dp[a] = 0;
    check[a] = true;
    int val = dfs(a, b, dp, check);
    printf("%d\n", val);
}