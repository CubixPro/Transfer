#include<iostream>
#include<algorithm>
#include<vector>
#define mod 1000000007

using namespace std;
vector <int> num;
int k, d;
int sum_of_digits[2000][10][2];//check = 1 -> equal till now; check = 0 -> has become lower
int sum_mod[2000][10][2];

int call(int position, int digit, int check)
{
    int res = 0;
    int msb;
    if(check == 1)
    {
        msb = num[position];
    }
    else
    {
        msb = 9 ;

    }
    for(int i = 0 ; i <= msb ; i++)
    {
        if(i == num[position])
        {
            check = 1;
        }
        else
        {
            check = 0;
        }
        sum_of_digits[position][i][check] = sum[position - 1]
        
    }    
}
int main()
{
    memset(sum_of_digits, -1, sizeof(int));
    memset(sum_mod, -1, sizeof(int));
    scanf("%d %d", &k, &d);
    string a, b;
    cin >> a >> b;
    for(int i = 0 ; i < a.length() ; i++)
    {
        num.push_back(a[i]);
    }    
    int vala  = call(0, 0, 1);
    num.clear();
    for(int j = 0 ; j < b.length() ; j++)
    {
        num.push_back(b[j]);
    }    
    int valb = call(0, 0, 1);
    int final = valb - vala;
}