#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int found = 0;
    outer:for(int i = 0;i<n;i++)
    {
        char str1[100];
        int found = 0;
        fgets(str1,100,stdin);
        char *str = str1
        while(*str!= '\n')
        {
            if (*str == 'n' && *(str++) == 'o' && *(str++) == 't')
            {
             printf("Regular Fancy");
             found = 1;
            }
            str++;
        }
        if (found == 0)
        printf("fancy");
        found = 0;
    }
}