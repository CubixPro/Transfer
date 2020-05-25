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
    cases{
        int n;
        string num;
        cin >> n;
        cin >> num;
        string fnum1 = "";
        string fnum2 = "";
        bool check = true ; //equal
        for(int i = 0 ; i <  n ; i++){
            if(check){
                if(num[i] == '2'){
                    fnum1 += "1";
                    fnum2 += "1";
                }
                else if(num[i] == '0'){
                    fnum1 += "0";
                    fnum2 += "0";
                }
                else{
                    fnum1 += '1';
                    fnum2 += '0';
                    check = false;
                }
            }
            else {
                 if(num[i] == '2'){
                    fnum1 += "0";
                    fnum2 += "2";
                }
                else if(num[i] == '0'){
                    fnum1 += "0";
                    fnum2 += "0";
                }
                else{
                    fnum1 += "0";
                    fnum2 += "1";
                    check = false;
                }
            }
        }
        cout << fnum1 << '\n' << fnum2 << '\n';
    }
}