#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char matriz[110][110];
int linhas, colunas;

int processa_posicao (int linha, int coluna)
{
    
    //cout << "linha: " << linha << "coluna: " << coluna << endl;
    
    int count = 0;
    
    bool zero = (linha > 0 && coluna > 0);
    bool um = (linha > 0);
    bool dois = (linha > 0 && coluna < colunas-1);
    bool tres = (coluna < colunas-1);
    bool quatro = (linha < linhas-1 && coluna < colunas-1);
    bool cinco = (linha < linhas-1);
    bool seis = (linha < linhas-1 && coluna > 0);
    bool sete = (coluna > 0);
    
    /*
    if (linha == 3 && coluna == 0) {
       cout << zero << endl;
       cout << um << endl;
       cout << dois << endl;
       cout << tres << endl;
       cout << quatro << endl;
       cout << cinco << endl;
       cout << seis << endl;
       cout << sete << endl;
    }*/
       
    
    if (zero) {
       if (matriz[linha-1][coluna-1] == '*') {
          ++count;
       }
    }
    
    if (um) {
       if (matriz[linha-1][coluna] == '*') {
          ++count;
       }
    }
    
    if (dois) {
       if (matriz[linha-1][coluna+1] == '*') {
          ++count;
       }
    }
    
    if (tres) {
       if (matriz[linha][coluna+1] == '*') {
          ++count;
       }
    }   
     
    if (quatro) {
       if (matriz[linha+1][coluna+1] == '*') {
          ++count;
       }
    }   
    
    if (cinco) {
       if (matriz[linha+1][coluna] == '*') {
          ++count;
       }
    }
    
    if (seis) {
       if (matriz[linha+1][coluna-1] == '*') {
          ++count;
       }
    }
    
    if (sete) {
       if (matriz[linha][coluna-1] == '*') {
          ++count;
       }
    }
                 
    return count;
    
    
    
    
}

int main()
{
    
    bool first_run = true;
    int field = 0;
    
    while (scanf("%d %d", &linhas, &colunas))
    {
          if (linhas == 0 && colunas == 0) {
             break;           
          }
          
          if (! first_run) {
                cout << endl;
          }
          else {
               first_run = false;
          }
                    
          cout << "Field #" << ++field << ":" << endl; 
                   
          for (int i = 0; i < linhas; i++) {
              cin >> matriz[i];
          }
          
          /*
          for (int i = 0; i < linhas; i++) {
              cout << matriz[i] << endl;
          }
          cout << endl;*/
          
          //cout << linhas << " " << colunas << endl;
          
          for (int i = 0; i < linhas; i++) {
              for (int j = 0; j < colunas; j++) {
                  if (matriz[i][j] == '*') {
                     cout << "*";
                  }
                  else {
                       cout << processa_posicao(i,j);
                  }
                  
              }
              cout << endl;
          }
          
          
          
          
          
    }
    
    
    
    
    return 0;
}
