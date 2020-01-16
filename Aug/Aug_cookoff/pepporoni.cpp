#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        int sum_left[n];
        int sum_right[n];
        int sum_left_total = 0;
        int sum_right_total = 0;
        
        for(int i = 0 ; i < n ; i++)
        {
            string value;
            cin >> value;
            sum_left[i] = 0;
            sum_right[i] = 0;
           for(int j = 0 ; j < n/2 ; j++)
           {
               int val = value[j] - '0';;
               sum_left[i] += val;
           }
           for(int j = n/2 ; j < n ; j++)
           {
               int val = value[j] - '0';
               sum_right[i] += val;
           }
           sum_left_total = sum_left_total + sum_left[i];
           sum_right_total = sum_right_total + sum_right[i];
        }
        int diff = abs(sum_left_total - sum_right_total);
        for(int i = 0 ; i < n ; i++)
        {
            int newdiff = abs((sum_left_total - sum_left[i] + sum_right[i]) - (sum_right_total - sum_right[i] + sum_left[i]));
            if(newdiff < diff)
            {
                diff = newdiff;
            }
        }
        printf("%d\n", diff);
    }
}