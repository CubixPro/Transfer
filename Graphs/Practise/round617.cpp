#include<bits/stdc++.h>
#define mp make_pair

using namespace std;
int ceiling(int a, int b){
    if(a%b == 0){
        return a/b;
    }
    else{
        return (a/b + 1);
    }
}

int main(){
    

  int testcases;
  scanf("%d", &testcases);
  while(testcases-- != 0){
      int n;
      cin >> n;
      string rob;
      cin >> rob;
      int min = rob.length() + 1;
      map<pair<int, int>, int> location;
      
      int x, y;
      x = 0;
      y = 0;
      int finalx, finaly;

        location.insert(mp(mp(0, 0), 0));
      for(int i = 0 ; i < rob.length() ; i++){
          char ch = rob[i];
          if(rob[i] == 'L'){
              x = x-1;
          }
          else if(rob[i] == 'R'){
              x = x + 1;
          }
          else if(rob[i] == 'U'){
              y = y + 1;
          }
          else{
              y = y - 1;

          }
          pair<int, int> np = make_pair(x, y);
            if(location.find(np) != location.end()){
                if(min > (i - location[np])){
                    finaly = i + 1;
                    finalx = location[np] + 1;
                    min = i - location[np];
                    location.erase(np);
                    location.insert(mp(np, i + 1));
                } 
                else{
                    location.erase(np);
                    location.insert(mp(np, i + 1));
 
                }
            }
                else{
                    location.insert(mp(mp(x, y), i + 1));
                }
            }
        if(min != (rob.length() + 1)) 
            cout << finalx << ' ' << finaly << '\n';
        else{
            cout << -1 << '\n';
        }
  }
  }
