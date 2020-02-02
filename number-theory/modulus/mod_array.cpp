#include<iostream>

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
    for(int i = str.length() - 1 ; i >= 0 ; i--)
    {
        char ch =str[i];
        int dig = str[i] - 48;
        mod += ((dig%num)*(exp_mod(10, pow, num)))%num;
        mod = mod%num;
        pow++;
    }
    return mod;
}
int main()
{
    string str = "17459895734004";
    int val = find_mod(str, 17);
    unsigned long long  int val2 = 17459895734004%17;
    printf("%d %llu", val, val2);
}