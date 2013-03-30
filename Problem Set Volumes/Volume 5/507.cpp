#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    
    int b;
    
    cin >> b;
    
    for (int i = 0; i < b; i++) {
        
        int n_stops;
        cin >> n_stops;
        
        int* valores = new int[n_stops];
        
        for (int j = 1; j < n_stops; j++) {
            cin >> valores[j];
        }
        
        long long int *somas = new long long int[n_stops];
        int* inicio = new int[n_stops];
        int* tamanho_caminho = new int[n_stops];
        
        somas[1] = valores[1];
        inicio[1] = 1;
        tamanho_caminho[1] = 1;
        long long int max_soma = valores[1];
        int stop_fixe = 2;
        int inicio_fixe = 1;
        int max_tam = 1;
        
        
        for (int j = 2; j < n_stops; j++) {
            if (valores[j] + somas[j-1] >= valores[j]) {
               somas[j] = valores[j] + somas[j-1];
               inicio[j] = inicio[j-1];
               tamanho_caminho[j] = tamanho_caminho[j-1] + 1;
            }
            else {
                 somas[j] = valores[j];
                 inicio[j] = j;
                 tamanho_caminho[j] = 1;
            }
            
            if (somas[j] > max_soma || (somas[j] == max_soma && tamanho_caminho[j] > max_tam)) {
               max_soma = somas[j];
               stop_fixe = j+1;
               inicio_fixe = inicio[j];
               max_tam = tamanho_caminho[j];
            }        
        }
        if (max_soma > 0)
           cout << "The nicest part of route " << i + 1 << " is between stops " << inicio_fixe << " and " << stop_fixe << endl;
        
        else
            cout << "Route " << i + 1 << " has no nice parts" << endl;
            
        free(somas);
        free(inicio);
        free(tamanho_caminho);
    }
    
    
    return 0;
}
