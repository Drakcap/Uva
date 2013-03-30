#include <string>
#include <iostream>
using namespace std;

int main()
{
    
    int G;
    
    cin >> G;
    
    while (G != 0) {
          
          string frase;
          
          cin >> frase;
          
          int tam_grupo = frase.size() / G;
          
          int final = 0;
          int i = tam_grupo - 1;
                
          
          for (int i = tam_grupo -1; i >= final && final < frase.size(); i--) {
              cout << frase[i];
              
              if (i == final) {
                    final += tam_grupo;
                    i = final + tam_grupo;
              }
          }
          
          cout << endl;
          
          cin >> G;
          
          
    }
    
    
    return 0;
}
