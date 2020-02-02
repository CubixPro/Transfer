#include<bits/stdc++.h>


using namespace std;
//typedef long long int lld;

long long int binomialCoeff(int n, int k) 
{ 
    long long int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (int i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 

int main()
{
    int t;
    scanf("%lld", &t);
    while(t-- != 0)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        int *arr = new int[n];
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        int count_left = 0;
        int count_right = 0;

        for(int i = k - 1 ; i >= 0 ; i--)
        {
            if(arr[i] == arr[k - 1])
                count_left++;
            else
            {
                break;
            }
            
        }
        for(int i = k  ; i < n ; i++)
        {
            if(arr[i] == arr[k - 1])
            {
                count_right++;
            }
            else
            {
                break;
            }
            
        }
        int final_val = count_left + count_right;
        long long  int  comb = binomialCoeff(final_val, count_left);

        printf("%lld\n", comb);
    }
}