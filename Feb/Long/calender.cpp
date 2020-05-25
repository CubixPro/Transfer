#include<bits/stdc++.h>

using namespace std;


int day_of_week( int year, int month, int day )
  {
  int a, y, m;
  a = (14 - month) / 12;
  y = year - a;
  m = month + (12 * a) - 2;
  // Gregorian:
  return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
  }
int leap(int y, int mon){
    if(mon == 2){
    if((y%4 == 0 && y%100 != 0) || (y%400 == 0)){
        return 29;
    }
    return 28;
    }
    else{
        int arr[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return arr[mon - 1];
    }
}

  int main(){
     int testcases;
     scanf("%d", &testcases);
     while(testcases-- != 0){
        int count = 0;
        int m1, y1, m2, y2;
        cin >> m1 >> y1;
        cin >> m2 >> y2;
        for(int i = y1 + 1 ; i <= y2 - 1 ; i++){
            for(int j = 1 ; j <= 12  ; j++){
            int day = day_of_week(i, j, 1);
            int date = 1 + (5 - day);
            if(date <= 0){
                date += 7;
            }
            int lunchtime = date + 10;
            int days = leap(i, j);
            day = day_of_week(i, j, days);
            int cookoff = days - day - 7;
            if(cookoff < lunchtime){
               // << i << ", ";
                count++;
            }
            }
        }
        if(y1 == y2){
        for(int i = m1 ; i <= m2 ; i++){
            int day = day_of_week(y1, i, 1);
            int date = 1 + (5 - day);
            if(date <= 0){
                date += 7;
            }
            int lunchtime = date + 10;
            int days = leap(y1, i);
            day = day_of_week(y1, i, days);
            int cookoff = days - day - 7;
            if(cookoff < lunchtime){
               // <<  y1 << " ,";
                count++;
            }
 
        }
        }
        else{
            for(int i = m1 ; i <= 12 ; i++){
            int day = day_of_week(y1, i, 1);
            int date = 1 + (5 - day);
            if(date <= 0){
                date += 7;
            }
            int lunchtime = date + 10;
            int days = leap(y1, i);
            day = day_of_week(y1, i, days);
            int cookoff = days - day - 7;
            if(cookoff < lunchtime){
               // <<  y1 << ", ";
                count++;
            }
 

            }
            for(int i = 1 ; i <= m2 ; i++){
            int day = day_of_week(y2, 2, 1);
            int date = 1 + (5 - day);
            if(date <= 0){
                date += 7;
            }
            int lunchtime = date + 10;
            int days = leap(y2, i);
            day = day_of_week(y2, i, days);
            int cookoff = days - day - 7;
            if(cookoff < lunchtime){
               // <<  i << ", ";
                count++;
            }
 

            }
        }  
       cout << count << '\n';
     } 
      
  }