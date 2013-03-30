#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


struct No {
       
       vector<int> ligacoes;
       bool visited;
       bool cor;
       int num;     
};

No nos[200];
int n, l;

bool dfs(No& no, bool cor)
{
     
     no.visited = true;
     no.cor = cor;
     
     int n_lig = no.ligacoes.size();
     
     for (int i = 0; i < n_lig; i++) {
         if (! nos[no.ligacoes[i]].visited) {
            bool nova_cor = ! cor;
            return dfs(nos[no.ligacoes[i]], nova_cor);      
         }
         if (nos[no.ligacoes[i]].cor == cor) {
              //cout << no.ligacoes[i] << " " << no.num << endl;
              return false;
         }
         
     }
     
     return true;
}


int main()
{
    
    while (cin >> n && n != 0) {
          
          cin >> l;
          
          for (int i = 0; i < n; i++) {
              nos[i].ligacoes.clear();
              nos[i].visited = false;
              nos[i].num = i;
          }
          
          //constroi o grafo
          for (int i = 0; i < l; i++) {
              int n1, n2;
              cin >> n1 >> n2;

              nos[n1].ligacoes.push_back(n2);
              nos[n2].ligacoes.push_back(n1);    
          }
          
          cout << (dfs(nos[0], true) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;      
          
          /*
          for (int i = 0; i < nos[1].ligacoes.size(); i++) {
              cout << nos[1].ligacoes[i] << endl;
          }*/
          
          
    }
    
    
    
    
    return 0;
}
