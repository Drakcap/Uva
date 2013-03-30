#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    
    string linha;
    
    while (cin >> linha) {
    
          int tam = linha.size();
          
          for (int i = 0; i < tam; i++) {
              cout << (char) (linha[i] - 7);
          }
          cout << endl;      
          
          
    }
    
    
    
    
    
}
