//only constraints 1
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[20][2];
vector<int> num;
int k;

int count0(int digit[10], bool exists[10]) //digit[11] is initialized to 0 and false
{
    int count = 0;
    for (int i = 1; i < 10; i++)
    {
        if (digit[i] == 0 && exists[i] == true)
            count++;
    }
    return count;
}
int call(int pos, int check, int digit[10], bool exists[10]) //0->has become lower; 1->equal till now
{
    /*if (dp[pos][check] != -1)
        return dp[pos][check];
        */
    if (pos == num.size())
    {
        int count = count0(digit, exists);
        if (count >= k)
            return 1;
        else
            return 0;
    }
    int msb;
    if (check == 1)
    {
        msb = 9;
    }
    else
    {
        msb = num[pos];
    }
    int res = 0;
    for (int i = 0; i <= msb; i++)
    {
        int newcheck = 1;
        int newdigit[10];
        bool newexists[10];
        if (i == num[pos] && check == 0)
            newcheck = 0;
        for (int j = 1; j < 10; j++)
        {
            newdigit[j] = (digit[j] * 10 + i) % j;
            newexists[j] = exists[j];
        }
        newexists[i] = true;
        res += call(pos + 1, newcheck, newdigit, newexists);
    }
    //dp[pos][check] = res;
    return res;
}

string decrease_by_1(string str)
{
    int length = str.length() - 1;
    while (str[length] == '0')
    {
        length--;
    }
    str[length]--; 
    //cout << str;
    return str;
}
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
   
    bool exists[10];
    memset(exists, false, sizeof(exists));
    int digit[10];
    memset(digit, 0, sizeof(digit));
    memset(dp, -1, sizeof(dp));
    string str1, str2;
    cin >> str1;
    cin >> str2;
    scanf("%d", &k);
    str1 = decrease_by_1(str1);
    for(int i = 0 ; i <= str1.length() - 1 ; i++)
    {
        num.push_back(str1[i] - '0');
    }
    //printf("%d", k);
    int val1 = call(0, 0, digit, exists);

    num.clear();
    memset(exists, false, sizeof(exists));
    memset(digit, 0, sizeof(digit));
    for(int i = 0 ; i <= str2.length() - 1 ; i++)
    {
        num.push_back(str2[i] - '0');
    }
    int val2 = call(0, 0, digit, exists);
    int final = val2 - val1;
    printf("%d %d\n", val2, val1);
    printf("%d\n", final);
    num.clear();
    }


}