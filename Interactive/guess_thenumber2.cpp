#include <cstdio>
#include <cstring>
#include <iostream>
int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int a, b;
        int mid;
        scanf("%d %d", &a, &b);
        while(a <= b)
        {
        //scanf("%d %d", &a, &b);
        mid = (a + b)/2;
        printf("%d\n", mid);
        fflush(stdout);

        char response[100];
        scanf("%s", response);
        if(strcmp(response, "TOO_BIG") == 0)
        {
            b = mid - 1;
            //printf("%d %d\n", a, b);
            continue;
        }
        else if(strcmp(response, "TOO_SMALL") == 0)
        {
            a = mid + 1;
            continue;
        }
        else if(strcmp(response, "CORRECT") == 0)
        {
            break;
        }
        }
    }



}