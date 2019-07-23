#include<algorithm>
#include<iostream>

using namespace std;
int operation(int x, int y, char a)
{
    switch(a)
    {
        case 'a': return x&y;
        case 'o': return x|y;
        case 'x': return x^y;
    }
}
void calcways(int* num, string op, int res_val, int length)
{
    int dp[length][2];
    for(int i = 0 ; i < length ; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    dp[0][num[0]]++;
    //printf("%d\n", operation(num[0], num[1], op[0]));
    dp[1][operation(num[0],num[1], op[0])]++;
    for(int i = 2 ; i < length ; i++)
    {
        int res;
        res = operation(0, num[i], op[i - 1]);
        dp[i][res] += dp[i - 1][0];
        res = operation(1, num[i], op[i - 1]);
        dp[i][res] += dp[i- 1][1];
    
        res = operation(0, operation(num[i - 1], num[i], op[i - 1]), op[i - 2]);
        dp[i][res] += dp[i - 2][0];
        res = operation(1, operation(num[i - 1], num[i], op[i - 1]), op[i - 2]);
        dp[i][res] += dp[i - 2][1];



    }
    printf("%d\n", dp[length - 1][res_val]);

}
int main()
{
    //printf("%d", operation(1, 1, 'x'));
    int arr[] = {1, 1, 0, 1};
    calcways(arr, "aoa", 1, 4);
}