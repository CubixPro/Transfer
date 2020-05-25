#include <bits/stdc++.h>
#include <cmath>
#define lld long long int
#define llf long long double
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define cases  \
    lld T = 0; \
    cin >> T;  \
    while (T--)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define MAXN 2000


using namespace std;

int main(){
    cases{
        int n;
        cin >> n;
        int arr4[] = {2, 4, 1, 3};
        int arr5[] = {1, 4, 2, 5, 3};
        int arr6[] = {1, 4, 2, 5, 3, 6};
        int arr7[] = {1, 4, 2, 6, 3, 5, 7};
        int arr8[] = {1, 4, 2, 6, 3, 7, 5, 8};
        int arr9[] = {1, 4, 8, 5, 2, 6, 3, 7, 9 };
        if(n == 1){
            cout << 1 ;
        }
        else if(n == 2 || n == 3){
            cout << -1;
        }
        else{
            if(n == 4){
                for(int i = 0 ; i < 4 ; i++){
                    cout << arr4[i] << ' ' ;
                }
            }
            else if(n%5 == 0){
                for(int i = 0 ; i < n/5 ; i++){
                   for(int j = 0 ; j < 5 ; j++ )
                        cout << (arr5[j] + i * 5) << ' '; 
                }
            }
            else if(n%5 == 1){
                for(int i = 0 ; i < n/5 - 1 ; i++){
                    for(int j = 0 ; j < 5 ; j++ )
                        cout << (arr5[j] + i * 5) << ' ';

                }
                for(int i = 0 ; i < 6 ; i++){
                    cout << (arr6[i] + (n/5 - 1)*5) << ' ';
                }
            }
             else if(n%5 == 2){
                for(int i = 0 ; i < n/5 - 1 ; i++){
                   for(int j = 0 ; j < 5 ; j++ )
                        cout << (arr5[j] + i * 5) << ' ';

                }
                for(int i = 0 ; i < 7 ; i++){
                    cout << (arr7[i] + (n/5 - 1)*5) << ' ';
                }
            }
             else if(n%5 == 3){
                for(int i = 0 ; i < n/5 - 1 ; i++){
                    for(int j = 0 ; j < 5 ; j++ )
                        cout << (arr5[j] + i * 5) << ' ';

                }
                for(int i = 0 ; i < 8 ; i++){
                    cout << (arr8[i] + (n/5 - 1)*5) << ' ';
                }
            }
             else if(n%5 == 4){
                for(int i = 0 ; i < n/5 - 1 ; i++){
                    for(int j = 0 ; j < 5 ; j++ )
                        cout << (arr5[j] + i * 5) << ' ';

                }
                for(int i = 0 ; i < 9 ; i++){
                    cout << (arr9[i] + (n/5 - 1)*5) << ' ';
                }
            }
            
        }
        cout << '\n';
    }
}