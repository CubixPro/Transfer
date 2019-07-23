#include <stdio.h>
#include <stdlib.h>
void swim(int arr[], int k)
{
    while (k > 1 && arr[k] > arr[k / 2])
    {
        int t = k / 2;
        {
            int temp = arr[k];
            arr[k] = arr[t];
            arr[t] = temp;
        }
        k = t;
    }
}
void sink(int arr[], int n, int k)
{
    while (k <= n / 2 && (arr[k] < arr[2 * k] || arr[k] < arr[2 * k + 1]))
    {
        int t = 2 * k;
        if (t != n)
        {
            if (arr[t] > arr[t + 1])
            {
                int temp = arr[t];
                arr[t] = arr[k];
                arr[k] = temp;
                k = t;
            }
            else
            {
                int temp = arr[t + 1];
                arr[t + 1] = arr[k];
                arr[k] = temp;
                k = t + 1;
            }
        }
        else
        {
            if (arr[t] > arr[k])
            {
                int temp = arr[t];
                arr[t] = arr[k];
                arr[k] = temp;
                k = t;
            }
            else
            {
                break;
            }
        }
    }
}
int main()
{
    int testcases;
    scanf("%d", &testcases);
    while (testcases-- != 0)
    {
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc((n + 1) * sizeof(int));
        arr[0] = 0;
        for (int i = 1; i < (n + 1); i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = (n + 1) / 2; i >= 1; i--)
        {
            sink(arr, n, i);
            /*for (int i = 1; i < n + 1; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");*/
        }
        /*for (int i = 1; i < n + 1; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");*/
        for (int i = n; i >= 1; i--)
        {
            int temp = arr[i];
            arr[i] = arr[1];
            arr[1] = temp;

            sink(arr, i - 1, 1);
        }

        //printf("Array : ");
        for (int i = 1; i < n + 1; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}