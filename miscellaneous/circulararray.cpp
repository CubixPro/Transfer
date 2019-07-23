#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

typedef long long int lld;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    for (int u = 1; u <= testcases; u++)
    {
        int n;
        scanf("%d", &n);
        lld arr[n];
        lld max = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
            max += arr[i];
        }
       // printf("%d", max);
        lld counter = 0;
        for (int i = 0; i < n - 1; i++)
        {
            lld min = max;
            int pos;
            for (int j = 0; j <= n - i - 1; j++)
            {
                if (j == (n - i - 1))
                {
                    if ((arr[0] + arr[j]) < min)
                    {
        //                printf("helllloooooo\n");
                        min = arr[0] + arr[j];
                        pos = j;
                    }
                    continue;
                }
                else
                {
                    if ((arr[j] + arr[j + 1]) < min)
                    {
                        min = arr[j] + arr[j + 1];
                        pos = j;
                    }
                }
            }
            //printf("%d %d \n", min, pos);
            arr[pos] = min;
            counter += min;
            if (pos == (n - i - 1))
            {
                arr[0] = min;
                //for (int l = 0; l < n - i - 1; l++)
                //{
                //    printf("%lld ", arr[l]);
                //}
                //printf("\n");

                continue;
            }
            for (int k = pos + 1; k < n - i - 1; k++)
            {
                arr[k] = arr[k + 1];
            }
            /*for (int l = 0; l < n - i - 1; l++)
            {
                //printf("wtf");
                printf("%lld ", arr[l]);
            }*/
         //   printf("\n");
            
        }
        printf("%lld\n", counter);
    }
}