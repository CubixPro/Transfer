#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lld;
int exp(int num, int power, int mod)
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

int main()
{
    string str;
    cin >> str;
    lld alph[26];
    lld final[26];
    lld mod = 1000000007;
    for (int i = 0; i < 26; i++)
    {
        alph[i] = 0;
        final[i] = 0;
    }
    lld max = 0;
    for (lld i = 0; i < str.length(); i++)
    {
        int num = str[i] - 97;
        alph[num]++;
        if (alph[num] > max)
            max = alph[max];
    }
    lld fact[str.length() + 1];
    fact[0] = 1;
    for (int i = 1; i < str.length() + 1; i++)
    {
        fact[i] = ((fact[i - 1]%mod) * (i%mod));
    }
    sort(str.begin(), str.end());
    for (lld i = 0; i < str.length(); i++)
    {
        if (i != (str.length() - 1) && (str[i] == str[i + 1]))
            i = i + 1;
        int num = str[i] - 97;
        lld val = ((fact[str.length() - 1] % mod)* exp((fact[alph[num] - 1]), mod - 2, mod))%mod;
        for (lld j = 0; j < str.length(); j++)
        {
            if (j!= (str.length() - 1) && (str[j] == str[j + 1]))
                j = j + 1;

            if (i != j)
            {
                val = ((val%mod) * exp(fact[alph[str[j] - 97]], mod - 2, mod))%mod;
            }
        }
        final[num] = val;
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%lld ", final[i]);
    }
}
