#include <bits/stdc++.h>
#include <cmath>
#define lld long long int
#define llf long long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define cases  \
    lld T = 0; \
    cin >> T;  \
    while (T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAXN 2000


using namespace std;

struct comparator{
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
        if(a.first != b.first)
            return a.first < b.first;
        else{
            return a.second.first > b.second.first;
        }
    }
};


int main(){
    cases{

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,  comparator> pq;
        
        int n;
        cin >> n;
        int count = 1;
        int arr[n];
        pq.push({n, {0, n - 1}});
        while(!pq.empty()){
            pair<int, pair<int, int>> node = pq.top();
            pq.pop();
            int size = node.first;
            if(size != 0){
            arr[node.second.first + (size - 1)/2] = count;
            count++;
            if(size == 1){
                continue;
            }
            if(size%2 == 0){
                pq.push({(size - 1)/2, {node.second.first, node.second.first + (size - 1)/2 - 1}});
                pq.push({(size - 1)/2 + 1, {node.second.second - (size - 1)/2, node.second.second}});

            }
            else {
                pq.push({(size - 1)/2, {node.second.first, node.second.first + (size - 1)/2 - 1}});
                pq.push({(size - 1)/2, {node.second.second - (size - 1)/2 + 1, node.second.second}});

            }
            }
            
        }
        for(int i = 0 ; i < n ; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    
}