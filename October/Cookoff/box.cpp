#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld max_arr(lld *arr, lld n)
{
    lld max = arr[0];
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

lld min_arr(lld* arr, lld n)
{
    lld min = arr[0];
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

lld con_jafar(lld* arr, lld n)
{
    lld con_min = arr[0];
    lld min_val = arr[1];
    for(int i = 1 ; i < n - 1 ; i++)
    {
        if(min(arr[i - 1], arr[i + 1]) > min_val)
        {
            min_val = min(arr[i - 1], arr[i + 1]);
            con_min = arr[i];
        }
    } 
    if(arr[n - 2] > min_val)
    {
        con_min = arr[n - 1];
        min_val = arr[n - 2];
    }
    return min_val;
}

lld con_amir(lld* arr, lld n)
{
    lld con_max = arr[0];
    lld max_val = arr[1];
    for(int i = 1 ; i < n - 1 ; i++)
    {
        if(max(arr[i - 1], arr[i + 1]) < max_val)
        {
            max_val = max(arr[i - 1], arr[i + 1]);
            con_max = arr[i];
        }
    } 
    if(arr[n - 2] < max_val)
    {
        con_max = arr[n - 1];
        max_val = arr[n - 2];
    }
    return max_val;
}

int main()
{
    int testcases;
    scanf("%lld", &testcases);
    while(testcases-- != 0)
    {
        lld n, k, p;
        scanf("%lld %lld %lld", &n, &k, &p);
        lld *arr = new lld[n];
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%lld", &arr[i]);
        }
        if(k%2 == 1)
        {
            if(p == 0)
            {
                 cout << max_arr(arr, n);
            }
            else
            {
                cout <<  min_arr(arr, n);
            }
        }
        else
        {
            if(p == 0)
            {
                cout <<  con_jafar(arr, n);
            }
            else
            {
                cout <<  con_amir(arr, n);
            }
            
        }
            
    cout << '\n';
        
    }
}