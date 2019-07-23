#include<algorithm>
#include<iostream>

using namespace std;

typedef long long int lld;
double abs(double val)
{
    return (val >= 0)? val : -val;
}
int main()
{
    lld testcases;
    scanf("%lld", &testcases);    
    hello : while(testcases-- != 0)
    {
        lld n;
        scanf("%lld", &n);
        lld arr[n];
        double sum = 0 ;;
        for(long long int i = 0 ; i< n ; i++)
        {
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }
        sum = sum/n;

       // printf("%lld ", sum);
       bool found = false;
        for(long long int i = 0 ; i < n;i++)
        {
            if((sum - arr[i]) == 0)
            {
                printf("%lld\n", (i + 1));
                found = true;
                break;
            }
        }
        if(found == false)
        printf("Impossible");
    }
}