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
int main()
{
    cases
    {
        int arr[9][9];
        for (int i = 0; i < 9; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < 9; j++)
            {
                arr[i][j] = str[j] - '0';
            }
        }

        arr[0][0] = arr[1][0];
        arr[3][1] = arr[4][1];
        arr[6][2] = arr[7][2];

        arr[1][3] = arr[2][3];
        arr[4][4] = arr[5][4];
        arr[7][5] = arr[8][5];

        arr[2][6] = arr[3][6];
        arr[5][7] = arr[6][7];
        arr[8][8] = arr[0][8];
        //cout << '\n';
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                cout << arr[i][j];
            }
            cout << '\n';
        }
    }
}