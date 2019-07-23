#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

typedef long long int lld;

void print(list<lld> g)
{
    list<lld>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
int main()
{
    int testcases;
    scanf("%d", &testcases);
    for (int u = 1; u <= testcases; u++)
    {
        int n;
        scanf("%d", &n);
        lld arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        int counter = 0;
        list<lld> l1;
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            l1.push_back(arr[i]);
            max += arr[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            //`printf("%d ", i);
            list<lld>::iterator val = l1.begin();
            int min = max;
            int pos;
            list<lld>::iterator it = l1.begin();
            if (i == (n - 1))
            {
             //   print(l1);
                counter += *it;
                continue;
            }
            for (int j = 0; j < n - i; j++)
            {
                if (j == (n - i - 1))
                {
                    int count = *it + *(val);
                    if (count < min)
                    {
                        printf("hello");;
                        min = count;
                        pos = j;
                    }
                    //printf("hello");
                    continue;
                }
                //printf("%d", __LINE__);
                int count = *it;
                advance(it, 1);
                count += *it;
                if (count < min)
                {
                    min = count;
                    pos = j;
                }
            }
            list<lld>::iterator it2 = l1.begin();
            //printf("%d %d ;", min, pos);
            advance(it2, pos);
            l1.erase(it2);
            list<lld>::iterator it1 = l1.begin();
            advance(it1, pos);
            //printf("%lld", *it1);
            if (it1 == l1.end())
            {
               // printf("hello");
               // print(l1);
               //val = l1.begin();
                l1.erase(val);
                list<lld>::iterator val2 = l1.begin();
                if (val2 == l1.end())
                {
                    counter += min;
                    //printf("%d %d only one element left\n", counter, i);
                    continue;
                    //break;
                }
                l1.insert(val2, min);
                counter += min;
                //printf("%d %d\n", counter, i);
                //print(l1);
                continue;
               
            }
            print(l1);
            list<lld>::iterator temp = l1.begin();
            advance(temp, pos);
                l1.erase(temp);
            //printf("101\n"); 
            list<lld> :: iterator temp2 = l1.begin();
            advance(temp2, pos);
            l1.insert(temp2, min);
            counter += min;
            //printf("102\n");
            //printf("%d %d\n", counter, i);
            //print(l1);
            
        }
        printf("%d\n", counter);
    }
}