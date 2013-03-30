#include <iostream>
#include <string>
using namespace std;

#define MAX 120000

string palavras[MAX];
unsigned num_palavras = 0;
unsigned tam_maior;
unsigned tam_menor;

/*
bool procura_palavra(const string &palavra, const int inicio, const int fim)
{
     if (! (inicio <= fim) ) return false;
     if (inicio < 0) return false;

     unsigned meio = inicio + (fim-inicio) / 2;
     
     if (palavra > palavras[meio]) {
        return procura_palavra(palavra, meio+1, fim);
     }
     
     else if (palavra < palavras[meio]) {
          return procura_palavra(palavra, inicio, meio-1);
     }
     
     else return true;
}*/

//recursiva e nao recursiva demoram o mesmo tempo
bool procura_palavra(const string &palavra, int inicio, int fim)
{

     while (inicio <= fim && inicio >= 0) {
           
         unsigned meio = inicio + (fim-inicio) / 2;
         
         if (palavra > palavras[meio]) {
            inicio = meio+1;
         }
         
         else if (palavra < palavras[meio]) {
              fim = meio-1;
         }
         
         else if (palavra == palavras[meio]) return true;
         
     }
     return false;
}



int main()
{
    
    string palavra;
    cin >> palavra;
    
    tam_maior = palavra.size();
    tam_menor = palavra.size();
    palavras[num_palavras] = palavra;
    ++num_palavras;
    
    while (cin >> palavra) {
          
          if (palavra.size() > tam_maior) tam_maior = palavra.size();
          
          else if (palavra.size() < tam_menor) tam_menor = palavra.size();
          
          palavras[num_palavras] = palavra;
          ++num_palavras;
          
    }
    
    
    
    for (unsigned i = 0; i < num_palavras; i++) {
        
        if (tam_menor + tam_menor > palavras[i].size()) {
           continue;
        } 
        
        unsigned conta = palavras[i].size() - tam_menor;
        unsigned max = (conta > tam_maior ? tam_maior : conta);
        
        //j -> tamanho da primeira parte
        for (unsigned j = tam_menor; j <= max; j++) {
            
            if (! procura_palavra(palavras[i].substr(0, j), 0, num_palavras-1) ) {
                  continue;
            }
            else {
                 
                 if (procura_palavra(palavras[i].substr(j, palavras[i].size() - j), 0, num_palavras-1)) {
                    cout << palavras[i] << endl;
                    break;
                 }
            }
        }
        
        
        
    }
    
    
    
    return 0;
    
}
