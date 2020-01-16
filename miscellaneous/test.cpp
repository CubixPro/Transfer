#include<iostream>

double refcube(const double &ra)
{
    return ra * ra * ra;
}
int main()
{
    double x = 2;
    double z = refcube(x + 0.3);
    printf("%lf", z);
}