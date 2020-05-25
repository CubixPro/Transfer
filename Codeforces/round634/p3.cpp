#include<bits/stdc++.h>
#include<cmath>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;
int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
 cases
    {
       lld n;
       cin >> n;
       int arr[n];
       for(int i = 0 ; i < n ; i++){
           cin >> arr[i];
       }
       int max = 0;
       int max_val = -1;
       unordered_map<int, int> count;
       for(int i = 0  ; i < n ; i++){
           if(count.find(arr[i]) == count.end()){
               count.insert({arr[i], 1});
           }
           else{
               count[arr[i]]++;
           }
           if(count[arr[i]] > max){
               max = count[arr[i]];
               max_val = arr[i];
           }
       }
        set<int> team1;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] != max_val){
                team1.insert(arr[i]);
            }
        }
        int max_team_size;
        if(team1.size() >= max){
            max_team_size = max;
        }
        else if(team1.size() < max){
            max_team_size = min(team1.size() + 1, max - 1);
        }
        cout << max_team_size << '\n';
    }
}