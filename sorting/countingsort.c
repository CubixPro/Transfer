#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *counting_sort(int *arr, int len, int range, int *arr2)
{
    int *aux = (int *)malloc(len * sizeof(int));
    int *count = (int *)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        count[arr[i]]++;
    }
    /*printf("Step 1 : ");
    for(int i = 0; i<range; i++)
    {
        printf("%d ", count[i]);
    }*/
    for (int i = 1; i < range; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    /*printf("Step 2 : ");
    for(int i = 0; i<range; i++)
    {
        printf("%d ", count[i]);
    }*/
    for (int i = range - 1; i >= 0; i--)
    {
        count[i] = count[i - 1];
    }
    /*printf("Step 3 : ");
    for(int i = 0; i<range; i++)
    {
        printf("%d ", count[i]);
    }*/
    for (int i = 0; i < len; i++)
    {
        aux[count[arr[i]]] = arr2[i];
        count[arr[i]]++;
    }
    return aux;
}
void  radix_sort(int *arr, int len, int digit_length, int base)
{
    int *digits = (int *)malloc(len * sizeof(int));
    int *aux = (int *)malloc(len * sizeof(int));
    int *temp = (int *)malloc(len * sizeof(int));
    for(int i = 0; i < len ; i++)
    {
        temp[i] = aux[i];
    }
    for(int j = 1; j <= digit_length ; j++)
    {
        for (int i = 0; i < len; i++)
        {
            digits[i] = temp[i] % 10 ; 
            temp[i] = temp[i]/10;
        }
        aux = counting_sort(digits, len, base, arr);
        printf("Run %d : ", j);
        for(int k = 0 ; k <= len ; k++)
        { 
            printf("%d ", aux[k]);
            arr[k] = aux[k];
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i <= len ; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int len, range;
    printf("Enter the number of values");
    scanf("%d", &len);
    //printf("Enter the range of values");
    //scanf("%d", &range);
    int *arr = (int *)malloc(len * sizeof(int));
    int *aux = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    /*int *arr2 = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr2[i]);
    }
    aux = counting_sort(arr, len, range, arr2);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", aux[i]);
    }*/
    radix_sort(arr, len, 3, 10);
}
