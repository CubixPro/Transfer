#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int  main()
{
     long int testcases;
     scanf("%ld", &testcases);
     for(long int i = 0 ; i < testcases ; i++)
     {
          char str[10000];
         long int a, b;
         scanf("%s %ld %ld", str, &a, &b);
        sort(&str + a, &str + b);
        printf("%s\n", str);
     }
}
