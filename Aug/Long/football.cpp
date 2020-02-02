#include<iostream>


using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        int goal[n];
        int fowl[n];
        int max = 0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d", &goal[i]);
        }
        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d", &fowl[j]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            int val = goal[i]*20 - fowl[i]*10;
            if(val < 0)
                val =  0;
            if(val > max)
                max = val;
        }
        printf("%d\n", max);
    }
}