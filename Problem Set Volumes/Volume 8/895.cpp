#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

#define TAM_DIC 26

int main()
{

    int** dicionario;
    
    dicionario = new int*[1000];
    
    for (int i = 0; i < 1000; i++) {
        dicionario[i] = new int[TAM_DIC];
    }
    
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < TAM_DIC; j++) {
            dicionario[i][j] = 0;
        }
    }
    
    while (! cin.eof()) {
    
        string palavra;
        int n_palavras = 0;
        
        //ciclo para iniciar o dicionario
        while (getline(cin, palavra)) {
              if (palavra == "#") {break;}
              
              for (unsigned i = 0; i < palavra.size(); i++) {
                  dicionario[n_palavras][palavra[i] - 'a']++;
              }
              
              n_palavras++;
        }
        
        
        string linha;
        int* letras = new int[TAM_DIC];
        
        while ( getline(cin, linha)) {
            if (linha == "#") {
               break;
            }
            
            for (int i = 0; i < TAM_DIC; i++) letras[i] = 0;
            
            for (unsigned i = 0; i < linha.size(); i++) {
                if (linha[i] != ' ') {
                   letras[linha[i] - 'a']++;
                }
            }
            
            int servem = 0;
        
            for (int i = 0; i < n_palavras; i++) {
                
                bool serve = true;
                
                for (int j = 0; j < TAM_DIC; j++) {
                    
                    if (dicionario[i][j] != 0) {
                       if (letras[j] < dicionario[i][j]) {
                          serve = false;
                          break;
                       }
                    }
                }
                if (serve) servem++;
            }
            
            cout << servem << endl;

        }
        
        for (int i = 0; i < n_palavras; i++) {
            for (int j = 0; j < TAM_DIC; j++) {
                dicionario[j] = 0;
            }
        }

    }
   

    return 0;
    
}
