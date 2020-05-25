#include<bits/stdc++.h>


using namespace std;
typedef long long int lld;

int main(){
    int testcases;
    cin >> testcases;
    while(testcases-- != 0){
       int a, b;
       cin >> a >> b;
       string str;
       int m[b];
       cin >> str;
       for(int i = 0 ; i < b ; i++){
           cin >> m[i];
       }
       int count[a];
       memset(count, 0, sizeof(int)*a);
       for(int  i = 0 ; i < b ; i++){
           count[m[i] - 1]++;
       }
       for(int i = a - 2 ; i >= 0 ; i--){
           count[i] = count[i] + count[i + 1] + 0;
       }
       int alphabets[26];
       memset(alphabets, 0, sizeof(int) * 26);
       for(int i = 0 ; i < a ; i++){
           count[i]++;
           alphabets[str[i] - 97] += count[i];
       }
       
       for(int i = 0 ; i < 26 ; i+=1){
           cout << (alphabets[i] ) << ' ';
       }
       cout << '\n';
    }
}
