#include<stdio.h>
#include<stdlib.h>
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        long int n;
        scanf("%ld", &n);
        char *string = (char*)malloc((n + 1) * sizeof(char));
        char ch;
        scanf("%s %c", string, &ch);
        
       
        long int count = 0;
        long int val = n*(n + 1)/2; 
        for(int i = 0 ; i < n ; i++)
        {
            //printf("%c", ch);
            if(string[i] != ch)
                count++;
            else
            {
                //printf("%ld\n", count);
                val = val - count*(count + 1)/2;
                count = 0;
            }
            
        }
        val = val - count*(count + 1)/2;
        printf("%ld\n", val);
    }
}