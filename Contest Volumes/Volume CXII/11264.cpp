#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


long long int moedas[1001];

int main()
{
    int n_tests;
    cin >> n_tests;
    
    for ( ; n_tests; --n_tests) {
    
        int n_coins;
        cin >> n_coins;
        int resposta = 0;
        long long int soma = 0;
        ++resposta; //moeda de maior valor
        
        cin >> moedas[0];
        soma += moedas[0];
        
        for (int i = 1; i < n_coins; i++) {
            cin >> moedas[i];
            
            if (soma > moedas[i]) {
               soma -= moedas[i-1];
            }
            else {
                 ++resposta;
            }
            
            if (i < n_coins-1) {
               soma += moedas[i];
            }
            
        }    
        cout << resposta << endl;
        
        
        
    }
    
    
    
    return 0;   
}
