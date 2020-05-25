// C++ program to check if each element of 
// the given array is a product of exactly 
// K prime factors 
#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAX 1000000000 
using namespace std; 

// initialise the global sieve array 
short Sieve[MAX] = { 0 }; 

// Function to generate Sieve 
void constructSieve() 
{ 
	// NOTE: k value is necessarily more than 1 
	// hence, 0, 1 and any prime number cannot be 
	// represented as product of 
	// two or more prime numbers 

	for (int i = 2; i <= MAX; i++) { 
		if (Sieve[i] == 0) { 
			for (int j = 2 * i; j <= MAX; j += i) { 
				int temp = j; 
				while (temp > 1 && temp % i == 0) { 
					Sieve[j]++; 
					temp = temp / i; 
				} 
			} 
		} 
	} 
} 

// Function to check if each number of array 
// satisfies the given condition 
void checkElements(int A[], int n, int k) 
{ 
	for (int i = 0; i < n; i++) { 
		if (Sieve[A[i]] == k) { 
			cout << "YES\n"; 
		} 
		else { 
			cout << "NO\n"; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	// first construct the sieve 
	constructSieve(); 
    //cout << "done" << '\n';
    cases{
        int n,k;
        cin >> n >> k;
        if(n == 1){
            cout << 0 << '\n';
        }
        else if(Sieve[n] == 0 && k == 1){
            cout << 1 << '\n';
        }
        else if(Sieve[n] >= k){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    } 

	return 0; 
} 
