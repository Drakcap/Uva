#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;


struct Info {
       
       int n_ocorrencias;
       int posicao;
};


struct Inteiro {
       
       int n_ocorrencias;
       int posicao;
       int num;
       
       bool operator<(const Inteiro &i)
       {
            return (posicao < i.posicao);     
       }     
       
};


int main()
{
    
    map<int,Info> mapa;
    
    int num, posicao = 0;
    
    while (cin >> num)
    {
          
          map<int,Info>::iterator it = mapa.find(num);
          
          if (it != mapa.end()) {
             ++it->second.n_ocorrencias;       
          }
          else {
               Info i;
               i.n_ocorrencias = 1;
               i.posicao = posicao;
               mapa.insert(make_pair(num, i));
               ++posicao;     
          }
          
    }
    
      list<Inteiro> lista;
      map<int,Info>::iterator it = mapa.begin();
      
      for ( ; it != mapa.end(); it++) {
          Inteiro i;
          i.n_ocorrencias = it->second.n_ocorrencias;
          i.num = it->first;
          i.posicao = it->second.posicao;
          lista.push_back(i);    
      }
      lista.sort();
      
      list<Inteiro>::iterator itr = lista.begin();
      
      for ( ; itr != lista.end(); itr++) {
          cout << itr->num << " " << itr->n_ocorrencias << endl;    
      }
    
    
    return 0;
}
