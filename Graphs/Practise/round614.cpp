#include<bits/stdc++.h>
#define  p pair<int, int>
#define   mp(x,y) make_pair(x,y)
using namespace std;


/*int main(){
    int n, m;
    set<pair<int, int>> vals;
    scanf("%d %d", &n, &m);
    int count = 0;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        pair<int, int> newp = (make_pair(x, y));
        if(vals.find(newp) == vals.end()){
            if(x < 2 && y < n){
                p np1 = mp(x + 1, y + 1);
                if(vals.find(np1) != vals.end())
                {
                    count++;
                    //continue;
                }

            } 
            if(x < 2 && y > 0){
                p np2 = mp(x + 1, y - 1);
                if(vals.find(np2) != vals.end())
                {
                    count++;
                    //continue;
                }
            }
            if(x > 1 && y < n){
                p np2 = mp(x - 1, y + 1);
                if(vals.find(np2) != vals.end())
                {
                    count++;
                    //continue;
                }
            }
            if(x > 1 && y > 1){
                p np2 = mp(x - 1, y - 1);
                if(vals.find(np2) != vals.end())
                {
                    count++;
                    //continue;
                }
            }
            if(x > 1 ){
                p np2 = mp(x - 1, y );
                if(vals.find(np2) != vals.end())
                {
                    count++;
                    //continue;
                }
            }
            

            if(x < 2 ){
                p np2 = mp(x + 1, y );
                if(vals.find(np2) != vals.end())
                {
                    count++;
                    //continue;
                }
            }
 
            vals.insert(newp);

        }
        else{
             if(x < 2 && y < n){
                p np1 = mp(x + 1, y + 1);
                if(vals.find(np1) != vals.end())
                {
                    ////cout << x+1 << y+1;
                    count--;
                    //continue;
                }

            } 
            if(x < 2 && y > 0){
                p np2 = mp(x + 1, y - 1);
                if(vals.find(np2) != vals.end())
                {
                    count--;
                    //cout << x+1 << y-1;
//continue;
                }
            }
            if(x > 1 && y < n){
                p np2 = mp(x - 1, y + 1);
                if(vals.find(np2) != vals.end())
                {
                    count--;
                    //continue;
                    //cout << x-1 << y+1;

                }
            }
            if(x > 1 && y > 1){
                p np2 = mp(x - 1, y - 1);
                if(vals.find(np2) != vals.end())
                {
                    //cout << x-1 << y-1;
count--;
                    //continue;
                }
            }
            if(x > 1 ){
                p np2 = mp(x - 1, y );
                if(vals.find(np2) != vals.end())
                {
                    count--;//cout << x+1 << y;

                    //continue;
                }
            }
            

            if(x < 2 ){
                p np2 = mp(x + 1, y );
                if(vals.find(np2) != vals.end())
                {
                    count--;//cout << x-1 << y;

                    //continue;
                }
            }
 

            vals.erase(newp);



        }
        if(count == 0 || vals.empty())
        {
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
        

    }
}*/

/*int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int n, s, k;
        scanf("%d %d %d", &n, &s, &k);
        set<int> closed;
        int min_floors = s;
        int dist = 0;
        while(k-- != 0){
            int x;
            scanf("%d", &x);
            closed.insert(x - s);
            
        }
        if(closed.find(0) == closed.end()){
            printf("%d\n", 0);
            continue;
        }
        else{
            for(int i = 1 ; i <= (n ) ; i++){
                if(((i + s) <= n && (closed.find(i) == closed.end())) || ((s - i) > 0 && closed.find(-i) == closed.end())){
                    printf("%d\n", i);
                    break;
                }
            }
        }

    }
}*/

int main(){
    int val ;
    scanf("%d", &val);
    double sum = 0;
    for(int i  = 1 ; i <= val  ; i ++){
        sum+= 1.0/i;
    }
    printf("%0.9lf", sum);
}