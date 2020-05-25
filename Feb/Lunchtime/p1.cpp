#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;
int ff(){
    return 0;
}
int main(){

ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcases;
    cin >> testcases;
    while(testcases-- != 0){
       int n, k;
       cin >> n >> k;
     //   string str;
      //  cin >> str;
int count = 0;;
       char s[n];
        int i = 0;
        for(int i = 0 ; i < n ; i++){
            string ch;
            cin >> ch;
            s[i] = ch[0];
        }
     ff(); 
       
      for(int i=n-1;i>=n-k;i--)
 {
 if(s[i]=='H')
 {
 for(int j=0;j<=i-1;j++)
 {
     ff();
 if(s[j]=='H')
 s[j]='T';
 else
 s[j]='H';
 }
 }
ff();
 }
 for(int i=0;i<n-k;i++)
 {
 if(s[i]=='H')
 count++;
 } 
 cout << count ;ff();
 
       cout << '\n';
       ff();
    }
}