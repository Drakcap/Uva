#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;


struct DNA {
       
       string cadeia;
       int posicao;
       int trocas;
       
       bool operator<(const DNA &dna)
       {
            
            if (trocas == dna.trocas) {
               return (posicao < dna.posicao);
            }
            else {
                 return (trocas < dna.trocas);
            }
            
       }
};


void calcula_trocas (DNA &dna)
{
    
    int tam = dna.cadeia.size();
    dna.trocas = 0;
    
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (dna.cadeia[j] < dna.cadeia[i]) {
               ++dna.trocas;
            }
        }
    }
    
    
}


int main()
{
    
    int n_tests;
    bool first_run = true;
    
    cin >> n_tests;
    
    for ( ; n_tests; --n_tests)
    {
        
        if (!first_run) {
           cout << endl;
        }
        else {
             first_run = false;
        }
        
        int tam;
        int num;
        int posicao = 0;
        cin >> tam >> num;
        list<DNA> lista;
        
        for ( ; num; --num)
        {
            DNA dna;
            dna.posicao = posicao++;
            cin >> dna.cadeia;
            calcula_trocas(dna);
            lista.push_back(dna);
        }
        
        lista.sort();
        
        list<DNA>::iterator it = lista.begin();
        
        for ( ; it != lista.end(); it++) {
            cout << it->cadeia << endl;
        }
        
        
    }
    
    
    
    
    return 0;
}
