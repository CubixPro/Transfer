#include<algorithm>
#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<string , int> umap1;
unordered_map<string , int> umap0;

int operation(int x, int y, char a)
{
    switch(a)
    {
        case 'a': return x&y;
        case 'o': return x|y;
        case 'x': return x^y;
    }
}

int countmax(string str, string op, int res_val)
{
    if(str.length() == 1)
    {
        return (str[0] == '1')?1:0;
    }
    if(res_val == 1)
    {
        if (umap1.find(str) != umap1.end())
            return umap1.at(str);
        
    }
    else if(res_val == 0 && umap0.find(str) != umap0.end())
        return umap0.at(str);
    int count = 0;
    umap0[str] = 0;
    umap1[str] = 1;
    for(int i = 0 ; i < str.length() ; i ++)
    {
        char oper = op[i];
        int val = operation(1, 1, op[i]);
        int count1 = countmax(str.substr(0, i + 1), op.substr(0, i ), 1);
        int count2 = countmax(str.substr(i + 1, str.length() ), op.substr(i + 1, str.length() - 1), 1);
        if(val == 0)
            umap0[str] += min(count1, count2);
        else if(val == 1)
            umap1[str] += min(count1, count2);

         val = operation(0, 0, op[i]);
         count1 = countmax(str.substr(0, i + 1), op.substr(0, i), 0);
         count2 = countmax(str.substr(i + 1, str.length()), op.substr(i + 1, str.length() - 1), 0);
        if(val == 0)
            umap0[str] += min(count1, count2);
        else if(val == 1)
            umap1[str] += min(count1, count2);

         val = operation(0, 1, op[i]);
         count1 = countmax(str.substr(0, i + 1), op.substr(0, i), 0);
         count2 = countmax(str.substr(i + 1, str.length()), op.substr(i + 1, str.length() - 1), 1);
        if(val == 0)
            umap0[str] += min(count1, count2);
        else if(val == 1)
            umap1[str] += min(count1, count2);

         val = operation(1, 0, op[i]);
         count1 = countmax(str.substr(0, i + 1), op.substr(0, i), 1);
         count2 = countmax(str.substr(i + 1, str.length()), op.substr(i + 1, str.length() - 1), 0);
        if(val == 0)
            umap0[str] += min(count1, count2);
        else if(val == 1)
            umap1[str] += min(count1, count2);
 
    }
}

int main()
{
    string numbers;
    string op;
    cin >> numbers;
    cin >> op;
    int n;
    int m;
    scanf("%d %d", &n, &m);
    printf("%d", countmax(numbers.substr(n, m + 1), op.substr(n, m), 1));

}