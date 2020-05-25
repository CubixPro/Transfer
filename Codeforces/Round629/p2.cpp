#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;
const int MAX_CHAR = 26; 
const int MAX_FACT = 20; 
lld fact[MAX_FACT]; 
  
// utility for calculating factorials 
void precomputeFactorials() 
{ 
    fact[0] = 1; 
    for (int i = 1; i < MAX_FACT; i++) 
        fact[i] = fact[i - 1] * i; 
} 
  
void nPermute123(string str, long int n) 
{ 
    // Sort the string in lexicographically 
    // ascending order 
    sort(str.begin(), str.end()); 
  
    // Keep iterating until 
    // we reach nth position 
    long int i = 1; 
    do { 
        // check for nth iteration 
        if (i == n) 
            break; 
  
        i++; 
    } while (next_permutation(str.begin(), str.end())); 
  
    // print string after nth iteration 
    cout << str << "\n"; 
}
void nPermute(string str, int n) 
{ 
	precomputeFactorials(); 

	// length of given string 
	int len = str.length(); 

	// Count frequencies of all 
	// characters 
	int freq[MAX_CHAR] = { 0 }; 
	for (int i = 0; i < len; i++) 
		freq[str[i] - 'a']++; 

	// out string for output string 
	char out[MAX_CHAR]; 

	// iterate till sum equals n 
	int sum = 0; 
	int k = 0; 

	// We update both n and sum in this 
	// loop. 
	while (sum != n) { 

		sum = 0; 
		// check for characters present in freq[] 
		for (int i = 0; i < MAX_CHAR; i++) { 
			if (freq[i] == 0) 
				continue; 

			// Remove character 
			freq[i]--; 

			// calculate sum after fixing 
			// a particuar char 
			int xsum = fact[len - 1 - k]; 
			for (int j = 0; j < MAX_CHAR; j++) 
				xsum /= fact[freq[j]]; 
			sum += xsum; 

			// if sum > n fix that char as 
			// present char and update sum 
			// and required nth after fixing 
			// char at that position 
			if (sum >= n) { 
				out[k++] = i + 'a'; 
				n -= (sum - xsum); 
				break; 
			} 

			// if sum < n, add character back 
			if (sum < n) 
				freq[i]++; 
		} 
	} 

	// if sum == n means this char will provide its 
	// greatest permutation as nth permutation 
	for (int i=MAX_CHAR-1; k < len && i >= 0; i--) 
		if (freq[i]) { 
			out[k++] = i + 'a'; 
			freq[i++]--; 
		} 

	// append string termination 
	// character and print result 
	out[k] = '\0'; 
	cout << out << '\n'; 
} 

int main(){
    cases{
        int n, k;
        cin >> n >> k;
    string str = "";
    for(int i = 0 ; i < n  - 2; i++){
str = str + "a";
    } 
    str = str + "bb";
        nPermute(str, k);
    }
}