#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
void display(set<pair<long int, long int>> s)
{
    int f = 0;
    typedef pair<long int, long int> pairs;
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {

        f = 1;
        pairs x = *itr;
        cout << "(" << x.first << ", "
             << x.second << ")"
             << " ";
    }

    if (f == 0)
        cout << "No valid pair\n";
}
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        long int m, n, k;
        scanf("%ld %ld %ld", &m, &n, &k);
        typedef pair<long int, long int> pairs;
        set<pairs> s;
        for (long int i = 1; i <= k; i++)
        {
            long int x, y;
            scanf("%ld %ld", &x, &y);
            pairs p = make_pair(x, y);
            s.insert(p);
        }
        //display(s);
        long int fence = 0;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            pairs coor = *it;
            long int x = coor.first;
            long int y = coor.second;
            auto itr = s.end();
            //cout << typeof(it);
            /*if(s.find(std::pair<long int, long int>(2, 1)) != itr)
              printf("True\ne");
            else
                printf("False\n");*/
            if (x == 1)
                fence++;
            if (x == m)
                fence++;
            if (y == 1)
                fence++;
            if (y == n)
                fence++;
            if (x != 1 && s.find(std::pair<long int, long int>(x - 1, y)) == itr)
                fence++;
            if (x != m && s.find(std::pair<long int, long int>(x + 1, y)) == itr)
                fence++;
            if (y != 1 && s.find(std::pair<long int, long int>(x, y - 1)) == itr)
                fence++;
            if (y != n && s.find(std::pair<long int, long int>(x, y + 1)) == itr)
                fence++;
        }
        printf("%ld\n", fence);
    }
}

