#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    
    int num;
    
    while (cin >> num) {
          
          if (num == 0) break;
          
          cout << "The parity of ";
          
          string bin = "";
          int count = 0;
          
          while (num > 0) {
          
                int temp = num % 2;
                num /= 2;
                
                if (temp == 0) {
                   bin = "0" + bin;
                }
                else if (temp == 1) {
                     bin = "1" + bin;
                     ++count;
                }
              
                
          }
          
          cout << bin << " is " << count << " (mod 2)." << endl; 
          
    }
    
    return 0;
}
