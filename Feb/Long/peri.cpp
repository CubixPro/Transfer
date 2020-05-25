#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
int main(){
    int testcases;
    cin >> testcases;
    while(testcases-- != 0){
        int n;
        cin >> n;
        lld a[n];
        lld b[n];
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        for(int j = 0 ; j < n ; j++){
            cin >> b[j]; 
        }
        sort(a, a + n);
        sort(b, b + n);
        lld sum  = 0;
        for(int i = 0 ;  i < n ; i++){
            sum += min(a[i], b[i]);
        }
        cout << sum << '\n';
    }
}