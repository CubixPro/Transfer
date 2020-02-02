#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef long long int lld;

/*int main(){
    lld n, m;
    scanf("%lld %lld", &n, &m);
    lld arr[n][m];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%lld", &arr[i][j]);
        }
    }
    lld total_max = 0;
    lld a = 0, b = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j =  i + 1 ; j < n ; j++){
            lld min_val = max(arr[i][0], arr[j][0]);
            for(int k = 1 ; k < m ; k++){
                min_val = min(min_val, max(arr[i][k], arr[j][k]));
            }
            if(min_val > total_max){
                total_max = min_val;
                a = i;
                b = j;
            }
        }
    }
    printf("%lld %lld\n", a + 1, b + 1);
}*/



/*int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr_max[n + 1];
    int arr_min[n + 1];
    for(int i = 1 ; i <= n ; i++ ){
        arr_min[i] = i;
        arr_max[i] = i;
    }
    int count[n + 1];
    for(int i = 1 ; i < n ; i++){
        count[i] = -1;
    }
    int i = 1;
    while(m-- != 0){
        int val;
        scanf("%d", &val);
        arr_min[val] = 1;
        if(count[val] == -1)
        {
            count[val] = i ; 
            arr_max[val] = min(n, max(val, val + i - 1));
        }
        else{
            arr_max[val] = min((n),  max(arr_max[val], i - count[val]));
            count[val] = i;
        }
        i++;
    }
            //cout << i;
    for(int k = 1 ; k <= n ; k++){
        if(count[k] != -1)
            arr_max[k] = min(n, max(arr_max[k], i - count[k]));
        else{
            //cout << "hi";
            arr_max[k] = min(n, i);
            
        }
    }
    for(int i = 1 ; i <= n ; i++){
        printf("%d %d\n", arr_min[i], arr_max[i]);
    }
}*/
/*lld nCrModpDP(int n, int r, int p) 
{ 
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    lld C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (int i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}
int main(){

    int n, m;
    scanf("%d %d", &n, &m);
    int num = n + 2 * m - 1;
    int den = n - 1;
    lld comb = nCrModpDP(num, den, mod);
    printf("%lld", comb);
}*/


/*int calc_min(int* arr1, int* arr2, int length){
    int min_val = max(arr1[0], arr2[0]);
    for(int i = 1 ; i < length ; i++){
        min_val = min(max(arr1[i], arr2[i]), min_val);
    }
    return min_val;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int a = 0, b = 1;
    int arr[n][m];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int min_val = calc_min(arr[a], arr[b], m);
    for(int i = 2 ; i < n ; i++){
        int min_val1 = calc_min(arr[a], arr[i], m);
        int min_val2 = calc_min(arr[b], arr[i], m);
        if(min_val1 > min_val){
            b = i;
            min_val = min_val1;
            cout << a << ' ' << b << '\n';
        }
        if(min_val2 > min_val)
        {
            a = i;
            min_val = min_val2;
         cout << a << ' ' << b << '\n';
        }
    }
    printf("%d %d", (a + 1), (b + 1));
}*/

/*int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    stack<int> msg;
    for(int i = n ; i >= 1 ; i--){
        msg.push(i);
    }
    for(int i = 1 ; i <= m ; i++){
        int val ;
        scanf("%d", &val);
        msg.push(val);
    }
    int last_seen[n + 1];
    int count[n + 1];
    int arr_max[n + 1];
    int arr_min[n + 1];
    int count_repeats = 0;
    int count_repeat_sub[n + 1];
    for(int i = 1 ; i <= n ; i++){
        last_seen[i] = 0;
        count[i] = 0;
        count_repeat_sub[i] = 0;
        arr_max[i] = i;
        arr_min[i] = i;
    }
    int i = 0;
    while(!msg.empty())
    {
        i++;
        int val  = msg.top();
        arr_max[val] = min(n, max(i - last_seen[val] - count_repeats + count_repeat_sub[val], arr_max[val]));
        count[val]++;
        if(count[val] >= 2)
            count_repeats++;
        last_seen[val] = i;
        count_repeat_sub[val] = count_repeats;
        if(i <= m)
            arr_min[val] = min(arr_min[val], 1);
        msg.pop();
    }
    
    for(int i = 1 ; i <= n ; i++){
        printf("%d %d\n", arr_min[i], arr_max[i]);
    }
    
}*/


int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
}