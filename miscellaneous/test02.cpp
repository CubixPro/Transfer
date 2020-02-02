//#include <iostream>

#include "bits/stdc++.h"

//# include <stdlib.h>

//#include <vector>

//#include <algorithm>

using namespace std;

 

#define MAXN 10000000

 

 

// stores smallest prime factor for every number

int spf[MAXN];

//#include <bits/stdc++.h>

 

// Binary predicate

int compare(const void* ap, const void* bp)

{

              // Typecasting

              const long int* a = (long int*)ap;

              const long int* b = (long int*)bp;

 

              if (*a < *b)

                           return -1;

              else if (*a > * b)

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

              for (long int i = 2; i < MAXN; i++)

 

                           // marking smallest prime factor for every

                           // number to be itself.

                           spf[i] = i;

 

              // separately marking spf for every even

              // number as 2

              for (long int i = 4; i < MAXN; i += 2)

                           spf[i] = 2;

 

              for (long int i = 3; i * i < MAXN; i++)

              {

                           // checking if i is prime

                           if (spf[i] == i)

                           {

                                         // marking SPF for all numbers divisible by i

                                         for (long int j = i * i; j < MAXN; j += i)

 

                                                       // marking spf[j] if it is not

                                                       // previously marked

                                                       if (spf[j] == j)

                                                                    spf[j] = i;

                           }

              }

}

 

// A O(log n) function returning primefactorization

// by dividing by smallest prime factor at every step

vector<long int> getFactorization(long int x)

{

              vector<long int> ret;

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

void show(long int* arr, int n)

{

              for (int i = 0; i < n; i++)

              {

                           printf("%ld ", arr[i]);

              }

              printf("\n");

}

int main()

{

 

              sieve();

              int testcases = 1;

              scanf("%d", &testcases);

              for (int i = 1; i <= testcases; i++)

              {

                           //const int max = 10000;

                           //const int num = 25;

                           int max;

                           int num;

                           scanf("%d %d", &max, &num);

                           //long int arr_products[num];

                           long int* arr_products = new long int[num];

                           //long int prime[num + 1];

                           long int* prime = new long int[num + 1];

                           //long int orig[num + 1];

                           long int* orig = new long int[num + 1];

                           scanf("%ld", &arr_products[0]);

                           vector <long int> p = getFactorization(arr_products[0]);

                           prime[0] = p[0];

                           prime[1] = p[1];

                           orig[0] = p[0];

                           orig[1] = p[1];

                           for (int j = 1; j < num; j++)

                           {

                                         scanf("%ld", &arr_products[j]);

                                         prime[j + 1] = arr_products[j] / prime[j];

                                         orig[j + 1] = arr_products[j] / orig[j];

                           }

                           sort(prime, prime + num + 1);

                           unique(prime, prime + num + 1);

                           //show(prime, num + 1);

                           //show(orig, num + 1);

                           string encrypted = "";

                           for(int k = 0; k < num + 1 ; k++)

                           {

                                         long int val = orig[k];

                                         long int *p1 = (long int*)std::bsearch(&val, prime, 26, sizeof(long int), compare);

                                         encrypted += (char)(65 + (p1 - prime));

 

                           }

                           printf("Case #%d: %s\n", i, encrypted.c_str());

 

                           delete[] arr_products;

                           delete[] prime;

                           delete[] orig;

              }

}