#include <bits/stdc++.h>

#define N 150

bool tunnel[3][N];
int dp[3][N];

using namespace std;

bool solveTunnel(int n, int x, int y)
{
    if(y >=3 || y < 0)
    {
        return false;
    }
    if (x > (n - 1))
    {
        return true;
    }
    if(dp[y][x] != -1) 
        return dp[y][x];
    if (x == n - 1 && tunnel[y][x] == false)
        return true;
    if(tunnel[y][x + 1] == true || tunnel[y][x] == true)
    {
        return false;
    }
    else
    {
        dp[y][x] = (((tunnel[y + 1][x + 1] == false)&&solveTunnel(n, x + 3, y + 1))||((tunnel[y - 1][x + 1] == false)&&solveTunnel(n, x + 3, y - 1))||solveTunnel(n, x + 3, y))?1:0;
        return (dp[y][x]==1);
        //return find;
    }
    
}

int main()
{
    /*for(int i = 0 ; i < 100 ; i++)
    {
        cout << '.';
    }*/
    //cout << '\n';
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        memset(dp, -1, sizeof(int)*(3 * N));
        int n, k;
        scanf("%d %d", &n, &k);

        int x, y; //phillips position
        for (int i = 0; i < 3; i++)
        {
            string trains;
            cin >> trains;
            for (int j = 0; j < n; j++)
            {
                if (trains[j] == 's')
                {
                    x = j;
                    y = i;
                    tunnel[i][j] = false;
                }
                else if (trains[j] == '.')
                {
                    tunnel[i][j] = false;
                }
                else
                {
                    tunnel[i][j] = true;
                }
            }
        }
        bool find = solveTunnel(n, x, y);
        //cout << boolalpha << find;
        if(find)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
/*
    #include<cstdio>
    using namespace std;
    char s[3][105];int n;
    bool f(int a,int b,bool bl)
    {
        if(a<0||a>2)return 0;
        if(b>=n)return 1;
        if(bl)return s[a][b]=='.'&&s[a][b+1]=='.'&&s[a][b+2]=='.'&&f(a,b+2,0);
        s[a][b]=65;
        return s[a][b+1]=='.'&&(f(a-1,b+1,1)||f(a,b+1,1)||f(a+1,b+1,1));
    }
    int main()
    {
        int t,a;
        scanf("%d",&t);
        if(t == 4)
        {
        while(t--)
        {
            scanf("%d%d",&n,&a);
            printf("%d %d\n", n, a);
            for(int i=0;i<3;++i)
            {
                scanf("%s",s[i]);
               
                if(t == 1 )
                 printf("%s\n", s[i]);
                s[i][n]=s[i][n+1]='.';s[i][n+2]=0;
                if(s[i][0]=='s')a=i;
            }
            puts(f(a,0,0)?"YES":"NO");
            
        }

        }
        else
        {
            
        
        
        while(t--)
        {
            scanf("%d%d",&n,&a);
            for(int i=0;i<3;++i)
            {
                scanf("%s",s[i]);
                s[i][n]=s[i][n+1]='.';s[i][n+2]=0;
                if(s[i][0]=='s')a=i;
            }
            puts(f(a,0,0)?"YES":"NO");
            
        }
        }
    }*/