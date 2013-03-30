#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

list<int> digitos;
int divisor;
int num;

void imprime_lista ()
{
     list<int>::iterator it = digitos.begin();
     
     for ( ; it != digitos.end(); it++) {
         cout << *it;    
     }
     cout << endl;     
     
     
}

bool divide()
{
     
     while (divisor > 1) {
           
         int div = num % divisor;
         
         while (div == 0 && num > 1) {
               digitos.push_front(divisor);
               num /= divisor;
               div = num % divisor;
         }
         
         if (num <= 1) {
              return true;
         }
         else {
              --divisor;
         }
     }
     
     return false;
             
}


int main()
{
    
    int n_tests;
    cin >> n_tests;
    
    for ( ; n_tests; --n_tests)
    {
        
        cin >> num;
        digitos.clear();
        
        if (num == 0) {
           cout << 10 << endl;
        }
        else if (num == 1) {
             cout << 1 << endl;
        }
        
        else {
             
             divisor = 9;
             
             if (! divide()) {
                     cout << -1 << endl;
             }                                       
             else {
                  imprime_lista();
             }
        }
        
        
        
    }
    
    
    
    return 0;
}
