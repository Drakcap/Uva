#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

bool preenchido[3001];

int main()
{
    
    int n;
    
    while (scanf("%d",&n) != EOF ) {
          
          for (int i = 0; i < n; i++) {
              preenchido[i] = false;
          }
          
          int anterior;
          int preenchidos = 0;
          
          scanf("%d", &anterior);
          //cout << anterior << " ";
          
          int i;
          
          for (i = 1; i < n; i++) {
              int num;
              scanf("%d", &num);
              //cout << num << " ";
              int diff = abs(num-anterior);
              if (diff >= n) {
                 break;
              }
              if (preenchido[diff]) {
                 break;
              }
              else {
                   preenchido[diff] = true;
                   ++preenchidos;
              }
              anterior = num;
          }
          ++i;
          //cout << "i: " << i << " ";
          for ( ; i < n; i++) {
              int temp;
              scanf("%d", &temp);
              //cout << temp << " ";
          }
          //cout << endl;
          
          bool is_jolly = (preenchidos == (n-1));      
          
          if (is_jolly) {
             printf("Jolly\n");
          }
          else {
               printf("Not jolly\n");
          }
          
          
          
    }
    
    
    
    return 0;
}
