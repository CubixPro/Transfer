#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int check(int n)
{
    while(n != 0)
    {
        int dig = n % 10;
        if(dig == 4)
        {
            return 1;
        }
         n = n/10; 
    }
    return 0;
}
int where(int n)
{
    int i = 0;
    while(n != 0)
    {
        int dig = n % 10;
        if(dig == 4)
        {
            return i;
        }
        i++;
        n = n/10;
    }
    return -1;
}

int main()
{
    int testcases;
    scanf("%d", &testcases);
    for(int i = 1 ; i <= testcases ; i++) 
    {
        long int n;
        long int a;
        long int b = 0;
        a = n;
        scanf("%ld", &n);
        //printf("%d %d\n", check(n), where(n));
        while(check(n) == 1)
        {
           int location = where(n);
           n = n - pow(10, location);
           b = b + pow(10, location);

        }
        a = n;
        printf("Case #%d: %ld %ld\n", i, a, b);
    }
    return 0;
}