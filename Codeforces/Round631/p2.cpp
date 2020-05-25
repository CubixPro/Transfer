#include <bits/stdc++.h>
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
int main()
{
    cases
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int count = 0;
        vector<pair<int, int>> coor;
        set<int> left;
        //left.insert(arr[0]);
        int max = -1;

        for (int i = 0; i < n - 1; i++)
        {
            if (left.find(arr[i]) == left.end())
            {
                left.insert(arr[i]);
            }
            else
            {
                break;
            }
            if (arr[i] > max)
            {
                max = arr[i];
            }
            if (left.size() == max)
            {
                set<int> right;
                bool check = true;
                int max2 = -1;
                for (int j = i + 1; j < n; j++)
                {
                    if (right.find(arr[j]) == right.end())
                        right.insert(arr[j]);
                    else{
                        check = false;
                        break;
                    }
                    right.insert(arr[j]);
                    if (arr[j] > max2)
                    {
                        max2 = arr[j];
                    }
                }
                if (right.size() == max2 && check)
                {
                    count++;
                    coor.push_back({i + 1, n - i - 1});
                }
            }
        }
        cout << count << '\n';
        for (int i = 0; i < count; i++)
        {
            cout << coor[i].first << " " << coor[i].second << '\n';
        }
    }
}