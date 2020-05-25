#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
double abso(double d){
    return (d > 0)?d:(-d);
}
int main()
{
 fast;
 cases
 {
     int n;
     cin >> n;
     double arr_x[n];
     double arr_y[n];
     for(int i = 0 ; i < n ; i++){
         cin >> arr_x[i];
     }
     for(int i = 0 ; i < n ; i++){
         cin >> arr_y[i];
     }
    sort(arr_x, arr_x + n);
    sort(arr_y, arr_y + n);
    int sum = 1;
    bool check = true;
    double ori_m = (arr_y[1] - arr_y[0] + 0.0)/(arr_x[1] - arr_x[0]);
    for(int i = 2 ; i < n ; i++){
        double new_m = (arr_y[i] - arr_y[i - 1] + 0.0)/(arr_x[i] - arr_x[i - 1]);
        if(abso(ori_m == new_m)  ){

            continue;
        }
        else{
            //sum = 0;
            sum = 0;
            break;
        }
    }
    sort(arr_y, arr_y + n, greater<double>());
    int sum_2 = 1;
      ori_m = (arr_y[1] - arr_y[0] + 0.0)/(arr_x[1] - arr_x[0]);
    for(int i = 2 ; i < n ; i++){
        double new_m = (arr_y[i] - arr_y[i - 1] + 0.0)/(arr_x[i] - arr_x[i - 1]);
        if(abso(ori_m == new_m)  ){

            continue;
        }
        else{
            //sum = 0;
            sum_2 = 0;
            break;
        }
    }
    
    cout << (sum + sum_2) << '\n';


 }
}
 