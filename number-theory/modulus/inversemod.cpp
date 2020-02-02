#include<iostream>
#include<algorithm>

typedef long long int lld;
int x, y;
lld extendedeuclid(lld c, lld m)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
    }
    else 
    {
        extendedeuclid(m, c%m);
        int temp = x;
        x = y ;
        y = temp - (c/m)*y;
    }
} 
lld exponentialmod(lld a, lld b, lld c)
{
    lld val  = 1;
    while(b != 0)
    {
      if(b%2 == 1)
      {
          val = (val * a)%c;
      } 
      a = (a*a) % c;
      b = b/2;
    }
    return val;
}
lld inverse(lld c, lld m)
{
   extendedeuclid(c, m);
   return (x % m + m)%m;
}
int main()
{
    lld a, b, c, m;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &m); 
    lld g = inverse(c, m);
    //printf("%lld\n", g);
    lld h = exponentialmod(a, b, m);
    //printf("%lld\n", h);
    lld i = (h * (g % m))%m;
    printf("%lld", i);
}