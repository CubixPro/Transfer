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
        cin >> n;
        int arr[n];
        bool check = false;
        unordered_map<int, int> locate;
        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
            if(locate.find(arr[i]) == locate.end()){
            locate.insert({arr[i], i});
            }
            else{
                if((i - locate[arr[i]] ) > 1){
                    check = true;
                    //return;
                    //break;
                }
            }
        }
        if(check){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << '\n';
    }
}