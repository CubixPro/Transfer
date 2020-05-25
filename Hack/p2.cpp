#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int len = str1.length(), i, j;
    vector<int> pi12(len), pi21(len);
    for(i = 1 ; i < len ; i++){
        j = pi12[i - 1];
        while(j > 0  && str2[i] != str1[j])
            j = pi12[j - 1];
        if(str2[i] == str1[j]){
            j++;
        }
        pi12[i] = j;
        j = pi21[i - 1];
        while(j > 0 && str1[i] != str2[j])
            j = pi21[j - 1];
        if(str1[i] == str2[j])
            j++;
        pi21[i] = j;
    }

    
    for(i = 0 ; i < len ; i++){
        if(str1[i] == str2[i]){
            pi12[i] = i + 1;
        }
    }
    int maxlen = 0;
    for(i = 0 ; i < len ; i++){
        if(pi12[i] + pi21[i] >= i + 1)
            maxlen = i + 1;
    }
    cout << maxlen << endl;
    return 0;
}
