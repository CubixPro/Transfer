import java.io.*;
import java.util.*;
import java.math.*;
// Java program for implementation of QuickSort 
class Node
{
    int x;
    int index;
}
class chdiger
{ 
	/* This function takes last element as pivot, 
	places the pivot element at its correct 
	position in sorted array, and places all 
	smaller (smaller than pivot) to left of 
	pivot and all greater elements to right 
	of pivot */
	int partition(Node arr[], int low, int high) 
	{ 
		int pivot = arr[high].x; 
		int i = (low-1); // index of smaller element 
		for (int j=low; j<high; j++) 
		{ 
			// If current element is smaller than or 
			// equal to pivot 
			if (arr[j].x <= pivot) 
			{ 
				i++; 

				// swap arr[i] and arr[j] 
                Node temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
			} 
		} 

		// swap arr[i+1] and arr[high] (or pivot) 
		Node temp = arr[i+1]; 
		arr[i+1] = arr[high]; 
		arr[high] = temp; 

		return i+1; 
	} 


	/* The main function that implements QuickSort() 
	arr[] --> Array to be sorted, 
	low --> Starting index, 
	high --> Ending index */
	void sort(Node arr[], int low, int high) 
	{ 
		if (low < high) 
		{ 
			/* pi is partitioning index, arr[pi] is 
			now at right place */
			int pi = partition(arr, low, high); 

			// Recursively sort elements before 
			// partition and after partition 
			sort(arr, low, pi-1); 
			sort(arr, pi+1, high); 
		} 
	} 

	/* A utility function to print array of size n */
	static void printArray(Node arr[]) 
	{ 
		int n = arr.length; 
        for (int i=0; i<n; ++i) 
        {
            System.out.println(arr[i].x+" "+arr[i].index); 
        }
		System.out.println(); 
	} 

	// Driver program 
	public static void main(String args[]) throws IOException
	{ 
		/*
        int n = 5;
        for(int i = 0; i < 5 ; i++)
        {
            arr[i] = new Node();
            arr[i].x = (int)(Math. random() * 10);
            arr[i].index = i;
        }
         */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcases = 0;
        testcases = Integer.parseInt(br.readLine());
        while(testcases-- != 0)
        {
            String line = br.readLine();
            BigInteger num = new BigInteger((line.substring(0, line.indexOf(' '))));
            int k = Integer.parseInt(line.substring(line.indexOf(' ') + 1));

            BigInteger num2 = num;
            int digits = 0;
            while(num2.compareTo(new BigInteger("0")) != 0)
            {
                digits++;
                num2 = num2.divide(new BigInteger("10"));
            }
            num2 = num;
            Node arr[] = new Node[digits];
            for(int i = digits - 1; i >= 0 ; i--)
            {
                arr[i] = new Node();
                arr[i].x = (num2.remainder(new BigInteger("10")).intValue());
                num2 = num2.divide(new BigInteger("10"));
                arr[i].index = i;
            }
            //printArray(arr);
		    chdiger ob = new chdiger(); 
		    ob.sort(arr, 0, digits-1); 

		    //System.out.println("sorted array"); 
            //printArray(arr);

            BigInteger new_no = new BigInteger("0");

            if(arr[0].x > k)
            {
                for(int i = 0 ; i < digits ; i++)
                {
                    new_no = new_no.multiply(new BigInteger("10")).add(new BigInteger((k + "")));
                }
            }
            else 
            {
                int i = 1;
                int count = 0;
                
                new_no = new BigInteger("" + arr[0].x);
                int pos = 0;
                while(i < digits)
                {
                    if ((arr[i].x < k) && (arr[i].index > arr[pos].index))
                    {
                        new_no = (new_no.multiply(new BigInteger("10"))).add(new BigInteger((arr[i].x + ""))); 
                        count ++;
                        pos = i;
                    }
                    i ++ ;
                }
                //System.out.println(k + " ");
                for(; count < digits - 1 ; count++)
                {
                    new_no = new_no.multiply(new BigInteger("10")).add(new BigInteger((k + "")));
                }
            }
            System.out.println(new_no + " ");

        }
	} 
} 
/*This code is contributed by Rajat Mishra */
