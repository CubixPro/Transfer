#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int n;
        int count = 0 ;
        scanf("%d", &n);
        char str[n + 1];
        scanf("%s", &str);
        for(int i = 0  ; i < n ; i++)
        {
            if(str[i] == '0')
                count++;
        }
        printf("%d", count);
    }
}