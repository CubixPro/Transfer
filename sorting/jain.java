import java.util.*;
class jain
{
    public static void main(String args[])
    {
        int product = 3*5*11*17*7;
        int arr[] = {3*11, 17*7*5, 3*5*7*11, 5};
        Hashtable<Integer, Integer> h = new Hashtable<Integer, Integer>();
        for(int i = 0; i < arr.length; i++)
        {
            h.put(i, arr[i]);
        }
        int count = 0;
        for(int i = 0; i < arr.length; i++)
        {
            int rem = product/arr[i];
            
            {
                if(h.contains(rem))
                    count++;
            }   
            h.remove(i, arr[i]); 
        }
        System.out.println(count);
    }
}