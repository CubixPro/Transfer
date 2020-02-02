#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int main()
{
    int k;
    scanf("%d", &k);
    lld g[k];
    g[0] = 1;
    g[1] = 1;
    lld product = 1;
    for(int i = 2 ; i < k ; i++)
    {
        g[i] = 2 * g[i - 1] + 3 * g[i - 2];
        product = ((product%600) * (g[i]%600))%600;
    }

    product = (product - 2 + 600) % 600; 
    lld a = 1;
    lld b = 1;
    lld c = 1;
    int count = 0;
    lld arrele[600];
    for(int i = 1 ; i <= 600 ; i++)
    {
        
        c = ((5 * (b%1000))%1000 + (3 * (a % 1000)))%1000;
       
        arrele[i - 1] = c;
        a = b;
        b = c;
        count++;
    }
    
    printf("%lld", arrele[product]);
}