#include<bits/stdc++.h>

using namespace std;

string xor_strings(string a, string b){
    string final = "";
    for(int i = 0 ; i < a.length() ; i++)
    {
        char ca = a[i];
        char cb = b[i];
        char f = ((ca - 48) xor (cb - 48)) + 48;
        final = final + f;
    }
    return final;

}

int count(string a)
{
    int count = 0;
    for(int i = 0 ; i < a.length() ; i++)
    {
        if(a[i] == '0')
        {
            continue;
        }
        else
        {
            count++;
        }
        
    }
    return count;
}

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        string val[n];
        for(int i = 0 ; i < n ; i ++)
        {
            cin >> val[i];
        }
        string final = val[0];
        for(int i = 1 ; i < n ; i++)
        {
            final = xor_strings(final, val[i]);
        }
        int num = count(final);
        cout << num << '\n';
    }
}