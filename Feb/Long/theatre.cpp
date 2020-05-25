#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

int main(){
    int testcases;
    scanf("%d", &testcases);
    int total_val = 0;
    while(testcases-- != 0){
        int n;
        scanf("%d", &n);
        if(n == 0){
            cout << -400 << '\n';
            total_val = total_val - 400;
            continue;
        }
        int arr[4][4]; 
        int count = 0;
        memset(arr, 0, sizeof(int)*16);
        int a = 0, b = 0, c = 0, d = 0;
        for(int i = 1; i <= n ; i++){
            pair<char, int> np;
            cin >> np.first >> np.second; 
            arr[np.first - 65][np.second/3 - 1]++;
        }
        vector<pair<int, pair<int, int>>> movies;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                if(arr[i][j] != 0)
                movies.push_back(mp(arr[i][j], mp(i, j)));
            }
        }
        sort(movies.begin(), movies.end(), greater<pair<int, pair<int, int>>>());
        vector<pair<int, pair<int, int>>> :: iterator it = movies.begin();
        bool titles[4];
        bool times[4];
        memset(titles, false, sizeof(titles));
        memset(times, false, sizeof(times));
        vector<int> counts;
        
        while(it != movies.end() && counts.size()!=4){
            if(!titles[(*it).second.first] && !times[(*it).second.second]){
                counts.push_back((*it).first);
                titles[(*it).second.first] = true;
                times[(*it).second.second] = false;
            }
            it++;

        }
        int final_size = 0;
        for(int i = 0 ; i < counts.size() ; i++){
            if(i == 0){
                final_size += 100 * counts[0];
            }
            else if(i == 1){
                final_size += 75 * counts[1];
            }
            else if(i == 2){
                final_size += 50 * counts[2];
            }
            else{
                final_size += 25 * counts[3]; 
            }
        }
        final_size -= 100*(4 - counts.size());
        cout << final_size << '\n';
        total_val+=final_size;
         
    }
    cout << total_val;
}