#include<stdio.h>
#include<stdlib.h>
void print_array(int arr[], int init, int length)
{
    //int length = sizeof(arr)/sizeof(int);
    for(int i = init; i < length;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int u, int *count)
{
    int x = l, y = m + 1;
    while((x <= m) && (y <= u))
    {
        if(arr[y] < arr[x])
        {
            *count = *count + (m -x +1);
            y++;
        }
        else if(arr[y] < arr[x])
        {
            *count = *count + (m -x);
            y++;
        }
        else
        {
            x++;
        }
    }
    //printf("%d %d %d \n", l, m, u);
    int i = l;
    int j = m + 1;
    int *aux = (int *)malloc(sizeof(int) * (- l + u + 1));
    /*int *right = (int *)malloc(sizeof(int) * (m -l +1));
    int *left = (int *)malloc(sizeof(int) * (u -m));
    int*/ 
    int k = 0;
    while( i<=m && j<=u )
    {
        //printf("True\n");
        if(arr[i] <= arr[j])
        {
            aux[k] = arr[i];
            i++;
        }

        else if(arr[i] > arr[j])
        {
            aux[k] = arr[j];
            j++;
//            printf("True");*count++;
        }
        k++;
    }
    
    while(i <= m)
    {
        aux[k] = arr[i];
        k++;
        i++;
//        printf("True");*count++;
    }
    while(j <= u)
    {
        aux[k] = arr[j];
        k++;
        j++;
    }
    for(int i =l,  k = 0; i< (- l + u + 1 +l); i++)
    {
        arr[i] = aux[k];
        k++;
    }
    //printf("Aux : ");
    //print_array(aux, 0, -l +u +1);
    //print_array(aux, l, -l +u +1);
    //printf("%d \n ", *count);
}
void mergesort(int arr[], int l, int u, int *count)
{
    if( l == (u - 1) )
    {
        if (arr[l] > arr[u])
        {
            int temp = arr[l];
            arr[l]   = arr[u];
            arr[u]   = temp;
            //printf("True");
            *count++;
        }
        return ;
    }
    else if( l == u )
    {
        return ;
    } 
    
    int m = (l + u)/2;
    mergesort(arr, l, m, count);
    //printf("Array : ");
    //print_array(arr, 0, 6); 
    mergesort(arr, m + 1, u, count);
    //printf("Array : ");
    //print_array(arr, 0, 6); 
    merge(arr, l, m, u, count);
    //printf("Array : ");
    //print_array(arr, 0, 6);
    //printf("%d ", count);
    printf("%d ", *count);
}

int main()
{
    int n;
    int count = 0;
    int *p = &count;
    printf("n = ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n-1, p);
    printf("Array : ");
    print_array(arr, 0, n);
    printf("%d ", count);
}