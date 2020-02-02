#include<iostream>
#include<algorithm>

using namespace std;

typedef unsigned long long int ulld;

ulld power_2[65];
ulld fib_2[65];

ulld fib(ulld n)
{
    if(n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }
    ulld a = 0; 
    ulld b = 1;
    ulld c ;
    for(ulld i = 3; i <= n ; i++)
    {
        c = (a%10 + b%10)%10;
        a = b;
        b = c;
    }
    return c;
    
}

int main()
{
    int testcases;
    power_2[0] = 1;
    fib_2[0] = 0 ;
    fib_2[0] = 0;
    fib_2[1] = 1;
   
    int arr[4] = {0, 9, 2, 3};

    for(int i = 2 ; i <= 64 ; i++)
    {
        int val = i%4;
        fib_2[i] = arr[val];
    }
    
    for(int i = 1 ; i <= 64 ; i++)
    {
        power_2[i] = power_2[i - 1] * 2;
    }
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        ulld n;
        int power;
        scanf("%llu", &n);
        //printf("%d\n", fib(n));
        for(int i = 0 ; i <= 63 ; i++)
        {
            if(n >= power_2[i] && n < power_2[i + 1])
            {
                power = i ;
                break;
            }
        }
        //printf("%d\n", power);
        printf("%llu\n", fib_2[power]);
    }
}