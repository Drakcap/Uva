#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


struct Posicao {
       
       int x;
       int y;
       
       //int entradas;
       
       bool operator==(const Posicao &pos) const
       {
            return (x == pos.x && y == pos.y);
       }
       
       bool operator<(const Posicao &pos) const
       {
            if (pos.x != x) {
               return (x < pos.x);
            }
            else {
                 return (y < pos.y);     
            }
              
       }
};

struct Obra {

       bool N;
       bool E;     
};

Obra obras[31][31];
long long int cidade[31][31];

/*
int procura_obra(const Obra &obra, const int inicio, const int fim)
{
     if (! (inicio <= fim) ) return -1;
     if (inicio < 0) return -1;

     unsigned meio = inicio + (fim-inicio) / 2;
     
     if (obras[meio] < obra) {
        return procura_obra(obra, meio+1, fim);
     }
     
     else if (obra < obras[meio]) {
          return procura_obra(obra, inicio, meio-1);
     }
     
     else return meio;
}*/

//nao verifica os limites
/*
Posicao nova_posicao (Posicao& pos, char dir)
{
        
        Posicao p;
        
        if (dir == 'N') {
                p.x = pos.x;
                p.y = pos.y + 1;
        }
        else if (dir == 'E') {
             p.x = pos.x + 1;
             p.y = pos.y;
        }
        else if (dir == 'W') {
             p.x = pos.x - 1;
             p.y = pos.y;
        }
        else if (dir == 'S') {
             p.x = pos.x;
             p.y = pos.y - 1;
        }
        
        return p;
        
}*/


int main()
{
    
    int n_tests;
    cin >> n_tests;
    
    for ( ; n_tests; --n_tests) {
    
        int dimensao;
        cin >> dimensao;
        
        Posicao inicial, final;
        cin >> inicial.x >> inicial.y >> final.x >> final.y;
        
        for (int i = inicial.x; i <= final.x; i++) {
            for (int j = inicial.y; j <= final.y; j++) {
                obras[i][j].N = false;
                obras[i][j].E = false;
                cidade[i][j] = 0;
            }
        }
        
        long long int num_obras;
        cin >> num_obras;
        
        for (int i = 0; i < num_obras; i++) {
             int x, y;
             cin >> x >> y;
             char dir;
             cin >> dir;
             
             if (dir == 'N') {
                obras[x][y].N = true;
             }
             else if (dir == 'E') {
                  obras[x][y].E = true;  
             }
             else if (dir == 'S') {
                  if (y > 1) {
                        obras[x][y-1].N = true;
                  }
             }
             else if (dir == 'W') {
                  if (x > 1) {
                        obras[x-1][y].E = true;
                  }     
             }

        }
        
        cidade[inicial.x][inicial.y] = 1;
        
        for (int j = inicial.y; j < final.y; j++) { 
            for (int i = inicial.x; i < final.x; i++) {
               
               if (! obras[i][j].N) {
                     cidade[i][j+1] += cidade[i][j];
               }
               
               if (! obras[i][j].E) {
                     cidade[i+1][j] += cidade[i][j];
               }       
            }
            //ultima coluna
            if (! obras[final.x][j].N) {
               cidade[final.x][j+1] += cidade[final.x][j];      
            }
        }
        
        //ultima linha
        for (int i = inicial.x; i < final.x; i++) {
            if (! obras[i][final.y].E) {
               cidade[i+1][final.y] += cidade[i][final.y];
            }          
        }
        
        //ultima posicao
        /*if (! obras[final.x-1][final.y].E) {
              cidade[final.x][final.y] += cidade[final.x-1][final.y];
        }*/
        
        /*
        queue<Posicao> fila;
        fila.push(inicial);
        
        while (! fila.empty()) {
        
              Posicao pos = fila.front();
              fila.pop();
              
              if (pos == final) {
                      ++maneiras;
                      continue;
              }
              
              //posicao a norte
              if (pos.y < dimensao && pos.y < final.y && !obras[pos.x][pos.y].N) {
                        Posicao nova_pos;
                        nova_pos.x = pos.x;
                        nova_pos.y = pos.y+1;
                        fila.push(nova_pos);              
              }
              
              //posicao a este
              if (pos.x < dimensao && pos.x < final.x && !obras[pos.x][pos.y].E) {
                 Posicao nova_pos;
                 nova_pos.x = pos.x+1;
                 nova_pos.y = pos.y;
                 fila.push(nova_pos);
              }       
              
        }*/
        
        /*
        for (int i = 0; i < num_obras; i++) {
            cout << obras[i].x << " " << obras[i].y << endl;
        }*/
        
        cout << cidade[final.x][final.y] << endl;       
        
    }
    
    
    return 0;
}
