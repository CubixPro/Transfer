#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

void traverse(vector<long int> graph[], long int source, bool visited[], unsigned long long int val[], unsigned long long int mod[], unsigned long long int gcd[], long long int sub[]);

int main()
{
    long int testcases;
    scanf("%ld", &testcases);
    while (testcases-- != 0)
    {
        long int n;
        scanf("%ld", &n);
        if(n == 0){
            return 0;
        }
        vector<long int> graph[n + 1];
        bool visited[n + 1];
        long long int sub[n + 1];
        for (long int i = 1; i <= (n - 1); i++)
        {
            long int x, y;
            scanf("%ld %ld", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        //printf("wtf\n");
        for (long int i = 1; i <= n; i++)
        {
            visited[i] = false;
            sub[i] = -1;
        }
        unsigned long long int val[n + 1];
        unsigned long long int mod[n + 1];
        for (unsigned long long int i = 1; i <= n; i++)
        {
            scanf("%llu", &val[i]);
        }
        for (unsigned long long int i = 1; i <= n; i++)
        {
            scanf("%llu", &mod[i]);
        }
        unsigned long long int gcd[n + 1];
        gcd[1] = val[1];
        //printf("wtf\n");
        traverse(graph, 1, visited, val, mod, gcd, sub);
        for (long int i = 1; i <= n; i++)
        {
            if (sub[i] != -1)
                printf("%lld ", sub[i]);
        }
        printf("\n");
    }
    return 0;
}

void traverse(vector<long int> graph[], long int source, bool visited[],unsigned long long int val[],unsigned long long int mod[], unsigned long long int gcd[], long long int sub[])
{
    visited[source] = true;
    for (long int i = 0; i < graph[source].size(); i++)
    {
        if (visited[graph[source][i]] == false)
        {
            gcd[graph[source][i]] = __gcd(val[graph[source][i]], gcd[source]);
            //printf("%llu \n", gcd[graph[source][i]]);
            traverse(graph, graph[source][i], visited, val, mod, gcd, sub);
        }
    }

    if ((graph[source].size() == 1 && source != 1) || graph[source].size() == 0)
    {
        sub[source] = mod[source] - __gcd(mod[source], gcd[source]);
    }
}