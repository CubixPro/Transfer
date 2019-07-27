/*www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-queries-3/editorial/
*/
#include <iostream>
#include <algorithm>

int main()
{
    int queries;
    scanf("%d", &queries);
    bool primes[1000001];
    
    for (int i = 0; i < 1000000 + 1; i++)
    {
        primes[i] = true;
    }
    for (int i = 2; i < 1000000 + 1; i++)
    {
        if (primes[i] == true)
        {
            for (int  j = i * i; j < 1000000 + 1; j += i)
            {
                primes[j] = false;
            }
        }
    }
    printf("hello\n");
    while (queries-- != 0)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int min = INT16_MAX;
        for (int i = n; i <= m; i++)
        {
            if (primes[i])
            {
                int a = i;
                i++;
                while (primes[i] != true && i<(m - 1))
                    i++;
                int b = i;
                int x = a ^ b;
                printf("%d %d\n", a, b);
                if (x < min)
                    min = x;
                i--;
            }
            
        }
        printf("%d\n", min);
    }
}