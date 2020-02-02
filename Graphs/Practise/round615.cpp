#include<bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int num ;
        scanf("%d", &num);
        int newnum = num;
        int a = 1, b = 1, c = 1;
        bool find = true;
        vector<pair<int, int>> factors;
        for(int i = 2 ; i <= sqrt(num) ; i++){
            if(num%i == 0){
                factors.push_back(make_pair(i, 0));
                while(num%i == 0){
                    factors.back().second++;
                    num = num/i;
                }
            }
        }
        if(num != 1){
            factors.push_back(make_pair(num, 1));
        }
        if(factors.size() == 1){
            if(factors[0].second < 6){
                find = false;
            }
            else{
                find = true;
                a = factors[0].first;
                b = factors[0].first * factors[0].first;
                c = newnum/(a * b);
            }
        }
        else if(factors.size() == 2){
            if((factors[0].second == 2 && factors[1].second == 1) || (factors[0].second == 1 && factors[1].second == 2)){
                find = false;
            }
            else
            {
                find = true;
                a = factors[0].first;
                b = factors[1].first;
                c = newnum/(a * b);
                if(c == 1)
                find = false;
            }
            
        }
        else{
            a = factors[0].first;
            b = factors[1].first;
            c = newnum/(a * b);
        }
        if(find){
            printf("YES\n%d %d %d\n", a, b, c);
        }
        else{
            printf("NO\n");
        }
    }
}