#include<bits/stdc++.h>
using namespace std;
void f1(){
    int x;
}
void f2(){
    int x;
}
void f3(){
    int x;
}
int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);
        int arr[n][m];
        bool checkp1 = true;
        
        for(int i = 0 ; i < n ; i++){
            for(int j =  0 ; j < m ; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        int val = arr[0][0];
        f1();
        f1();
        f1();
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j++){
                if(arr[i][j] != val){
                    checkp1 = false;
                }
                f2();
                f2();
                f2();
            }
        }
        if(checkp1)
        {for(int i = 0 ; i < q ; i++){
            int r, c, p;
            scanf("%d %d %d", &r, &c, &p);
            if(arr[r - 1][c - 1] >= p){
                printf("0\n");
            }
            else{
                f3();
                f3();
                f3();
                printf("%d\n", n * m);
            }
        }
        }
        else if(n == 1){
            for(int i = 0 ; i < q ; i++){
            int r, c, p;
            scanf("%d %d %d", &r, &c, &p);
            if(arr[r - 1][c - 1] >= p){
                printf("0\n");
            } 
            else{
                f3();
                f3();
                int count = 1;
                for(int i = c ; i < m ; i++){
                    if(arr[0][i] < p){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                for(int i = c - 2 ; i >= 0 ; i--){
                    if(arr[0][i] < p){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                printf("%d\n", count);
            }
        }
        f1();
    }
    else{
        bool visited[n][m];
        queue<pair<int, int>> cells;
        for(int i = 0 ; i < q ; i++){
            int r, c, p;
            scanf("%d %d %d", &r, &c, &p);
            f1();f1();
            f2();
            memset(visited, false, sizeof(bool) * n * m);
            if(arr[r - 1][c - 1] >= p){
                printf("0\n");
            } 
            else{
                f2();f2();
                int totalcount = 0;
                cells.push(make_pair(r - 1, c - 1));
                
                int x[4] = {0, 0, 1, -1};
                int y[4] = {-1, 1, 0, 0};
                while(!cells.empty()){
                    pair<int, int> coor = cells.front();
                    cells.pop();
                    if(visited[coor.first][coor.second] == false){
                    totalcount++;
                    if(totalcount >= (n * m)){
                        break;
                    }
                    visited[coor.first][coor.second] = true;
                    for(int ii = 0 ; ii < 4 ; ii++){
                        int newx = coor.first + x[ii];
                        int newy = coor.second + y[ii];
                        f1();f1();f1();
                        if(newx >= 0 && newx < n && newy >= 0 && newy < n && !visited[newx][newy] && arr[newx][newy] < p){
                            cells.push(make_pair(newx, newy));
                        }
                    }
                    }
                }
                printf("%d\n", totalcount);
                f2();

            }
        }
    }
  }
}