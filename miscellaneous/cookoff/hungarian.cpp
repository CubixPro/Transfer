#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long int testcases;
    scanf("%ld", &testcases);

    string arr[testcases];
    for (int z = 1; z <= testcases; z++)
    {
        long int n;
        scanf("%ld", &n);
        bool total_find = true;
        long int values[n][n];
        for (long int i = 0; i < n; i++)
        {
            bool find = false;
            for (long int j = 0; j < n; j++)
            {
                long int val;
                scanf("%ld", &val);
                values[i][j] = val;
                if (val == 0)
                    find = true;
            }
            //printf("%d\n", find);
            total_find = total_find && find;
        }
        for (long int i = 0; i < n; i++)
        {
            bool find = false;
            for (long int j = 0; j < n; j++)
            {
                if (values[j][i] == 0)
                    find = true;
            }
            total_find = total_find && find;
        }

        if (total_find == false)
            arr[z - 1] = "NO";
        else
        {
            arr[z - 1] = "YES";
        }
    }
    for (int i = 0; i < testcases; i++)
    {
        cout << arr[i];
        printf("\n");
    }
}