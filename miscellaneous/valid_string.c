#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int testcases = 0 ;
    scanf("%d",&testcases);
    char** str = (char **)malloc(testcases*sizeof(char*));
    for(int i=0 ;i<testcases;i++)
    {
        str[i] = (char *)malloc(100000*sizeof(char));
    }
    getchar();
    for(int i = 0 ; i < testcases; i ++)
    {
        gets(str[i]);
    }
    /*for(int i = 0;i < testcases; i++)
    {
        printf("%s \n", str[i]);
    }*/
    for(int  i = 0;i< testcases;i++)
    {

        int valid = 1;
        int n = -1;
        int j = 0 ;
       for(int j = 0;j<strlen(str[i]); j++) 
        {
            if (n!= -1)
                j--;
            char ch = str[i][j];
            if (ch>=48 && ch<=57)
            {
                n = ch - 48;
                j++;
                int count = 0;
                 while(!(str[i][j]>=48&&str[i][j]<=57) && j!=(strlen(str[i])))
                {
                    if(str[i][j] == '?')
                        count++;
                   j++; 
                } 
                int n2 = str[i][j] - 48;
                if(j == strlen(str[i]))
                    break;
                if((n+n2)!=count)
                {
                    valid = 0;
                    break;
                }
                else
                {
                    n = n2;
//                    j++;
                    continue;
                }
            }
            //j++;
        }
        if(valid == 0)
        {
            printf("Invalid \n");
        }
        else 
        {
            printf("Valid \n");
        }
    }
    return 0;
}