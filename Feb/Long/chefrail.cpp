#include<bits/stdc++.h>

using namespace std;


int main(){
    int testcases;
    
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int nx, ny;
        scanf("%d %d", &nx, &ny);
        vector<int> xp;
        vector<int> xn;
        vector<int> yp;
        vector<int> yn;
        unordered_map<int, int> x;
        unordered_map<int, int> y;
        int maxy;
        int maxx;
        int count = 0;
        bool zero = false;
        for(int i = 0 ; i < nx ; i++){
            int val;
            scanf("%d", &val);
            if(val == 0){
                zero = true;
                continue;
            }
            if(val > 0){
                xp.push_back(val);
            }
            else{
                xn.push_back(val);
            }
            x.insert(make_pair(val, 1));
        }
        for(int i = 0 ; i < ny ; i++){
            int val;
            scanf("%d", &val);
            if(val == 0){
                zero = true;
                continue;
            }
            if(val > 0){
                yp.push_back(val);
            }
            else{
                yn.push_back(val);
            }
            y.insert(make_pair(val, 1));
        }
        sort(xp.begin(), xp.end());
        sort(xn.begin(), xn.end(), greater<int>());
        sort(yp.begin(), yp.end());
        sort(yn.begin(), yn.end(), greater<int>());
        /*
        if(!xp.empty()){
            maxx = xp[xp.size() - 1];
        
        if(!xn.empty()){
            maxx = max(maxx, abs(xn[xn.size() - 1]));
        }
        }
        else if(!xn.empty()){
            maxx = abs(xn[xn.size() - 1]);

        }
        if(!yp.empty()){
            maxy = yp[yp.size() - 1];
        
            if(!yn.empty()){
             maxy = max(maxy, abs(yn[yn.size() - 1]));
            }
        }
        else if(!yn.empty()){
             maxy = (abs(yn[yn.size() - 1]));
        }
        if(nx!= 0 && ny != 0){
            if(!xp.empty() && !xn.empty()){
        int max_square = abs(xp[xp.size() - 1] * xn[xn.size() - 1]);
        int max_square_root = sqrt(max_square);
        for(int i = 1 ; i <= min(max_square_root, maxy) ; i++){
            if(xn.size() <= xp.size()){
                for(int j = 0 ; j < xn.size() ; j++){
                    if((i * i)%xn[j] ==  0 && (y.find(-i) != y.end() || y.find(i) != y.end())){
                        int temp = i * i / xn[j] * -1;
                        if(x.find(temp) != x.end())
                        {
                            if(y.find(i) != y.end()){
                                count++;
                            }
                            if(y.find(-i) != y.end()){
                                count++;
                            }
                        }
                    }
                }
            }
            else{
                 for(int j = 0 ; j < xp.size() ; j++){
                    if((i * i)%xp[j] ==  0 && (y.find(-i) != y.end() || y.find(i) != y.end())){
                        int temp = i * i / xp[j];
                        if(x.find(temp) != x.end())
                        {
                            if(y.find(i) != y.end()){
                                count++;
                            }
                            if(y.find(-i) != y.end()){
                                count++;
                            }
                        }
                    }
                }
            }
        }
            }
            if(!yn.empty() && !yp.empty()){ 
         int max_square = abs(yp[yp.size() - 1] * yn[yn.size() - 1]);
         int max_square_root = sqrt(max_square);
        for(int i = 1 ; i <= min(max_square_root,maxx) ; i++){
            if(yn.size() <= yp.size()){
                for(int j = 0 ; j < yn.size() ; j++){
                    if((i * i)%yn[j] ==  0 && (x.find(-i) != x.end() || x.find(i) != x.end())){
                        int temp = i * i / yn[j] * -1;
                        if(y.find(temp) != y.end())
                        {
                            if(x.find(i) != x.end()){
                                count++;
                            }
                            if(x.find(-i) != x.end()){
                                count++;
                            }
                        }
                    }
                }
            }
            else{
                 for(int j = 0 ; j < yp.size() ; j++){
                    if((i * i)%yp[j] ==  0 && (x.find(-i) != x.end() || x.find(i) != x.end())){
                        int temp = i * i / yp[j] * -1;
                        if(y.find(temp) != y.end())
                        {
                            if(x.find(i) != x.end()){
                                count++;
                            }
                            if(x.find(-i) != x.end()){
                                count++;
                            }
                        }
                    }
                }
            }
        }
        }*/
        for(int i = 0 ; i < xp.size() ; i++){
            for(int j = 0 ; j < xn.size() ; j++){
                int prod = xp[i] * xn[j] * -1;
                int prodroot = sqrt(prod);
                if(prodroot*prodroot == prod){
                    if(y.find(-prodroot) != y.end()){
                        count++;
                    }
                     if(y.find(prodroot) != y.end()){
                        count++;
                    }
                }
            }
        }
        for(int i = 0 ; i < yp.size() ; i++){
            for(int j = 0 ; j < yn.size() ; j++){
                int prod = yp[i] * yn[j] * -1;
                int prodroot = sqrt(prod);
                if(prodroot*prodroot == prod){
                    if(x.find(-prodroot) != x.end()){
                        count++;
                    }
                     if(x.find(prodroot) != x.end()){
                        count++;
                    }
                }
            }
        }

        if(zero){
            count += (xp.size() + xn.size())*(yp.size() + yn.size());
        }
cout << count << '\n';
    }
}