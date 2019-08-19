#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        string str; 
        cin >> str;
        int val = str.length();
        int* c0; int* c9;
        c0 = new int[val];
        c9 = new int[val];
        int count = 0 ;
        
        for(int i = 0 ; i < str.length() ; i++)
        {
            char ch = str[i];
            if(ch == '(' && i > 0)
                c9[i] = c0[i - 1] + 1;
            else if(i > 0 && ch != '(')
            {
                c9[i] = c0[i - 1];
            }
            else 
            {
                if(i == '(')
                    c9[0] = 1;
                else
                {
                    c9[0] = 0;
                }
                
            }

        }
        for(int i = str.length() - 1 ; i >= 0 ; i-- )
        {
            char ch = str[i];
            if(ch == ')' && i < (str.length() - 1))
                c0[i] = c0[i + 1] + 1;
            else if(i < (str.length() - 1) && ch != '(')
            {
                c0[i] = c0[i + 1];
            }
            else 
            {
                if(i == ')')
                    c0[str.length() - 1] = 1;
                else
                {
                    c0[str.length() - 1] = 0;
                }
                
            }
 

        }

            
    } 
}