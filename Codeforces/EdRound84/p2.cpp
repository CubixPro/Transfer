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
       int* prince[n];
       int sizes[n];
        for(int i = 0 ; i < n ; i++){
            int size;
            cin >> size;
            sizes[i] = size;
            prince[i] = (int*)malloc(sizeof(int) * size);
            for(int j = 0 ; j < size ; j++){
                int val;
                cin >> val;
                val--;
                prince[i][j] = val;
            }
        }
        bool check = true;
        bool kingdom[n];
        int index;
        memset(kingdom, true, sizeof(kingdom));
        for(int i = 0 ; i < n ; i++){
            bool found = false;
            for(int j = 0 ; j <  sizes[i] ; j++){
                if(kingdom[prince[i][j]]){
                    kingdom[prince[i][j]] = false;
                    found = true;
                    break;
                }
                else{
                    continue;
                }
            }
            if(found == false){
                index = i;
            }
        }
        int king = -1;
        for(int i = 0 ; i < n ; i ++){
            if(kingdom[i] == true){
                king = i;
                break;
            }
        }

        if(king == -1)
        {
            cout << "OPTIMAL\n";
        }
        else{
            cout << "IMPROVE\n";
        cout << (index + 1) << ' ' << (king + 1) << '\n';
        }
    }
}