#include <stdio.h>
long long int fact(long int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}
long int comb(long int n, long int p)
{
    return fact(n) / (fact(p) * fact(n - p));
}
int main()
{
    long int testcases;
    scanf("%ld", &testcases);
    while (testcases-- != 0)
    {
        long int n;
        scanf("%ld", &n);
        long int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (long int j = 0; j < i; j++)
            {
                sum += 1 + comb((i - 1), j) * j;
            }
        }
        sum = sum % 1000000007;
        printf("%ld\n", sum);
    }
}