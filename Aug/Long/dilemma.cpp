#include<iostream>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        string str;
        cin >> str;
        int c1 = 0 ; 
        for(int i = 0 ; i < str.length() ; i++)
        {
            char ch = str[i];
            if(ch == '1')
                c1++;
        }
        if(c1 % 2 == 0)
            printf("LOSE");
        else
        {
            printf("WIN");
        }
       printf("\n"); 
    }
}