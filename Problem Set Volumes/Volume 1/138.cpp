#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    
    long long unsigned n = 0;
    long long unsigned casa = 6;
    long long unsigned final = 8;

    
    while (n < 10) {
          
          long long unsigned soma_menor = (casa-1) * (casa) / 2;
          
          
          while (true) {
                
                long long unsigned soma_maior = final * (final + 1) /2;
                soma_maior = soma_maior - soma_menor - casa;

                
                if (soma_maior > soma_menor) {
                   break;
                }
                
                if (soma_maior == soma_menor) {
                   cout << setw(10) << casa << setw(10) << final << endl;
                   n++;
                   break;
                }
                
                final++;
          }
          
          casa++;
    }
    
    return 0;
}
                
                
