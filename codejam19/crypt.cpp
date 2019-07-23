// C++ program to find prime factorization of a 
// number n in O(Log n) time with precomputation 
// allowed. 
#include "bits/stdc++.h" 
using namespace std; 

#define MAXN 10000000 


// stores smallest prime factor for every number 
unsigned long int spf[MAXN]; 
//#include <bits/stdc++.h> 
 int binary_search(unsigned long int *arr, int size, unsigned long int val)
{
    int l = 0;
    //printf("%d ", l);
    int u = size - 1;
    while (l <= u)
    {
        int mid = (l + u) / 2;
        //printf("%d ", mid);
        if (val > arr[mid])
        {
            l = mid + 1;
        }
        else if (val == arr[mid])
        {
            return mid;
        }
        else if (val < arr[mid])
        {
            u = mid - 1;
        }
        
    }
    return -1;
} 
// Binary predicate 
 int compare(const void* ap, const void* bp) 
{ 
    // Typecasting 
    const unsigned long int* a = (long unsigned int*)ap; 
    const unsigned long int* b = (long unsigned int*)bp; 
  
    if (*a < *b) 
        return -1; 
    else if (*a > *b) 
        return 1; 
    else
        return 0; 
} 
// Calculating SPF (Smallest Prime Factor) for every 
// number till MAXN. 
// Time Complexity : O(nloglogn) 
void sieve() 
{ 
	spf[1] = 1; 
	for (unsigned long int i=2; i<MAXN; i++) 

		// marking smallest prime factor for every 
		// number to be itself. 
		spf[i] = i; 

	// separately marking spf for every even 
	// number as 2 
	for (unsigned long int i=4; i<MAXN; i+=2) 
		spf[i] = 2; 

	for (unsigned long int i=3; i*i<MAXN; i++) 
	{ 
		// checking if i is prime 
		if (spf[i] == i) 
		{ 
			// marking SPF for all numbers divisible by i 
			for (unsigned long int j=i*i; j<MAXN; j+=i) 

				// marking spf[j] if it is not 
				// previously marked 
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 

// A O(log n) function returning primefactorization 
// by dividing by smallest prime factor at every step 
vector<unsigned long int> getFactorization(unsigned long int x) 
{ 
	vector<unsigned long int> ret; 
	while (x != 1) 
	{ 
		ret.push_back(spf[x]); 
		x = x / spf[x]; 
	} 
	return ret; 
} 

// driver program for above function 
/*
int main(int argc, char const *argv[]) 
{ 
	// precalculating Smallest Prime Factor 
    long int x;
    scanf("%ld", &x);
	//cout << "prime factorization for " << x << " : "; 

	// calling getFactorization function 
	vector <long int> p = getFactorization(x); 

	for (int i=0; i<p.size(); i++) 
        printf("%ld ", p[i]);
	//cout << endl; 
	return 0; 
} 
*/
void show(unsigned long int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}
int main()
{
    
	sieve(); 
    int testcases;
    scanf("%d", &testcases);
    for(int j = 1; j <= testcases; j++)
    {
        int max;
        int num;
        scanf("%d %d", &max, &num);
        unsigned long int arr_products[num];
        unsigned long int prime[num + 1];
        unsigned long int orig[num + 1];
        scanf("%lu", &arr_products[0]);
        vector <unsigned long int> p = getFactorization(arr_products[0]); 
        prime[0] = p[0];
        prime[1] = p[1];
        orig[0] = p[0];
        orig[1] = p[1];
        for(int i = 1; i < num ; i++)
        {
            scanf("%lu", &arr_products[i]);
            if(arr_products[i]%prime[i] == 0)
            {
            prime[i + 1] = arr_products[i]/prime[i];
            orig[i + 1] = arr_products[i]/orig[i];
            }
            else if(arr_products[i]%prime[0] == 0)
            {
                prime[2] = arr_products[1]/prime[0];
                orig[2] = arr_products[1]/prime[0];
            }
        }
        sort(prime, prime + num + 1);
        unique(prime, prime + num + 1);
        //show(prime, num + 1);
        //show(orig, num + 1);
        string encrypted = "";
        for(int k = 0; k < num + 1 ; k++)
        {
            unsigned long int val = orig[k];
            //unsigned long int *p1 = (unsigned long int*)std::bsearch(&val, prime, 26, sizeof(prime[0]), compare); 
            int index = binary_search(prime, 26, val);
            encrypted += (char)(65 + index); 

        }
        printf("Case #%d: %s\n", j, encrypted.c_str());
    }
    return 0;
}