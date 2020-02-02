#include<bits/stdc++.h>

using namespace std;
int backtrack(string s[], int n, int curr, int k, int tot, bool visited[]){
    if(curr == (n - 1))
        return tot;
    for(int i = 1 ; i <= k ; i++)
        if((curr + i) == (n - 1) && s[curr][n - 1] == '1')
        {
            return (tot + 1);
        }
    int max = INT_MAX;
    int total;
    bool ping = false;
    for(int i = 1 ; i <= k ; i++){
        if(((curr + i) < n) && (s[curr][curr + i] == '1') && visited[curr + i] == false && s[curr + i][curr + i] == '1')
        {   
            ping = true;
            visited[curr + i] = true;
            total = backtrack(s, n, curr + i, k, tot + 1, visited);
            if(total == -1)
                ;
            else
            {
                if(total <= max)
                    max = total;
            }
            visited[curr + i] = false;

        } 
        if(((curr - i) >= 0) && (s[curr][curr - i] == '1')  && visited[curr - i] == false && s[curr - i][curr - i] == '1')
        {   
            ping = true;
            visited[curr - i] = true;
            total = backtrack(s, n, curr - i, k, tot + 1, visited);
            if(total == -1)
                ;
            else
            {
                if(total <= max)
                    max = total;
            }
            visited[curr - i] = false;
        }
    }
        if(ping == false)
            return -1;
        if(total == -1)
            return total;

    return max;
}

int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase-- != 0){
        int n, k;
        scanf("%d %d", &n, &k);
        string s[n];
        bool visited[n];
        for(int i = 0 ; i < n ; i++){
            cin >> s[i];
        }
        memset(visited, false, sizeof(bool) * n);
   
        cout << backtrack(s, n, 0, k, 0, visited) << '\n';
    }
}
 