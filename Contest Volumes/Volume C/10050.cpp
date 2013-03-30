#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

bool dias[3660];
int n_dias;
int n_partidos;
int n_greves;

int main()
{
    
    int n_tests;
    cin >> n_tests;
    
    for ( ; n_tests; --n_tests) {
        
        cin >> n_dias;
        //cout << "dias: " << n_dias << endl;
        n_greves = 0;
        
        for (int i = 0; i <= n_dias; i++) {
            dias[i] = false;
        }
        cin >> n_partidos;
        
        for (int i = 0; i < n_partidos; i++) {
            int freq, acum;
            cin >> freq;
            acum = freq;
            
            while (acum <= n_dias) {
                  
                  int mod = acum % 7;
                  //cout << acum << " " << mod << endl;
                  
                  //sexta feira
                  if (mod == 6) {
                           
                  }
                  else if (mod == 0) {
                       
                  }
                  else if (! dias[acum]) {
                       ++n_greves;
                       dias[acum] = true;
                       //cout << acum << " " << mod << endl;
                  }      
                  
                  acum += freq;
            }
                
            
        }
        cout << n_greves << endl;
        
        
    }
    
    
    
    return 0;
}
