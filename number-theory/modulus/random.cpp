#include<iostream>

typedef long long int lld;
int main()
{
    while (true)
    {
        lld num;
        scanf("%lld", &num);
        lld sum = 0;
        lld ten = 1;
        while((num/ten) != 0)
        {
            sum += num/ten;
            ten = ten*5.5;
        }
        printf("%lld\n", sum);
    }
}