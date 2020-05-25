#include<bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        bool check = true;
        string pass;
        cin >> pass;
        string key = "";
        set<string> comb;
        set<char> elements;
        if(pass.length() == 1){
            printf("YES \n");
            for(int i = 0 ; i < 26 ; i++){
                cout << (char)(97 + i);
            }
            cout << '\n';
        }

        else if(pass.length() == 2){
            printf("YES\n");
            cout << pass;
            for(int i = 0 ; i < 26 ; i++){
                char ch = i + 97;
                if(ch != pass[0] || ch != pass[1]){
                    cout << ch;
                }
            }
            cout << '\n';
        }
        else{
            key += pass[0];
            key += pass[1];
            comb.insert(key);
            reverse(key.begin(), key.end());
            comb.insert(key);
            elements.insert(pass[0]);
            elements.insert(pass[1]);
            string init = "";
            char value = pass[1];
            init = init + value; 
            for(int i = 2 ; i < pass.length() ; i++){
               init = init + pass[i]; 
               if(comb.find(init) != comb.end()){
                   init = pass.substr(i, 1);
                   continue;
               }
               else {
                  if(elements.find(pass[i]) == elements.end()){
                   if(key[0] == init[0]){
                       key = pass[i] + key;
                       comb.insert(init);reverse(init.begin(), init.end());
                       comb.insert(init);
                       elements.insert(pass[i]);
                        init = pass.substr(i, 1);
                   }
                   else if(key[key.length() - 1] == init[0]){
                       key = key  + pass[i];
                        comb.insert(init);reverse(init.begin(), init.end());
                       comb.insert(init);
                       elements.insert(pass[i]);
                        init = pass.substr(i, 1);
                   }
                   else{
                       check  = false;
                       break;
                   }
               }
               else{
                   check = false;
                   break;
               }
               }
            }
            if(check){
                printf("YES\n");
                cout << key;
                for(int i = 0 ; i < 26 ; i++){
                    if(elements.find((char)(i + 97)) == elements.end()){
                        cout << (char)(i + 97);
                    }
                }
                printf("\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}