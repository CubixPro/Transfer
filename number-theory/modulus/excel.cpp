#include<iostream>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    long int power_26[6];
   /* power_26[0] = 1;

    for (int i = 1; i <= 5; i++)
    {
        power_26[i] = power_26[i - 1] * 26;
    }*/
    while (testcases-- != 0)
    {
        long int n;
        scanf("%ld", &n);
        string name;
        while(n != 0)
        {
            if(n % 26 == 0)
            {
                //TODO
                int l = 26;
                n = (n - 26)/26;
                name = (char)(l + 64) + name;
            }
            else
            {
                int l = n%26;
                char letter = 64 + l; 
                name = letter + name;
                n = n/26;
            }
            
        }  
        cout << name << '\n';
    }
}