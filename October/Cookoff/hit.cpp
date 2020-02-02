#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main()
{
    lld testcases;
    scanf("%lld", &testcases);
    while(testcases-- != 0)
    {
        lld n;
        scanf("%lld", &n);
        lld *arr = new lld[n];
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%lld", &arr[i]);
        }
        sort(arr, arr + n);
        bool possible = true;
        lld index = n ;
        if(arr[index / 4] == arr[index / 4 - 1])
        {
            possible = false;
            cout << -1 << '\n';
            continue;
        }
        if(arr[index/2] == arr[index/2 - 1])
        {
            possible = false;
            cout << -1 << '\n';
            continue;

        }
        if(arr[index * 3 / 4] == arr[index * 3 / 4 - 1])
        {
            possible = false;
            cout << -1 << '\n';
            continue;
        }
        if(possible == true)
        {
            cout << arr[n / 4] << " " << arr[n / 2] << " " << arr[3 * n / 4] << '\n';
        }

    }
}