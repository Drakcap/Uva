#include <iostream>
#include <map>
#include <string>
using namespace std;

inline bool is_consoante(char c)
{
     
     return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
     
}

int main()
{
    
    int L, N;
    
    while (cin >> L >> N)
    {
          
          map<string, string> plurais;
          
          //constroi dicionario de plurais
          for (int i = 0; i < L; i++) {
              string palavra, plural;
              cin >> palavra >> plural;    
              plurais.insert(make_pair(palavra,plural));
          }
          
          //le as palavras e mostra plural
          for (int i = 0; i < N; i++) {
          
              string palavra;
              cin >> palavra;
              
              map<string,string>::iterator it = plurais.find(palavra);
              unsigned fim = palavra.size()-1;
              
              //palavra irregular
              if (it != plurais.end()) {
                     cout << it->second << endl;
              }
              
              //termina em consoante seguida de y
              else if (palavra[fim] == 'y' && is_consoante(palavra[fim-1]) ) {
                 palavra[palavra.size()-1] = 'i';
                 palavra += "es";
                 cout << palavra << endl;                                                        
              }
              
              else if (palavra[fim] == 'o' || palavra[fim] == 's' || palavra[fim] == 'x') {
                   cout << palavra << "es" << endl;     
              }
              
              else if (palavra[fim] == 'h' && (palavra[fim-1] == 's' || palavra[fim-1] == 'c') ) {
                   cout << palavra << "es" << endl;     
              }
              
              else {
                   cout << palavra << "s" << endl;
              } 
              
                  
              
          }
          
          
          
          
    }
    
    
    
    
    
    return 0;
}
