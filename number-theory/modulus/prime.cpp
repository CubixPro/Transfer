#include<iostream>
#include<set>

using namespace std;
set<int> primes;
void primefact(int val)
{
    while(val%2 == 0)
    {
        val = val/2;
        primes.insert(2);
    }
    for(int i = 3 ; i*i <= val ; i+=2)
    {
        while(val%i == 0)
        {
            val = val/i;
            primes.insert(i);
        }
    }
    if(val > 2)
        primes.insert(val);
}
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int m = 0;
       if(m == 0) 
       {
            printf("1 997\n");
            m++;
       }
       int num;
       scanf("%d", &num);
       int val = 997*997 - num;
       primefact(val);
       set<int> :: iterator it;
       it = primes.begin();
       while(it!=primes.end())
       {
           printf("1 %d\n", *it);
           int ret ;
           scanf("%d", &ret);
           if(ret == 0)
           {
               printf("2 %d", *it);
               string found;
               cin >> found;
               if(found == "yes")
                break;
               else
               {
                   return 1;
               }
               
           }
           else if(ret == -1)
           {
               return 1;
           }
            it++;
       }
    }
}
        
    

            