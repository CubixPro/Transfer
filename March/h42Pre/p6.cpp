#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define MOD 1000000007

#define love ios_base::sync_with_stdio(false);
#define you cin.tie(NULL);
#define codechef cout.tie(NULL);
#define TEST ll test; cin >> test; while(test--)

using namespace std;

ll fac[100009];
void facto()
{
    fac[0]=1;
    for(ll i=1;i< 100009;i++)
    {
        fac[i] = (fac[i-1]*i)%MOD;
    }
}

ll power(ll x,ll m)//calculate mod 1e9+7
{
    ll res = 1;
    //ll m = 1e9+5;
    while(m>0)
    {
        if(m&1) res = (res*x)%MOD;
        m = m>>1;
        x = (x*x) % MOD;
    }
    return res;
}

ll ncr(ll n,ll r)
{
    ll ans = (fac[n] * ((power(fac[n-r],MOD-2)*power(fac[r],MOD-2))%MOD) )%MOD;
    return ans;
}

ll sumofn(ll n, ll k)
{
    ll p =0;/* code */
    ll num1,temp,arr[100000];
    for(ll j=1;j<=k;j++)
    {
        if(j==1)
        {
            num1 = (((n*(n+1))%MOD)*power(2,MOD-2))%MOD;
            arr[p++] = num1;
            temp = num1;
        }
        else
        {
            temp = (power(n+1,j+1)-1-n + MOD)%MOD;
            for(ll s=1;s<j;s++)
            {
                temp = (temp%MOD - (arr[j-s-1]*ncr(j+1,s+1))%MOD)%MOD;
            }
            temp = (temp*power(j+1,MOD-2))%MOD;
            arr[p++] = temp;
        }
    }
    ll ans = 0;
    for(ll i=0;i<p;i++)
    {
        ans = ans + arr[i];
        ans%=MOD;
       //cout << ans << endl;
        //cout << arr[i] << endl;
    }
    return ans;
}
int main() 
{ 
    love you codechef
    //register ll i,j,k;
    facto();
     
    TEST
    {
        ll n,k;
    //     for(int i=0;i<5;i++)
    //  {
    //      cout << fac[i] << endl;
    //  }
        cin >> n >> k;
        ll ans = sumofn(n,k);
        cout << ans << endl;
    }
    return 0;
}