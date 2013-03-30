#include <iostream>
#include <string.h>
using namespace std;

char matriz[25][25];
int somas[25][25];
int maior = 0;


int main()
{
    
    int n_testes;
    cin >> n_testes;
    bool first_run = true;
    
    for ( ; n_testes ; --n_testes) {
        
          maior = 0;
        
          if (! first_run) cout << endl;
          else first_run = false;
          
          cin >> matriz[0];
          
          int tam = strlen(matriz[0]);
          
          for (int i = 1; i < tam; i++) {
              cin >> matriz[i];
          }
          
          for (int i = 0; i < tam; i++) {
              for (int j = 0; j < tam; j++) {
                  somas[i][j] = 0;
              }
          }
          
          for (int i = 0; i < tam; i++) {
              
              for (int j = 0; j < tam; j++) {
                  
                  for (int k = i; k < tam; k++) {
                      
                      for (int l = j; l < tam; l++) {
                          
                          if (k == i && l == j) {
                                somas[k][l] = matriz[k][l] - '0';
                          }
                          
                          else if (k == i) {
                                somas[k][l] = (matriz[k][l] - '0') + somas[k][l-1];
                          }
                          
                          else if (l == j) {
                               somas[k][l] = (matriz[k][l] - '0') + somas[k-1][l];     
                          }
                          
                          else {
                               somas[k][l] = (matriz[k][l] - '0') + somas[k][l-1] - somas[k-1][l-1] + somas[k-1][l];
                          }
                          
                          if (somas[k][l] == ((k - i + 1) * (l - j + 1)) && somas[k][l] > maior) {
                             //cout << "maior: " << somas[k][l] << endl;
                             //cout << "i: " << i << "j: " << j << "k: " << k << "l: " << l << endl;
                             maior = somas[k][l];
                          }
                          /*
                          if (i == 2 && j == 3 && k == 7 && l == 4) {
                             cout << somas[7][4] << endl;
                          }*/
                      }
                      

                  }
                  

                  
                  /*
                  for (int i = 0; i < tam; i++) {
                      for (int j = 0; j < tam; j++) {
                          cout << somas[i][j] << " ";
                      }
                      cout << endl;
                  }
                  cout << endl;*/
                  
                  
              }
          }
          
                  /*       
                  for (int i = 0; i < tam; i++) {
                      for (int j = 0; j < tam; j++) {
                          cout << matriz[i][j] << " ";
                      }
                      cout << endl;
                  }
                  cout << endl;*/
          
          cout << maior << endl;
          

          
    }
    
    
    return 0;
    
}
