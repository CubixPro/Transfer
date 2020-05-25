#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;

void build(int seg_tree[], int arr[], int start, int end, int node){
    if(start == end){
        seg_tree[node] = arr[start];
        //cout << node << '\n';
    }
    else{
        int mid = (start + end)/2;
        build(seg_tree, arr, start, mid, 2 * node);
        build(seg_tree, arr, mid + 1, end, 2 * node + 1);
        seg_tree[node] = (seg_tree[2 * node] <= seg_tree[2 * node + 1])?seg_tree[2 * node]:seg_tree[2 * node + 1];
    }
}

void update(int seg_tree[], int arr[], int start, int end, int node, int index, int val)
{
    if(start == end){
        arr[index] = val;
        seg_tree[start] = val;
    }
    else {
        int mid = (start + end)/2;
        if(index <= mid && start <= index) {
            update(seg_tree, arr, start, mid, 2 * node, index, val);
        }
        else {
            update(seg_tree, arr, mid  + 1, end, 2 * node + 1, index, val);
        }

         seg_tree[node] = (seg_tree[2 * node] <= seg_tree[2 * node + 1])?seg_tree[2 * node]:seg_tree[2 * node + 1];

    }
}


int query(int seg_tree[], int arr[], int start, int end, int l, int r, int node){
    if(r < start || l >end){
        return INT32_MAX;
    }
    else if(l <= start && r >= end){
        return seg_tree[node];

    }
    else{
        int mid = (start  + end)/2;
        int val1 = query(seg_tree, arr, start, mid, l, r, 2 * node);
        int val2 = query(seg_tree, arr, mid + 1, end, l, r, 2 * node + 1);
        return min(val1, val2);
    }
}
int main(){
   // cases
    {
        int n, m;
        cin >> n >> m;
        int arr[n];
        for(int i = 0 ; i < n  ; i++){
            cin >> arr[i];
        }    
        int seg_tree[4 * n + 1];
        build(seg_tree, arr, 0, n - 1, 1);
        
        for(int i = 0 ; i < m ; i++){
            string s;
            int l, r;
            cin >> s >> l >> r;
            if(s.compare("q") == 0){
                cout << query(seg_tree, arr, 0, n - 1, l - 1, r - 1, 1) << '\n';
            }
            else{
                update(seg_tree, arr, 0, n - 1, 1, l - 1, r);
            } 
        }
    }
}