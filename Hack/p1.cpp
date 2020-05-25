#include<bits/stdc++.h>
using namespace std;

int main(){
    long double a, b, ans = 0;
    cin >> a >> b;
    long double lo  = 0, hi = 1e5;
    bool state = false;
    while(hi - lo >= 1e-8)
{
    long double mid = (lo + hi)/2;
    if(mid * b < a)
        lo = mid;
        else
            hi = mid, state = true;
        
    
}
if(state){
    cout << fixed << setprecision(8) << hi << endl;
}
else{
    cout << -1;
}
}