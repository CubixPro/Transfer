#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;

llu power(llu a, llu b)
{
    llu res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            res = res * a;
        }
        b = b / 2;
        a = a * a;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    //llu val123 =  power(2, 2000);
    //cout << val123;
    cin >> n >> m; //1 -> unlocked 0 -> locked
    //int door = 0;
    //int final_door = power(2, n) - 1;
    //cout << final_door;
    set<int> closed;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        if (val == 0)
        {
            closed.insert(i);
        }
    }
    bool found = false;
    if (closed.empty())
    {
        found = true;
    }
    for (int i = 0; i < m; i++)
    {
        int con;
        cin >> con;
        set<int> temp;
        
        for (int j = 0; j < con; j++)
        {
            int doornum;
            cin >> doornum;
            temp.insert(doornum);
        }
        if(temp  == closed){
            found = true;
        }
    }
    if (found)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << '\n';
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef  long long int llu;
 
llu pow(llu a, llu b){
    llu res = 1;
    while(b != 0){
        if(b%2 == 1){
            res = res * a;
        }
        b = b/2;
        a = a*a; 
    }
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    llu n, m;
    cin >> n >> m;//1 -> unlocked 0 -> locked
    llu door = 0;
    llu final_door = pow(2, n) - 1;
    //cout << final_door;
    for(llu i = 1 ; i <= n ; i++){
        llu val;
        cin >> val;
        door += pow(2, n - i)*val;
    }
    bool found = false;
    if(door == final_door){
        found = true;
    }
    for(llu i = 0 ; i < m ; i++){
        llu val = door;
        llu con;
        cin >> con;
        for(llu j = 0 ; j < con ; j++){
            llu doornum;
            cin >> doornum;
            val ^= (1<<(n - doornum));
            //cout << val << '\n';
        }
        if(val == final_door){
            found = true;
            //break;
        }
    }
    if(found){
        cout << "YES";
    }
    else{
        cout << "NO";
 
    }
    cout << '\n';
 
}
*/ 