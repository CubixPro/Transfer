#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long int lld;

using namespace std;
int exp_mod(int num, int power, int mod)
{
    int val = 1;
    while(power!=0)
    {
        if(power%2 == 1)
        {
            val = ((val%mod) * (num%mod))%mod;
            power--;
        }
        num = ((num%mod)*(num%mod))%mod; 
        power = power/2;
    }
    return val;
}
int find_mod(string str, int num)
{
    int mod = 0;
    int pow = 0;
    for(int i = 0 ; i < str.length()  ; i++) 
    {
        char ch =str[i];
        int dig = str[i] - 48;
        mod = (mod * 10)%num;
        mod = (mod + dig)%num;
    }
    return mod;
}

int main()
{
    lld testcases;
    scanf("%lld", &testcases);
    while (testcases-- != 0)
    {
        int n;
        string k;
        scanf("%d", &n);
        cin >> k;
        if (find_mod(k, n) == (n - find_mod(k, n)))
        {
            lld val = find_mod(k, n) * 2 - 1;
            printf("%lld\n", val);
        }
        else
        {
            lld val = min(find_mod(k, n), n - find_mod(k, n));
            lld s2 = val * 2;
            printf("%lld\n", s2);
        }
    }
}