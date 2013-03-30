#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <string>
#include <sstream>
using namespace std;


struct No {
  
       int num;
       int low;
       int pai;
       bool visitado;
       bool is_art;     
       list<int> ligacoes;
       bool is_lig[101];
       
};

//flags para a raiz
//bool is_art = false;
int n_filhos = 0;

int counter = 1;
int n_nos;
int n_ligacoes;
int n_articulacao = 0;

No nos[101];

void find_art (int no)
{
     
     nos[no].visitado = true;
     nos[no].num = nos[no].low = counter++;
     
     list<int>::iterator it = nos[no].ligacoes.begin();
     
     for ( ; it != nos[no].ligacoes.end(); it++) {
           
           if (! nos[*it].visitado) {
                 nos[*it].pai = nos[no].num;
                 
                 if (no == 1) {
                        ++n_filhos;
                 }
                 
                 find_art(*it);
                 
                 //encontrou ponto de articulacao
                 if (nos[*it].low >= nos[no].num) {
                    nos[no].is_art = true;
                    //++n_articulacao;
                    //cout << *it << endl;
                    //cout << "No: " << no << endl;
                    
                    /*if (no == 1) {
                           is_art = true;
                    } */              
                 }
                 nos[no].low = (nos[no].low < nos[*it].low ? nos[no].low : nos[*it].low); 
           }
           
           else if (nos[no].pai != nos[*it].num) {
                nos[no].low = (nos[no].low < nos[*it].num ? nos[no].low : nos[*it].num);          
           }
         
         
         
     }
     
     if (no == 1 && nos[1].is_art && n_filhos == 1) {
             
     }
     
     else if (nos[no].is_art) {
        ++n_articulacao;
     }
     
        
}

int main()
{
    string linha;
    
    while (getline(cin,linha)) {
          
          if (linha == "") continue;
          
          istringstream l(linha);
          l >> n_nos; 
          
          if (n_nos == 0) {
             break;
          }
          
          n_articulacao = 0;
          n_filhos = 0;
          counter = 1;
          
        for (int i = 0; i < n_nos; i++) {
            //nos[i+1].num = i+1;
            nos[i+1].visitado = false;
            //nos[i+1].low = i+1;
            
            for (int j = 0; j < n_nos; j++) {
                nos[i+1].is_lig[j+1] = false;
            }
            nos[i+1].ligacoes.clear();
            nos[i+1].is_art = false;
            //nos[i+1].pai = -1;
        }
        
        
        
        while (getline(cin,linha)) {
              if (linha == "") continue;
              int no;
              istringstream n(linha);
              
              n >> no;
              
              if (no == 0) {
                 break;
              }
              
              while (! n.eof()) {
                    int lig;
                    n >> lig;
                    if (! nos[lig].is_lig[no]) {
                       nos[lig].ligacoes.push_back(no);
                       nos[no].ligacoes.push_back(lig);
                       nos[lig].is_lig[no] = true;
                       nos[no].is_lig[lig] = true;
                    }      
              }
        }
        
        nos[1].pai = -1; //raiz
        find_art(1);
        
        
        
        
        /*
        cout << "ver ligacoes" << endl;
        for (int i = 1; i < 6; i++) {
            cout << nos[5].is_lig[i] << endl;
        }*/
        
        cout << n_articulacao << endl;          
          
    }
    
    
    
    return 0;
}
