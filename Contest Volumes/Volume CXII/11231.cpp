#include <iostream>
using namespace std;

int main()
{
    
    int linhas, colunas;
    bool branco;
    
    while (cin >> linhas >> colunas >> branco)
    {
          if (linhas == 0 && colunas == 0 && branco == 0) break;
          
          long long int n_xadrez = 0;
          long long int n_xadrez_linha1 = 0;
          long long int n_xadrez_linha2 = 0;
          colunas -= 7;
          linhas -= 7;
          
          if (branco) {
               n_xadrez_linha1 = (colunas + 1) /2;
               if (linhas > 1) {
                  if (colunas % 2 == 0) {
                       n_xadrez_linha2 = n_xadrez_linha1;         
                  }
                  else {        
                       n_xadrez_linha2 = n_xadrez_linha1 - 1;
                  }
               }       
          }
          else {
               n_xadrez_linha1 = colunas / 2;
               if (linhas > 1) {
                  if (colunas % 2 == 0) {
                       n_xadrez_linha2 = n_xadrez_linha1;         
                  }               
                  else {           
                          n_xadrez_linha2 = n_xadrez_linha1 + 1;
                       }
               }
          }
          
          int linhas_iguais_linha1 = (linhas + 1)/2;
          int linhas_dif_linha1 = linhas - linhas_iguais_linha1;
          
          n_xadrez = n_xadrez_linha1 * linhas_iguais_linha1 + n_xadrez_linha2 * linhas_dif_linha1;
          
          
          
          cout << n_xadrez << endl;
          
          
          
    }
    
    
    
    return 0;
}
