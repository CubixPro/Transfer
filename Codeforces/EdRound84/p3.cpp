#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
int main(){
   // cases
   {
        int n, m, p;
        cin >> n >> m >> p;
        for(int i = 0 ; i < 2 * p ; i++){
            int x, y;
            cin >> x >> y;
        }
        string path = "";
        string d = "";
        string u = "";
        for(int i = 1 ;i < n ; i++){
            d = d + "D";
            u = u + "U";
        }
        for(int i = 1 ; i <= m/2 ; i++){
            if(i == m/2 && m%2 == 0){
                path += d + "R" + u;
            }
            else{
                path += d + "R" + u + "R";
            }
        }
        if(m%2 == 1){
            path += d ;
        
        for(int i = 1 ; i <= m/2 ; i++){
            if(i == m/2 && m%2 == 0){
                path += u + "L" + d;
            }
            else{
                path += u + "L" + d + "L";
            }
        }
        if(m%2 == 1){
            path += u ;
        }
        }
        else{
            for(int i = 1 ; i <= m/2 ; i++){
            if(i == m/2 && m%2 == 0){
                path += d + "L" + u;
            }
            else{
                path += d + "L" + u + "L";
            }
        }
        }
        cout << path.length() << '\n';
        cout << path << '\n';
    }
}