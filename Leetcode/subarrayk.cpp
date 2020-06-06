#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
       int p1 = 0, p2 = 0, p3 = 0;
        int count = 0;
       unordered_map<int, int> dict1;
        unordered_map<int, int> dict2;
     while(dict1.size() != k){
         add(dict1, A[p2]);
         add(dict2, A[p2]);
         p2++;
     } 
       for(; p2 <= A.size() ; ){
          while(!(dict2.size() < k)){
             remove(dict2, A[p3]); 
              p3++;
          } 
           count += (p3 - p1);
           if(p2 < A.size()){
            add(dict1, A[p2]);
           add(dict2, A[p2]);
               }
           p2++;
           if(dict1.size() > k){
               dict1 = dict2;
               p1 = p3;
               
           }
       } 
        return count;
    } 
    void add(unordered_map<int, int>& A, int val){
        if(A.find(val) == A.end()){
            A.insert({val, 1});
        }
        else{
            A[val]++;
        }
    }
    void remove(unordered_map<int, int>& A, int val){
        A[val]--;
        if(A[val] == 0){
            A.erase(val);
        }
    }
};




int main()
{
    int size, k;
    cin >> size >> k;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    Solution s;
    cout << s.subarraysWithKDistinct(arr, k);
}