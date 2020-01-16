#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main()
{
    lld testcases;
    scanf("%lld", &testcases);
    while (testcases-- != 0)
    {
        lld n, m;
        scanf("%lld %lld", &n, &m);
        lld arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }

        pair<lld, int> a[n];
        for (lld i = 0; i < n; i++)
        {
            a[i] = make_pair(arr[i], i % m);
        }

        sort(a, a + n);
        lld min = INT64_MAX;
        string there = "";
        string fin = "";
        for(lld i = 0 ; i < m ; i++)
        {
            there += '0';
            fin += '1';
        }
        string always = there;
        for (lld i = 0; i <= n - m ; i++)
        {
        
            //memset(there, false, sizeof(bool) * 5);
            int j = i;
            there = always; 
                while(there != fin && j < n)
                {
                    if(there[a[j].second] == '0')
                    {
                        there[a[j].second] = '1';
                        j++;
                    }
                    else{
                        j++;
                    }
                }
            lld new_min = a[j - 1].first - a[i].first;
            if(new_min < min)
                min = new_min;
        }
        printf("%lld\n", min);
    }
   
}