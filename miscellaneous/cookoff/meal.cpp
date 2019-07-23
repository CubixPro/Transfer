#include <iostream>
#include <bits/stdc++.h>

#include <string>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        string words[n];
        int count[6] = {0, 0, 0, 0, 0, 0};

        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
            //cout << words[i] << endl;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                char ch = words[i][j];
                switch (ch)
                {
                case 'c':
                    count[0]++;
                    break;
                case 'o':
                    count[1]++;
                    break;
                case 'd':
                    count[2]++;
                    break;
                case 'e':
                    count[3]++;
                    break;
                case 'h':
                    count[4]++;
                    break;
                case 'f':
                    count[5]++;
                    break;
                }
            }
        }
        count[0] = count[0] / 2;
        count[3] = count[3] / 2;

        int min = count[0];
        //printf("%d", count[0]);
        for (int i = 1; i < 6; i++)
        {
            //printf("%d ", count[i]);
            if (count[i] < min)
                min = count[i];
        }
        printf("%d", min);
        printf("\n");
    }
    return 0;
}