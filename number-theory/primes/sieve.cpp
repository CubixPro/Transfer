#include<iostream>

using namespace std;
typedef long long int lld;

int main()
{
    lld n;
    scanf("%lld", &n);
    bool arr[n];
    lld counter = 0;
    for(lld i = 0 ; i < n + 1 ; i ++)
    {
        arr[i] = true;
    }
    for(lld i = 2 ; i < n + 1 ; i ++)
    {
        if (arr[i] == true)
        {
            printf("%lld\n", i);
            counter++;
            for(lld j = i * i ; j < n + 1 ; j+=i)
            {
                arr[j] = false;
            }
        }
    }
/*for(int i = 2 ; i < n + 1 ; i ++)
{
	printf("%d   ", arr[i]);
}*/

    printf("%lld\n", counter);
}
