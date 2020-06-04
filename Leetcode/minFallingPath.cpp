#include<bits/stdc++.h>

using namespace std;

int elementAt(vector<vector<int>> A, int i, int j){
    if(i < A.size()){
        if(j < A[i].size()){
            return A[i][j];
        }
        return 110;
    }
    else{
        return 110;
    }
}

int minPath(vector<vector<int>>& A, int i, int j){
    if((i + 1) == A.size()){
        return min(elementAt(A, i, j), elementAt(A, i, j + 1), elementAt(A, i, j - 1));
    }
    else{
        int minval = 100000;
        if(j >= 0 && j < A[i].size()){
            minval = min(minval, minPath(A, i + 1, j) + A[i][j]);
        }
        if((j - 1) >= 0 && (j - 1) < A[i].size()){
            minval = min(minPath(A, i + 1, j - 1) + A[i][j - 1], minval);
        }
        if((j + 1) >= 0 && (j + 1) < A[i].size()){
            minval = min(minPath(A, i + 1, j + 1) + A[i][j + 1], minval);
        }
        return minval;
    }
}


int minFallingPathSum(vector<vector<int>>& A) {
        int minval = 100000;
        if(A.size() == 1){
            for(int i = 0 ; i < A[0].size() ; i++){
               minval = min(minval, A[0][i]);
            }
            return minval;
        }
        else{
            for(int i = 0 ; i < A[0].size() ; i++){
                minval = min(minval, A[0][i] + minPath(A, 1, i));
            }
            return minval;
        }
}

int main(){
    vector<vector<int>> A(3);
    A[0].push_back(-80);
    A[0].push_back(-13);
    A[0].push_back(22);
    A[1].push_back(83);
    A[1].push_back(94);
    A[1].push_back(-5);
    A[2].push_back(73);
    A[2].push_back(-48);
    A[2].push_back(61);

    cout << minFallingPathSum(A);
}