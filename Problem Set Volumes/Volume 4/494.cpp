#include <iostream>
#include <string>
using namespace std;

bool e_letra(char letra)
{
     
     if (letra >= 'a' && letra <= 'z')
        return true;
        
     if (letra >= 'A' && letra <= 'Z')
        return true;
        
     return false;
     
}

int main()
{
    
    string linha;
    
    while (getline(cin, linha)) {
          
          int n_palavras = 0;
          
          for (unsigned i = 0; i < linha.size(); i++) {
              bool palavra = false;
              while (e_letra(linha[i])) {
                    palavra = true;
                    i++;
                    
                    if (i > linha.size()) break;
              }
              
              if(palavra) ++n_palavras;     
              
          }
          
          cout << n_palavras << endl;      
          
    }
    
}
