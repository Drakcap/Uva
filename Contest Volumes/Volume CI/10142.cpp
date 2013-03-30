#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

struct Candidato {
       
       string nome;
       int votacao;
       int posicao[1000];  //posicao do candidato no boletim
       bool activo;
};

struct Boletim {
       
       vector<int> votacoes;
};

Candidato candidatos[21];
Boletim boletins[1001];
int n_boletins;
int limiar_vitoria;
int n_candidatos;
int candidatos_activos;


void actualiza_boletim (int boletim, int pos)
{
     
     boletins[boletim].votacoes.erase(boletins[boletim].votacoes.begin() + pos);
     
     int max = candidatos_activos - 1;
     
     for (int i = pos; i < max; i++) {
             --candidatos[boletins[boletim].votacoes[i]].posicao[boletim];    
     }
     
     if (pos == 0) {
             ++candidatos[boletins[boletim].votacoes[0]].votacao;
     }     
     
     
}

void elimina_candidato (int candidato)
{
     for (int i = 0; i < n_boletins; i++) {
         actualiza_boletim(i, candidatos[candidato].posicao[i]);
     }     
     
     candidatos[candidato].activo = false;
     --candidatos_activos;
     
}

bool fim_votacao (list<int>& max_candidatos, list<int>& min_candidatos)
{
    
    int max = 0, min = -1;
    
    for (int i = 1; i <= n_candidatos; i++) {
        
        //candidato tem de estar no activo
        if (candidatos[i].activo) {
                                  
            if (candidatos[i].votacao > max) {
               max = candidatos[i].votacao;
               max_candidatos.clear();
               max_candidatos.push_back(i);                          
            }
            else if (candidatos[i].votacao == max) {
               max_candidatos.push_back(i);                          
            }
            
            if (candidatos[i].votacao < min || min == -1) {
                min = candidatos[i].votacao;
                min_candidatos.clear();                         
                min_candidatos.push_back(i);                      
            }
            else if (candidatos[i].votacao == min) {
               min_candidatos.push_back(i);
            }
        }
          
    }
  
    if ((int)max_candidatos.size() == candidatos_activos) {
       return true;
    }
    
    if (max_candidatos.size() > 1) {
       return false;
    }
    
    if (max < limiar_vitoria) {
       return false;
    }
    
    return true;
    
}

int main()
{
    
    int n_tests;
    string linha;
    bool first_run = true;
    
    getline(cin,linha);
    istringstream stream(linha);
    
    stream >> n_tests;
    getline(cin,linha);
    //cout << linha << endl;
    
    for ( ; n_tests; --n_tests) {
        
        if (! first_run) {
              cout << endl;
        }
        else {
             first_run = false;
        }
        
        getline(cin,linha);
        //cout << linha << endl;
        istringstream s1(linha);
        
        s1 >> n_candidatos;
        candidatos_activos = n_candidatos;
        
        for (int i = 0; i < n_candidatos; i++) {
            getline(cin,linha);
            candidatos[i+1].nome = linha;
            candidatos[i+1].votacao = 0;
            candidatos[i+1].activo = true;
        }
        
        n_boletins = 0;
    
        
        //le os boletins
        while (getline(cin,linha)) {
              
              if (linha == "") {
                 break;
              }
              
              boletins[n_boletins].votacoes.clear();
                    
              istringstream s2(linha);
              //cout << linha << endl;
              int candidato;
              s2 >> candidato;
              candidatos[candidato].posicao[n_boletins] = 0;
              ++candidatos[candidato].votacao;
              boletins[n_boletins].votacoes.push_back(candidato);
              
              
              for (int i = 1; i < n_candidatos; i++) {
                  //int candidato;
                  s2 >> candidato;
                  candidatos[candidato].posicao[n_boletins] = i;
                  boletins[n_boletins].votacoes.push_back(candidato);
              }
              
              
              ++n_boletins;
              
              /*
              cout << "boletim: " << n_boletins << endl;
              cout << candidatos[1].votacao << endl;
              cout << candidatos[2].votacao << endl;
              cout << candidatos[3].votacao << endl;*/
        }
        

        
        limiar_vitoria = (n_boletins +1)/2;
        
        
        list<int> max_candidatos;
        list<int> min_candidatos;
        
        //cout << candidatos[1].votacao << endl;
        //cout << candidatos[2].votacao << endl;
        //cout << candidatos[3].votacao << endl;
        
        while (! fim_votacao(max_candidatos, min_candidatos) ) {
              
              list<int>::iterator it = min_candidatos.begin();
              
              for ( ; it != min_candidatos.end(); it++) {
                  elimina_candidato(*it);    
              }
              
              //cout << min_candidatos.size() << endl;
              //cout << max_candidatos.size() << endl;
              min_candidatos.clear();
              max_candidatos.clear();
        }
        
        list<int>::iterator it = max_candidatos.begin();
        
        for ( ; it != max_candidatos.end(); it++) {
            cout << candidatos[*it].nome << endl;
        }
        
        //cout << candidatos[1].votacao << endl;
        //cout << candidatos[2].votacao << endl;
        //cout << candidatos[3].votacao << endl;
        //cout << n_tests << endl;
        //cout << n_candidatos << endl;
        //cout << n_boletins;
        
            
        
        
        
        
        
    }
    
    
    
    
    
    
    return 0;
}
