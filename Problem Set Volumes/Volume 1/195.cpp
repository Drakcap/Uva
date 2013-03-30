#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <cctype>
using namespace std;


struct Palavra {

       string palavra;       
       
       bool operator<(const Palavra& p)
       {
            unsigned tam1 = 0, tam2 = 0;
            
            while (true)
            {
                  
                  if (tam1 == palavra.size()) {
                           return true;
                  }
                  
                  if (tam2 == p.palavra.size()) {
                           return false;
                  }
                  
                  int l1 = tolower(palavra[tam1]);
                  int l2 = tolower(p.palavra[tam2]);
                  
                  if (l1 < l2) {
                         return true;
                  }
                  
                  if (l2 < l1) {
                         return false;
                  }
                  
                  if (palavra[tam1] != p.palavra[tam2]) {
                     return (palavra[tam1] < p.palavra[tam2]);                  
                  }
                  
                  
                  ++tam1;
                  ++tam2;
                  
                  
                  
            }
            
            
       }
       
};


int main()
{
    Palavra p1;
    Palavra p2;
    p1.palavra = "a";
    p2.palavra = "A";

    int n_words;
    
    cin >> n_words;
    
    for (int i = 0; i < n_words; i++) {
        
        list<Palavra> lista;
        string palavra, anterior;
        
        cin >> palavra;
        anterior = palavra;
        
        do {
                 Palavra p;
                 p.palavra = palavra;
                 lista.push_back(p);      
                 next_permutation(palavra.begin(), palavra.end());
        } while (palavra != anterior);
        
        lista.sort();
        list<Palavra>::iterator it = lista.begin();
        
        for ( ; it != lista.end(); it++) {
            cout << it->palavra << endl;
        }
    }

    
    
    
    return 0;
}
