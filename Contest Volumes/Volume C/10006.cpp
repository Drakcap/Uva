#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MAX 65001

bool carmichael[MAX];
//bool ja_calc[MAX];
int n;

bool is_prime(const unsigned num)
{
     unsigned test_num, test_limit;
     
     if (num == 1)
        return false;
     
     else if (num == 2)
          return true;
     
     if (num % 2 == 0)
        return false;
     
     test_num = 3;
     test_limit = num;
     
     while (test_limit > test_num) {
           
           if (num % test_num == 0)
              return false;
           
           test_limit = num / test_num;
           
           test_num += 2;
     }
     
     return true;
}


int main()
{
    
    memset(carmichael, false, sizeof(carmichael));
    
    /*
    for (int i = 0; i < MAX; i++) {
        carmichael[i] = false;
    }*/
    
    carmichael[561] = true;
    carmichael[1105] = true;
    carmichael[1729] = true;
    carmichael[2465] = true;
    carmichael[2821] = true;
    carmichael[6601] = true;
    carmichael[8911] = true;
    carmichael[10585] = true;
    carmichael[15841] = true;
    carmichael[29341] = true;
    carmichael[41041] = true;
    carmichael[46657] = true;
    carmichael[52633] = true;
    carmichael[62745] = true;
    carmichael[63973] = true;
    
    
    
    
    while (scanf("%d", &n) && n != 0) {
          if (carmichael[n]) {
                cout <<  "The number " << n << " is a Carmichael number.";
          }
          else {
                cout << n << " is normal.";
          }
          cout << endl;
    }
    //for (n = 3; n < MAX; n++) {
          
          /*
          if (ja_calc[n]) {
             if (carmichael[n]) {
                cout <<  "The number " << n << " is a Carmichael number.";
             }
             else {
                  cout << n << " is normal.";
             }
             cout << endl;
             continue;     
          }*/
          /*
          bool serve = true;
          
          for (int a = 2; a < n; a++) {
              
              int levantado = 1;
              
              for (int i = 0; i < n; i++) {
                  levantado *= a;
                  levantado %= n;
                  //cout << levantado << endl;
              }
              
              if (levantado != a) {
                 serve = false;
                 break;
              }
          }
          
          if (serve) {   
             if (!is_prime(n)) {           
                cout << n << endl;
                carmichael[n] = true;
             }
          }
          
    }*/
    
    
    
    return 0;
}
