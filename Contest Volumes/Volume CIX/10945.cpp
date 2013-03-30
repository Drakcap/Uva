#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main()
{
    
    string linha;
    
    while (getline(cin, linha) != 0)
    {
          unsigned ini = 0;
          unsigned ult = (linha.size() == 0 ? 0 : linha.size()-1);
          bool is_palindrome = true;
          
          if(linha == "DONE") break;
          
          while (ini < ult) {
                
                while (linha[ini] == '.' || linha[ini] == ',' || linha[ini] == '!' || linha[ini] == '?' || linha[ini] == ' ') ++ini;
                
                while (linha[ult] == '.' || linha[ult] == ',' || linha[ult] == '!' || linha[ult] == '?' || linha[ult] == ' ') --ult;
                
                if (ult <= ini) break;
                
                linha[ini] = tolower(linha[ini]);
                linha[ult] = tolower(linha[ult]);
                
                if (linha[ult] != linha[ini]){
                   is_palindrome = false;
                   break;               
                }
                
                ini++;
                ult--;        
                
          }
          cout << (is_palindrome ? "You won't be eaten!" : "Uh oh..") << endl;
          
          
          
          
    }
    
    
    return 0;
}
