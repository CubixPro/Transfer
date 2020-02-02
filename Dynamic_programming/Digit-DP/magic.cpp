//use this as a template for digit dp problems :) 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define mod 1000000007
using namespace std;


int dp[2001][2001][2];
vector<int> num;
int m, d;

bool check() {
        int cur = 0;
        for(int i = 0 ; i < num.size() ; i++){
            cur = (cur * 10 + num[i]) % m;
            if((i+1) & 1) {
                if(num[i] == d) return 0;
            } else if(num[i] != d) return 0;
        }
        if(!cur) return 1;
        return 0;
    }

int call(int pos, int sum, int check) //check = 1 -> everything possible ; check = 0 -> not everthing
{
    if(dp[pos][sum][check] != -1)
        return dp[pos][sum][check];
    if (pos == num.size())
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }
    int msb;
    if (check == 1)
    {
        msb = 9;
    }
    else
    {
        msb = num[pos];
    }
    int res = 0;
    if ((pos + 1) % 2 == 1)
    {
        for (int i = 0; i <= msb; i++)
        {
            int newcheck = 1;
            int newsum = 0;
            if(i == num[pos] && check==0)
                newcheck = 0;
            if (i != d)
            {
                newsum = (sum * (10) + i) % m;
                res += call(pos + 1, newsum, newcheck)%mod;
                res = res%mod;
            }
        }
    }
    else
    {
        int newcheck = 1;
        if (d == num[pos] && check == 0)//new error
            newcheck = 0;

        if (d <= msb)
        {
            int newsum;
            newsum = (sum * (10 ) + d) % m;
            res += call(pos + 1, newsum, newcheck)%mod;
            res = res%mod;
        }

    }
    dp[pos][sum][check] = res;
    return res;
}
int main()
{

    scanf("%d %d", &m, &d);
    string a, b;
    cin >> a;
    cin >> b;
    for(int i = 0 ; i < a.length() ; i++)
    {
        num.push_back(a[i] - '0');
    }
    bool value = check();
    memset(dp, -1, sizeof(dp));
    int val = call(0, 0, 0);
    if(check())
        val--;
    num.clear();
    for(int i = 0 ; i < b.length() ; i++)
    {
        num.push_back(b[i] - '0');
    }
    memset(dp, -1, sizeof(dp));
    int val2 = call(0, 0, 0);
    printf("%d\n", (val2-val + mod)%mod);
    
    
}