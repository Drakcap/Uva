#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <list>
#include <vector>
using namespace std;

struct Numero {
       
       int pos;
       int valor;
};

struct Regra {
       
       string regra;
       vector<int> nums;
       list<string> regras;
       
       void faz_regra (string &regra) {
            regras.clear();
            nums.clear();    
            this->regra = regra;
             
             unsigned tam = regra.size();
             for (unsigned i = 0; i < tam; i++) {
                 if (regra[i] == '0') {
                    nums.push_back(i);             
                 }
             }
             
             faz_regras(0, regra);
       }
       
       
       
       
       void faz_regras(unsigned pos, string regra)
       {
            
            if (pos == nums.size()) {
               regras.push_back(regra);
               return;
            }
               
            string temp = regra;   
            for (unsigned i = 0; i < 10; i++) {
                faz_regras(pos+1, temp);
                temp[nums[pos]]++;                
            }

            
       }
       
       
       
};

string dicionario[100];
int n_palavras = 0;
Regra regras[1000];
int n_regras = 0;



int main()
{
    
    
    while ( scanf("%d", &n_palavras) != EOF ) {
          
        //le as palavras do dicionario
        for (int i = 0; i < n_palavras; i++) {
            cin >> dicionario[i];    
        }
        
        cout << "--" << endl;
        
        scanf("%d", &n_regras);
        
        //le as regras do dicionario e faz output das passwords
        for (int i = 0; i < n_regras; i++) {
            string temp;
            cin >> temp;
            regras[i].faz_regra(temp);
            
            for (int j = 0; j < n_palavras; j++) {
                
                list<string>::iterator it = regras[i].regras.begin();
                
                for ( ; it != regras[i].regras.end(); it++) {
                    
                    string r = *it;
                    unsigned tam = r.size();
                    
                    for (unsigned k = 0; k < tam; k++) {
                    
                        if (r[k] == '#') {
                           cout << dicionario[j];
                        }
                        else cout << r[k];    
                    }
                    cout << endl;
                }
            }
        }
        
    }
    
    
    
    return 0;
}
