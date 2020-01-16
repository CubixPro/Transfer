#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int dist[n + 1][n + 1];
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            scanf("%d", &dist[i][j]);
        }
    }
    int queries;
    scanf("%d", &queries);
    int calc[queries];
    int count = 0;
    while(queries-- != 0){
        int x, y, wt;
        scanf("%d %d %d", &x, &y, &wt);
        dist[x][y] = min(dist[x][y], wt);
        dist[y][x] = dist[x][y];
        /*for(int i = 1 ; i <= n ; i++){
            dist[x][i] = min(dist[x][i], dist[x][y] + dist[y][i]);
            dist[i][x] = dist[x][i];
            dist[i][y] = min(dist[i][y], dist[i][x] + dist[x][y]);
            dist[y][i] = dist[i][y];
        }*/
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= n ; j++){
                
            }
        }
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j  = i ; j <= n ; j++){
                sum += dist[i][j];
            }
        }
        calc[count] = sum;
        count++; 
    }
    for(int i = 0 ; i < count ; i++){
        cout << calc[i] << ' ';
    }
}