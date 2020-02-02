#include<stdio.h>
void find_route(int row, int column)
{
    int initx = 2;
    int inity = 3;
    int iinity;
    for(int k = 1 ; k <= row*column ; k++)
    {
        printf("%d %d\n", initx, inity);
        if(k % 2 == 1)
        {
            iinity = inity;
            inity = (inity + (column - 2)) % column;
        
        }
        else 
        {
            //inity = (inity + (column / 2 + 1)) % column;
            inity = (++iinity) % column;
        }
        if(inity == 0)
                inity = column;

        
        if((k % (column*2)) != 0)
        {
            initx = (initx % 2 == 0)?(-- initx):(++ initx);
            //printf("%d \n", initx);
        } 
        else 
        {
            initx = k/column + 2;
            inity = 3; 
        }
    }

}
int main()
{
    int testcases;
    scanf("%d", &testcases);
    for(int i = 1 ; i <= testcases ; i++)
    {
        int row, column;
        scanf("%d %d", &row, &column);
        printf("Case #%d: ", i);
        if(row%2 == 0 && column >= 4)
        {
            printf("POSSIBLE\n");
            find_route(row, column);
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
        
    }
}