#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>
#include <sstream>
using namespace std;

struct No {
       
       bool visited;
       list<int> ligacoes;
};

No nos[30];
int n_nos;
int resposta;


void dfs(No& no)
{
     
     no.visited = true;
     
     list<int>::iterator it = no.ligacoes.begin();
     
     for ( ; it != no.ligacoes.end(); it++) {
         if (! nos[*it].visited) {
               //cout << "a visitar: " << *it << endl;
               dfs(nos[*it]);    
         }
     }
     
     
     
}


int main()
{
    int n_tests;
    
    bool first_run = true;
    
    string linha;
    getline(cin,linha);
    istringstream i(linha);
    
    i >> n_tests;
    
    getline(cin,linha); //le linha em branco
    
    for ( ; n_tests; --n_tests)
    {
        
        if (! first_run) {
              cout << endl;
        }
        else {
             first_run = false;
        }
        
        getline(cin, linha); //le o no maximo
        n_nos = linha[0] - 'A' + 1;
        resposta = 0;
        
        for (int i = 0; i < n_nos; i++) {
            nos[i].visited = false;
            nos[i].ligacoes.clear();
        }
        
        while (getline(cin,linha) && linha != "") {
              istringstream istr(linha);
              string temp;
              istr >> temp;
              int no1 = temp[0] - 'A';
              int no2 = temp[1] - 'A';
              //cout << linha << endl;      
              nos[no1].ligacoes.push_back(no2);
              nos[no2].ligacoes.push_back(no1);
        }
        
        for (int i = 0; i < n_nos; i++) {
            if (! nos[i].visited) {
                  ++resposta;
                  dfs(nos[i]);
            }
        }
        
        cout << resposta << endl;
        
    }    
    
    
    
    
    
    
}
