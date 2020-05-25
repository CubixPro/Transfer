#include<bits/stdc++.h>
#define lld long long int
#define llf long long double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases lld T=0;cin>>T;while(T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;
int main()
{
 fast;
 //cases
 {
     int n;
        cin>>n;
        int x[n],c[n];
       for(int i = 0 ; i < n ; i++)
            cin>>x[i]>>c[i];
        
        //lld suf[n],pre[n];
        lld add[100005];
        memset(add, 0, sizeof(add));
        lld sub[100005];
        memset(sub, 0, sizeof(sub));
        lld dist[100005];
        memset(dist, 0, sizeof(dist));
        for(int i = 0 ; i < n ; i++){
            dist[x[i]] = c[i];
        } 
        
        for(int i = 0 ; i < 100004; i++){
            sub[i + 1] = sub[i] + dist[i];
        }
        for(int j = 100003 ; j >= 0 ; j--){
            add[j] = add[j + 1] + dist[j];
        }
        int total = 0;
        for(lld i = 0 ; i < 100005 ; i++){
            total += dist[i]*i;
        }
        /*for(int i = 0 ; i < 10 ; i ++){
            cout << dist[i] << ' ' << add[i] << ' ' << sub[i] << '\n';
        }*/
        int max = total;
        int pos = -1;
        for(int i = 1 ; i < 100005 ; i++){
            total = total - add[i] + sub[i];
            if(total < max){
                max = total;
                pos = i;
            }
        }
        cout << max  << '\n';

 }
}