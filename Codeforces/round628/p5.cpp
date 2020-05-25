#include<bits/stdc++.h>
using namespace std;


void compute(unsigned long long int S,  
            unsigned long long int X) 
{ 
    
    unsigned long long int A = (S - X)/2; 
    if((S < X) || (S - X)%2 == 1){
        cout << -1 << '\n';
        return;
    }
   unsigned long long int a = 0, b = 0, c = 0; 
 unsigned long long int p = 1; 
    // Traverse through all bits 
    for (unsigned long long int i=0; i < log(S)/log(2)  + 1 ; i++) 
    { 
        
       unsigned long long int  Xi = (X & (p << i)); 
       unsigned long long int Ai = (A & (p << i)); 
        if (Xi == 0 && Ai == 0) 
        { 
            // Let us leave bits as 0. 
        } 
        else if (Xi == 0 && Ai > 0) 
        { 
            a = ((p << i) | a);  
            b = ((p << i) | b);  
        } 
        else if (Xi > 0 && Ai == 0) 
        { 
            a = ((p << i) | a);  
  
            // We leave i-th bit of b as 0. 
        } 
        else // (Xi == 1 && Ai == 1) 
        { 
            a = ((p << i) | a);
            b = ((p << i) | b);
            c = ((p << i) | c);
            //return; 
        } 
        //cout << a << '\n';
    } 
    /*if((a < 0)  || (b < 0) || (c < 0) || (a + b + c) != S){
        cout << -1 << '\n';
    }*/
     if(c != 0){
        cout << '3' << '\n' << a <<  ' ' << b << ' ' << c << '\n';
    }
    else if(b != 0 && a!= 0){
        cout << '2' << '\n' << a << ' ' << b << '\n';
    }
    else if(a != 0){
        cout << "1\n" << a << '\n';
    }
    else if(b != 0){
        cout << "1\n" << b <<  '\n';
    }
    else{
        cout << "0\n";
    }
} 

 int main(){
     long long int x, y;
     cin >> x >> y;
     
     compute(y, x);
 } 