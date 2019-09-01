#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        double x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        double c1c2  = sqrt(pow(x1 - x2, 2) +  pow((y1 - y2), 2));
        if(c1c2 <= (r1 + r2))
        {
            printf("NO\n");
            break;
        }
        {
            printf("YES\n");
        }
        double newx, newy;
        double m = (y1 - y2)/(x1 - x2);
        newx = x1 + r1 * cos(atan(m));
        newy = y1 + r1 * cos(atan(m));
        if((newx*newx + newy*newy - r2*r2) < 0)
        {
        newx = x1 - r1 * cos(atan(m));
        newy = y1 - r1 * cos(atan(m));
      
        } 
        printf("%lf %lf\n", newx, newy);
    }
}