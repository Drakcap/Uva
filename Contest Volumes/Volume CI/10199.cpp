#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


struct No {
       
       int num;
       string nome;
       int low;
       int pai;
       bool visited;
       bool root;
       bool is_art;
       list<int> ligacoes;
       
       bool operator <(const No& no) const
       {
            return (nome < no.nome);
       }
       
};

No nos[101];
list<string> cameras;
int counter = 1;
int n_filhos = 0;

/*
int compare(const void *a,const void *b) {
    
    No c,d;
    
    c=*(struct No*)a;
    d=*(struct No*)b;
    
    if (c.nome < d.nome) {
       return -1;
    }
    if (c.nome > d.nome) {
       return 1;
    }
    
    return 0;
    
}*/

int procura_no(const string &palavra, const int inicio, const int fim)
{
     if (! (inicio <= fim) )  {return false;}
     if (inicio < 0) {return false;}

     unsigned meio = inicio + (fim-inicio) / 2;
     
     if (palavra > nos[meio].nome) {
        return procura_no(palavra, meio+1, fim);
     }
     
     else if (palavra < nos[meio].nome) {
          return procura_no(palavra, inicio, meio-1);
     }
     
     else return meio;
}

void find_art (No& no)
{
     no.visited = true;
     no.low = no.num = counter++;
     
     list<int>::iterator it = no.ligacoes.begin();
     
     for ( ; it != no.ligacoes.end(); it++) {
         //cout << no.nome << " " << nos[*it].nome << endl;
         if (! nos[*it].visited) {
               nos[*it].pai = no.num;
               
               if (no.root) ++n_filhos;
               
               find_art(nos[*it]);
               
               if (nos[*it].low >= no.num) {
                  //cout << "aki" << endl;
                  //cout << no.nome << endl;
                  no.is_art = true;                 
               }
               no.low = (no.low < nos[*it].low ? no.low : nos[*it].low);
         }
         else if (no.pai != nos[*it].num) {
              no.low = (no.low < nos[*it].num ? no.low : nos[*it].num);     
         }       
         
     }
     
     if (no.root == true && no.is_art == true && n_filhos == 1) {
             //cout << "aki" << endl << no.nome << endl;
     }
     
     else if (no.is_art) {
        cameras.push_back(no.nome);
     }     
     
     
}


int main()
{
    
    int map = 1;
    bool first_run = true;
    int n_nos;
    
    while (cin >> n_nos && n_nos != 0)
    {
          
          if (! first_run) {
                cout << endl;
          }
          else {
               first_run = false;
          }
          
          counter = 1;
          cameras.clear();
          n_filhos = 0;
          
          for (int i = 0; i < n_nos; i++) {
              cin >> nos[i].nome;
              nos[i].visited = false;
              nos[i].root = false;
              nos[i].is_art = false;
              nos[i].ligacoes.clear();    
          }
          
          sort(nos, nos + n_nos);
          
          //for (int i = 0; i < n_nos; i++) cout << nos[i].nome << endl;
          
          int n_ligacoes;
          cin >> n_ligacoes;
          //cout << n_ligacoes << endl;
          
          //constroi o grafo
          for (int i = 0; i < n_ligacoes; i++) {
              string local1, local2;
              cin >> local1 >> local2;
              //cout << local1 << " " << local2 << endl;
              int pos1 = procura_no(local1, 0, n_nos-1);
              int pos2 = procura_no(local2, 0, n_nos-1);
              nos[pos1].ligacoes.push_back(pos2);
              nos[pos2].ligacoes.push_back(pos1);    
          }
          
          /*
          for (int i = 0; i < n_nos; i++) {
              cout << "ligacoes a: " << nos[i].nome << endl;
              list<int>::iterator it = nos[i].ligacoes.begin();
              for ( ; it != nos[i].ligacoes.end(); it++) {
                  cout << nos[*it].nome << endl;
              }
          }*/
          
          
          for (int i = 0; i < n_nos; i++) {
              if (! nos[i].visited) {
                    nos[i].pai = -1;
                    nos[i].root = true;
                    n_filhos = 0;
                    //cout << nos[i].nome << endl;
                    find_art(nos[i]);
              }
          }
          
          /*
          for (int i = 0; i < n_nos; i++) {
              cout << nos[i].nome << endl;
              cout << nos[i].num << endl;
              cout << nos[i].low << endl;
              cout << nos[i].pai << endl;
          } */      
          
          cameras.sort();
          
          cout << "City map #" << map++ << ": " << cameras.size() << " camera(s) found" << endl;
          list<string>::iterator it = cameras.begin();
          
          for ( ; it != cameras.end(); it++) {
              cout << *it << endl;
          }
          
          //cout << "aki :X" << endl;
    }
    
    
    
    
    
    return 0;
}


