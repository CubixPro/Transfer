#include <stdio.h>
int ending_element;
int length;
int ending_steps;
int** dp;
int count_ways(int arr[], int starting_element, int steps)
{
    if (steps == ending_steps)
    {
        if (ending_element == starting_element)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] != starting_element)
            {
                sum += count_ways(arr, arr[i], steps + 1);
            }
        }
        return sum;
    }
}
int main()
{
    int array[3] = {1, 2, 3};
    ending_element = 2;
    length = 3;
    ending_steps = 4;
   
    int ways = count_ways(array, 1, 1);
    printf("%d ", ways);
}