#include<iostream>
#include<algorithm>

using namespace std;
void show(int arr[], int n)
{
    for(int i = 0 ; i < n ; i ++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    long int n;
    scanf("%ld", &n);
    long int arr[n];
    for(long int i = 0; i < n ; i++)
    {
        scanf("%ld", &arr[i]);
    }
    //show(arr, n);
    sort(arr, arr+n);
    //show(arr, n);
    int i = 1;
    while((n - i - 1) >= 0)
    {
        if(arr[n-i-1] != arr[n-i])
        {
            printf("%ld\n", arr[n-i-1]%arr[n-i]);
            return 0;
        }
         i++;
    } 
    printf("%d\n", 0);
    return 0;
}