#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int length;
void updateArrayfull(int st[], int ss, int se, int i, int orig, int final, int si)
{
    if(i > se || i < ss)
    {
        return ;
    }
    else 
    {

        st[si] = st[si] - orig + final; 
        if(ss == se)
            return ;
        int mid = (ss + se)/2;
        updateArrayfull(st, ss, mid, i, orig, final, si*2 + 1);
        updateArrayfull(st, mid + 1, se, i, orig, final, si*2 + 2);
    }
}
void updateArray(int arr[], int n ,int i, int x, int *st)
{
    updateArrayfull(st, 0, n - 1, i, arr[i], x, 0);
}
int getvalfull(int *st,int ss,int se,int qs,int qe,int i)
{
    //printf("se : %d ss : %d qs : %d qe : %d\n", ss, se, qs, qe);
    if((ss >= qs) && (se <= qe))
    {
        //printf("i = %d ; %d\n", i, st[i]);
        return st[i];
    }
    else if((se < qs) || (ss > qe))
    {
        //printf("i = %d ; %d\n", i, 0);
        return 0;
    }
    else
    {
        //printf("i = %d \n", i);
        int mid = (ss + se)/2;
        return getvalfull(st, ss, mid, qs, qe, i*2 + 1) + getvalfull(st, mid + 1, se, qs, qe, i*2 + 2);

    }
    
}
int getval(int *st,int n, int qe, int qs)
{
    //printf("%d : ", getvalfull(st, 0, n-1, qe, qs, 0));
    return getvalfull(st, 0, n-1, qe, qs, 0);
}
int constructSTfull(int *arr, int l, int m, int *st, int i)
{
    if(l == m)
    {
        st[i] = arr[l];
        return arr[l];
    }
    int mid = (l + m)/2;
    st[i] = constructSTfull(arr, l, mid, st, i*2 + 1) + constructSTfull(arr, mid + 1, m, st, i*2 + 2);
    return st[i];

}
int* constructST(int *arr, int n)
{
    int x = ceil(log2(n));
     length = 2 * pow(2,x) - 1;
    int* st = (int*)malloc(length * sizeof(int));
     constructSTfull(arr, 0, n-1, st, 0);
    return st;
}
void printST(int* arr, int length1)
{
    for(int i = 0; i < length1 ; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {2, 3, 5, 1, 6};
    int* st = constructST(arr, 5);
    printf("%d ", length);
    printST(st, length);
    printf("val = %d",getval(st, 5, 1, 3));
    updateArray(arr, 5, 2, 10, st);
    printST(st, length);
}