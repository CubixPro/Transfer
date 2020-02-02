#include<stdio.h>
#include<stdlib.h>
int main()
{
    int testcases;
    scanf("%d",&testcases);
    while(testcases-- != 0)
    {
        long int n;
        scanf("%ld", &n);
        char string[n];
        scanf("%s", string);
        long int count = 0;
        for(int i = 1 ; i < n ; i++)
        {
            if(string[i] == string[i-1])
            {
                count ++;
            }
            

        }
        if(count == 0 || count == 2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        
    }
}