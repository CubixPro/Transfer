#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int> pos;
        vector<int> neg;
        int maxsum = 0;
        for(int i = 0 ; i < satisfaction.size() ; i++){
            if(satisfaction[i] < 0){
                neg.push_back(satisfaction[i]);
            }
            else{
                pos.push_back(satisfaction[i]);
            }
        }
        int totalsum = 0;
        int semisum = 0;
        
        sort(pos.begin(), pos.end());
        for(int i = 0 ; i < pos.size(); i++){
            totalsum += (i + 1)*pos[i];
            semisum += pos[i];
        }
        maxsum = totalsum;
        sort(neg.begin(), neg.end(), greater<int>());
        for(int i = 0 ; i < neg.size() ; i++){
           totalsum = totalsum + semisum + neg[i];
           if(totalsum > maxsum){
               maxsum = totalsum;
               semisum += neg[i];
           } 
           else{
               break;
           }
        }
        return maxsum;

    }
};
int main(){
    int size;
    cin >> size;

    vector<int> sat(size);
    for(int i = 0 ; i < size ; i++){
        cin >> sat[i];
    }
    Solution s;
    cout << s.maxSatisfaction(sat);
    
}