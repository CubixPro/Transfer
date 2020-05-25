#include<bits/stdc++.h>


using namespace std;
fstream f;

const int n = 1000000005;
bool prime[n + 1]; 
/*bool prime(int n){
    for(int j = 2 ; j <= sqrt(n) ; j++){
        if(n%j == 0){
            return false;
        }
    }
    return true;
}*/
void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    memset(prime, true, sizeof(prime)); 
  
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
  
    // Print all prime numbers 
    int count = 0;
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
       {
           count++;
          //f << p << ", "; 
       }
    cout << count << '\n';
}
int main(){
    //int count = 0;
    vector<int> primes;
   // f.open("primes.txt", ios::app);
    SieveOfEratosthenes(n);
    /*for(int i = 2 ; i < n ; i++){
        if(prime(i)){
            primes.push_back(i);
            count++;
            f << i << ", ";
        }
        
    }*/
    //f.close();
    //cout << count;
}