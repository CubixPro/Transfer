#include<bits/stdc++.h>

using namespace std;

typedef long long int lld; 

lld comb(lld n){
    return (n * (n - 1)/2);
}

 int main(){
     lld testcases;
     scanf("%lld", &testcases);
     while ((testcases-- != 0))
     {
         lld len;
         scanf("%lld", &len);
         map<lld, lld> x;
         map<lld, lld> y;
         lld count_doub = 0;
         lld total = len;
         lld coor[len][2];
        for(lld i = 0 ; i < len ; i++){
            scanf("%d %d", &coor[i][0], &coor[i][1]);
            if(x.find(coor[i][0]) == x.end())
                x.insert(make_pair(coor[i][0], 1));
            else{
                x[coor[i][0]]++;
            }
            if(y.find(coor[i][1]) == y.end())
                y.insert(make_pair(coor[i][1], 1));
            else{
                y[coor[i][1]]++;
            }
        }
        lld newlen = len;
        /*for(lld i = 0 ; i < newlen ; i++){
            if(x[coor[i][0]] >= 2 && y[coor[i][1]] >= 2){
                len--;
                x[coor[i][0]]--;
                y[coor[i][1]]--;
                coor[i][1] = -1;
                coor[i][0] = -1;
            }
        } */
        //cout << len;
        lld total_comb = comb(len);
        //cout << "wtf\n";
        map<lld, lld> :: iterator it;
        it = x.begin();
        while(it != x.end()){
            if(it->first >= 0)
                total_comb = total_comb - comb(it->second);
            it++;
        }
        it = y.begin();
        while(it != y.end()){
            if(it->first >= 0)
                total_comb = total_comb - comb(it->second);
            it++;
        }
        cout << total_comb << '\n';
     }
 }
 



     
 
 