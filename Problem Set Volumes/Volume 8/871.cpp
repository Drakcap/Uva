#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    string linha;
    string prox_linha;
    cin >> linha;
    cin >> prox_linha;
    
    int *matriz = new int[linha.size()];
    int *matriz_seguinte = new int[linha.size()];
    matriz[0] = (linha[0] == '0' ? 0 : 1);
    int maximo = 0;
    
    for (unsigned i = 1; i < linha.size(); i++) {
        if (linha[i] == '0') {
           matriz[i] = 0;
        }
        else {
             int novo_valor = matriz[i-1]+1;
             matriz[i] = novo_valor;
             
             if(novo_valor > maximo) maximo = novo_valor;      
        }    
    }
    
    int ix_max = -1;
    int ix_min = -1;
    
    while (cin >> linha) {
          
          if (linha[0] == '1') {
             ++matriz[0];
             if(matriz[0] > maximo) maximo = matriz[0];
          }
          
          for (unsigned i = 1; i < linha.size(); i++) {
              if (linha[i] == '0') {
                 matriz[i] = 0;
              }
              
              else {
                   //int melhor antigo     
                   
              }
          }
          
    }
    
    
    return 0;
}
