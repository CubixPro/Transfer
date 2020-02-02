#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
	array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("n"); 
} 

// Driver program to test above functions 
/*int main() 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Sorted array: n"); 
	printArray(arr, n); 
	return 0; 
}*/ 

int main() {

    int n, k, m;
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&m);
    int* targets = (int *)malloc(n * sizeof(int ));
    for(int i= 0 ;i<n;i++)
    {
        scanf("%d",&targets[i]);
    }
    int count = 0;
    /*for(int i = 0;i<n;i++)
    {
        for(int j = 0;j< n - 1 - i;j++)
        {
            if(targets[j]>targets[j+1])
            {
                int temp = targets[j];
                targets[j] = targets[j+1];
                targets[j+1] = temp;
            }
        }
    }*/

	quickSort(targets, 0, n-1); 
    //printArray(targets,n);
    for(int  i =0 ;i<n;i++)
    {
        /*if(targets[i]<=m && k!=0)
        {
            count++;
            k--;
        }*/

        int arrows = (targets[i]%m == 0)?targets[i]/m:targets[i]/m + 1;
        
        k = k - arrows;
        if(k == 0)
        {
            count++;
            break;
        }
        else if (k<0)
        {
            break;
        }
        else
        {
            count++;
        }

        
    }
    printf("%d",count);

    
    return 0;
}
