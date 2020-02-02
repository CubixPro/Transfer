#include<bits/stdc++.h>

using namespace std;
bool compareNumbers(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
       return true; 
    if (n2 < n1) 
       return false; 
  
    // If lengths are same 
    for (int i=0; i<n1; i++) 
    { 
       if (str1[i] < str2[i]) 
          return true; 
       if (str1[i] > str2[i]) 
          return false; 
    } 
  
    return false; 
}  

int main(){
    int testcases;
    scanf("%d", &testcases);
    while(testcases-- != 0){
        int n;
        scanf("%d", &n);
        string num[n];
        string num1[n];
        map<string, int> count1;
        map<string, int> count2;
        map<string, int> count3;//occurences
        for(int i = 0 ; i < n ; i++){
            cin >> num[i];
            num1[i] = num[i];
        }
        for(int i = 0 ; i < n ; i++){
            if(count3.find(num1[i]) == count3.end()){
                count3.insert(make_pair(num1[i], 1));

            }
            else{
                count3[num1[i]]++;
            }
        }
        

        
        sort(num1, num1 + n, compareNumbers);
        
        string numf[n];
        int counter  = 0;
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
            numf[counter] = num1[i];
            counter++;
            }
            else{
                if(numf[counter - 1] == num1[i])
                    continue;
                else{
                    numf[counter] = num1[i];
                    counter++;
                }
            }
        } 

        for(int i = 0 ; i < counter ; i++){
            if(i == 0){
                count1.insert(make_pair(numf[i], 0));
            }
            else{
                count1.insert(make_pair(numf[i], count1[numf[i - 1]] + count3[numf[i - 1]]));
            }
        }

        for(int i = 0 ; i < counter ; i++){
            if(i == 0){
                count2.insert(make_pair(numf[i], 0));
            }
            else{
                count2.insert(make_pair(numf[i], (count2[numf[i - 1]] + count3[numf[i - 1]]*(numf[i - 1][numf[i - 1].length() - 1] - 48)) % 10));
            }
        }

        for(int i = 0 ; i < n ; i++){
            printf("%d %d\n", count1[num[i]], count2[num[i]]);
        }
    }

}