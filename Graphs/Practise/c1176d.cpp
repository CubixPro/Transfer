#include<bits/stdc++.h>
#define MAX_SIZE 2750132

using namespace std;
vector<long long >isprime(MAX_SIZE , true); 
vector<long long >prime; 
vector<long long >SPF(MAX_SIZE); 
int main(){
    int n;
    scanf("%d", &n);
    isprime[0] = isprime[1] = false ; 
  
    // Fill rest of the entries 
    for (long long int i=2; i<MAX_SIZE ; i++) 
    { 
        // If isPrime[i] == True then i is 
        // prime number 
        if (isprime[i]) 
        { 
            // put i into prime[] vector 
            prime.push_back(i); 
  
            // A prime number is its own smallest 
            // prime factor 
            SPF[i] = i; 
        } 
  
        // Remove all multiples of  i*prime[j] which are 
        // not prime by making isPrime[i*prime[j]] = false 
        // and put smallest prime factor of i*Prime[j] as prime[j] 
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ] 
        // so smallest prime factor of '10' is '2' that is prime[j] ] 
        // this loop run only one time for number which are not prime 
        for (long long int j=0; 
             j < (int)prime.size() && 
              i*prime[j] < MAX_SIZE && prime[j] <= SPF[i]; 
             j++) 
        { 
            isprime[i*prime[j]]=false; 
  
            // put smallest prime factor of i*prime[j] 
            SPF[i*prime[j]] = prime[j] ; 
        } 
    } 
  
    
     
    multiset<int> primevals;
    multiset<int> composites;

    int final_arr[2 * n];
    for(int k = 0 ; k < 2*n ; k ++){
        scanf("%d", &final_arr[k]);
        if(isprime[final_arr[k]])
            primevals.insert(final_arr[k]);
        else
            composites.insert(final_arr[k]);
    }

    multiset<int> :: reverse_iterator it = composites.rbegin();
    while(it != composites.rend()){
        for(int k = 2 ; k <= sqrt(*it) ; k++ ){
            //cout << k;
            if(*it%k == 0){
                int val = *it/k;
                if(isprime[val] && primevals.find(val) != primevals.end())
                {
                    primevals.erase(primevals.equal_range(val).first);
                    break;
                }
                else if(composites.find(val) != composites.end() )
                {
                    composites.erase(composites.equal_range(val).first);
                    break;
                }
                
            }
        }
        it++;
    }
    multiset<int> :: iterator it1 = primevals.begin();
    while(it1 != primevals.end()){
        if(primevals.find(prime[*it1 - 1]) != primevals.end())
        {
            primevals.erase(primevals.equal_range(prime[*it1 - 1]).first);
        }
        it1++;
    }

      multiset<int> :: iterator it2 = primevals.begin();
      while(it2 != primevals.end()){
          cout << *it2 << ' ';
          it2++;
      }
      multiset<int> :: iterator it3 = composites.begin();
      while(it3 != composites.end()){
          cout << *it3 << ' ';
          it3++;
      }
}