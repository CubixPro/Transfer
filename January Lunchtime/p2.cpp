#include<iostream>
#include<algorithm>


using namespace std;

typedef long long int lld;


lld abso(lld val){
    if(val >= 0)
        return val;
    else 
        return -val;
}

int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase-- != 0){
        lld n, a, b, c;
        scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
        lld arr[n];
        int fren = -1;
        lld min_val = INT64_MAX;
        int j;
        for(lld i = 0 ; i < n ; i++){

            scanf("%lld", &arr[i]);
            if(((arr[i] >= a && arr[i] <= b && b >= a) || (arr[i] <= a && arr[i] >= b && a >= b)) && fren == -1)
            {
                fren = i;
            }
            if( (abso(arr[i] - b) + abso(arr[i] - a) + c) <= min_val)
            {
                min_val = abso(arr[i] - b) + abso(arr[i] - a) + c;
                j = i;
            }
            
        }
        if(fren == -1){
            sort(arr, arr+n);
            if(abso(arr[0] - b) <= abso(arr[n - 1] - b))
                fren = arr[0];
            else
            {
                fren = arr[n - 1];
            }
            
        }
        lld final_val = abso(fren - b) + abso(fren - a) + c;
        //cout << final_val << '\n';
        printf("%lld\n", min_val);
    }
}
        