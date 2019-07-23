#include<list>
#include<algorithm>
#include<iostream>

using namespace std;
void print(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
int main()
{
    list<int> l1;
    while (true)
    {
        int n ; 
        scanf("%d", &n);
        if(n == 1)
        {
            l1.push_front(1);

        }
        else if(n == 2)
        {
            l1.push_back(2);
        }
        else if(n == 3)
        {
            list<int> :: iterator it = l1.begin();
            advance(it, 2);
            l1.insert(it, 1);
        }
        else if(n == 4)
        {
            list<int> :: iterator it = l1.begin();
            advance(it, 2);
            l1.erase(it);
        }
        else if(n == 5)
        {
            print(l1);
        }
        else if(n == 6)
        {
            return 0;
        }
    }
}