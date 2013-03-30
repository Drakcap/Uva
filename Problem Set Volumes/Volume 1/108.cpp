#include <iostream>
using namespace std;

int matriz[100][100];
int matriz_orig[100][100];
int N;
int max_soma;
bool ha_max = false;

void processa_matriz (int n_linhas)
{
     for (int i = 0; i < n_linhas; i++) {
         
         int temp = matriz[i][0];
         
         for (int j = 1; j < N; j++) {
             temp = (temp < 0 ? matriz[i][j] : temp + matriz[i][j]);
             
             if (! ha_max || max_soma < temp) {
                   max_soma = temp;
                   ha_max = true;
                   //cout << "i " << i << " j " << j << endl;
             }
         }    
         
     }
     
     
}

void actualiza_matriz (int linha_inicial)
{
     
     for (int i = linha_inicial, j = 0; i < N; i++, j++) {
         
         for (int c = 0; c < N; c++) {
             matriz[j][c] += matriz_orig[i][c];
         }    
         
     }     
     
}


int main()
{
    
    while (cin >> N) {
          
          for (int i = 0; i < N; i++) {
              for (int j = 0; j < N; j++) {
                  cin >> matriz[i][j];
                  matriz_orig[i][j] = matriz[i][j];
              }
              
          }
          
          //i = linha a somar 'a primeira
          for (int i = 1, j = N; i < N; i++, j--) {
              processa_matriz(j);
              //cout << max_soma << endl;
              actualiza_matriz(i);
          }
          
          
          cout << max_soma << endl;
          
    }
    
    
    return 0;
    
}
