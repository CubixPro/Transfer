#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0)
    {
        int m, n, k;
        scanf("%d %d %d", &m, &n, &k);
        int index[2][k];
        typedef vector<bool> BOOLAR;
        vector<BOOLAR> tree ;

        for (int i=0; i< m; i++)
        {
            BOOLAR row;
            for (int j=0; j<n; j++)
            {
                row[j] = false;
            }
            tree[i] = row;
        }
        //bool tree[m][n];
        /*for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                tree[i][j] = false;
        //        printf("%d ", tree[i][j]);
            }
            //printf("\n");
        }*/
        //printf("%d \n", tree[1][1]);
        for(int i = 0; i < k; i ++)
        {
            scanf("%d %d", &index[0][i], &index[1][i]);
            index[0][i]--;
            index[1][i]--;
            tree[index[0][i]][index[1][i]] = true;
            //printf("%d \n", tree[index[0][i]][index[1][i]] );
        }
        //printf("%d \n", tree[1][1]);
        //printf("%d \n", true);
        /*for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                printf("%d ", tree[i][j]);
            }
            printf("\n");
        }*/

        int fence = 0;
        for(int i = 0; i < k ; i++)
        {
            bool border = false;
            int row = index[0][i];
            int colomn = index[1][i];
            if(row == 0)
                fence+=1;
            if(row == (m-1))
                fence+=1;
            if(colomn ==0)
                fence += 1;
            if(colomn == (n-1))
                fence += 1;
            //if(row != 0 && tree[row - 1][colomn] == false)
            //    fence += 1;
            if(((BOOLAR)(tree[row-1]))[colomn] == false)
                fence+=1;
            /*if(row != (m-1) && tree[row+1][colomn] == false)
                fence+=1;
            if(colomn != 0 && tree[row][colomn - 1]==false)
                fence+=1;
            if(colomn !=(n - 1) && tree[row][colomn + 1]==false)
                fence+=1;
            //printf("%d\n", fence);*/
        }
        printf("%d \n", fence);
            

    }
}
