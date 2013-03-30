#include <iostream>
#include <string>
using namespace std;


int main()
{
    
    string texto;
    bool estado = true;
    
    while (getline(cin, texto)) {

          
          for (unsigned i = 0; i < texto.size(); i++) {
              
              if (texto[i] == '"') {
                 cout << (estado ? "``" : "''");
                 estado = !estado;
              }
              else {
                   cout << texto[i];
              }
          }
          cout << endl;
    
    }
    
    
    return 0;
}
