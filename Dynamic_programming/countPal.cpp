#include<algorithm>
#include<cstring>
#include<iostream>
#include<unordered_map>
using namespace  std;

unordered_map<string, int> umap;
bool prime[10001]; 
void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    //memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}
int isPalindrome(string str, int length)
{
    //cout << str;
    if (str.length() == 1)
    {
     //   printf("if 0 \n");
        return length+1;
    }
    else if(str.length() == 2)
    {
        if(str[0] == str[1])
        {
      //      printf("if 1  %d \n", length);
            return length+2;
        }
        else
        {
       //     printf("if 1.2 \n");
            return 0;
        }
        
    }
    else if(umap.find(str) != umap.end())
    {
        return umap.at(str);
    }
    else if(str[0] == str[str.length() - 1])
    {
        //printf("if 2  %d  \n", length );
        umap.insert({str, isPalindrome(str.substr(1, str.length() - 2), length + 2)});
        return umap.at(str); 
    }
    else  
    {
        //printf("if 3\n");
        //return max(isPalindrome(str.substr(0, str.length() - 2), 0), isPalindrome(str.substr(1, str.length() - 1), 0));
        int length1 =  isPalindrome(str.substr(0, str.length() - 1), 0);
        int length2 =  isPalindrome(str.substr(1, str.length() ), 0); 
        umap.insert({str, max(length1, length2)});
        return umap.at(str);
    }
}
bool isPrime(int number)
{
    if (number == 1)
        return false ;
    for(int i = 2 ; i <= number/2 ; i++)
    {
        if(number % i == 0)
            return false;

    }
    return true;
}

int main()
{
    int testcases;
    for(int i = 0 ; i < 10001 ; i ++)
    {
        prime[i] = true ;
    }
    SieveOfEratosthenes(10001);
    scanf("%d", &testcases);
    for(int k = 1 ; k <= testcases ; k++)
    {
        string str ;
        cin >> str ;
        int large = isPalindrome(str, 0);
        //printf("%d\n", large);
        if(prime[large] == true)
            printf("PRIME\n");
        else
        {
            printf("NOT PRIME\n");
        }
        
    }
}
