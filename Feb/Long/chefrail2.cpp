#include<bits/stdc++.h>

using namespace std;
typedef long long int lld;
lld min_take_give(lld val){
    for(lld i = sqrt(val); i >= 1 ; i--){
        if(val%(i * i) == 0){
            return (val/(i * i));
        }
    }
    return 1;
}

int main(){
    lld testcases;
    scanf("%lld", &testcases);
    while(testcases-- != 0){
        lld nx, ny;
        scanf("%lld %lld", &nx, &ny);
        unordered_map<lld, lld> x;
        unordered_map<lld, lld> y;
        unordered_map<lld, vector<lld>> give;//positive
        unordered_map<lld, vector<lld>> take;//negetive
        lld count = 0;
        bool zero = false;
        for(lld i = 0 ; i < nx ; i++){
            lld val;
            scanf("%lld", &val);
            if(val == 0){
                zero = true;
                continue;
            }
            x.insert(make_pair(val, 1));
            if(val > 0){
            lld temp = min_take_give(val);
                if(give.find(temp) == give.end()){
                    vector<lld> tmp;
                    tmp.push_back(val);
                    give.insert(make_pair(temp, tmp));
                }
                else{
                    give[temp].push_back(val);
                }
            } 
           
            else {
                val = -val;
                lld temp = min_take_give(val);
                    if(take.find(temp) == give.end()){
                    vector<lld> tmp;
                    tmp.push_back(val);
                    take.insert(make_pair(temp, tmp));
                }
                else{
                    take[temp].push_back(val);
                }

            }


        }
        for(lld i = 0 ; i < ny ; i++){
             lld val;
            scanf("%lld", &val);
            if(val == 0){
                zero = true;
                continue;
            }
            y.insert(make_pair(val, 1));
        }
        unordered_map<lld, vector<lld>> :: iterator it = give.begin();
        while(it != give.end()){
            lld val = (*it).first;
            if(take.find(val) == take.end()){
                it++;
                continue;
            }
            else{
                for(lld i = 0 ; i< (*it).second.size() ; i++){
                    for(lld j = 0 ; j < take[val].size() ; j++){
                        lld p;
                        if(y.find((p = sqrt((*it).second[i]*take[val][j]))) != y.end()){
                            count++;
                        }
                        if(y.find(-p) != y.end()){
                            count++;
                        }
                    }
                }
            }
            it++;
        }
        give.clear();
        take.clear();
        unordered_map<lld, lld> :: iterator ip = y.begin();
        while(ip != y.end()){
            lld val = (*ip).first;
            if(val > 0){
            lld temp = min_take_give(val);
                if(give.find(temp) == give.end()){
                    vector<lld> tmp;
                    tmp.push_back(val);
                    give.insert(make_pair(temp, tmp));
                }
                else{
                    give[temp].push_back(val);
                }
            } 
           
            else {
                val = -val;
                lld temp = min_take_give(val);
                    if(take.find(temp) == give.end()){
                    vector<lld> tmp;
                    tmp.push_back(val);
                    take.insert(make_pair(temp, tmp));
                }
                else{
                    take[temp].push_back(val);
                }

            }


            ip++;
        }

         it = give.begin();
        while(it != give.end()){
            lld val = (*it).first;
            if(take.find(val) == take.end()){
                it++;
                continue;
            }
            else{
                for(lld i = 0 ; i< (*it).second.size() ; i++){
                    for(lld j = 0 ; j < take[val].size() ; j++){
                        lld p;
                        if(x.find((p = sqrt((*it).second[i]*take[val][j]))) != x.end()){
                            count++;
                        }
                        if(x.find(-p) != x.end()){
                            count++;
                        }
                    }
                }
            }
            it++;
        }
    if(zero){
        count += (x.size() * y.size());
    }
    cout << count << '\n';
    }
}