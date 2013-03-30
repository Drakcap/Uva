#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <list>
using namespace std;


#define ERRO 0.00000000001

struct Ponto {
       
       int x;
       int y;
};

struct Recta {

       Ponto baixo;
       Ponto alto;
       double declive;
       int menor_x;
       int maior_x;
       int num;
       
       Recta (int &x1, int &y1, int &x2, int &y2) {
       
             if (y1 > y2) {
                swap(x1,x2);
                swap(y1,y2);       
             }
             
             baixo.x = x1;
             baixo.y = y1;
             alto.x = x2;
             alto.y = y2;
             
             declive = ((double) y1 - (double) y2) / ((double) x1 - (double) x2);
             
             if (x1 < x2) {
                    menor_x = x1;
                    maior_x = x2;
             }
             else {
                  menor_x = x2;
                  maior_x = x1;
             }      
       }       
       
};

list<Recta> rectas;
        

bool colide (Ponto &p, Recta &r)
{
     
     //ponto esta acima ou abaixo da recta
     if (p.y <= r.baixo.y || p.y > r.alto.y) {
             return false;
     }
     
     //ponto esta ao lado da recta
     if (p.x < r.menor_x || p.x > r.maior_x) {
             //cout << "aki" << endl;
             return false;
     }
     
     double novo_declive = ((double) p.y - (double) r.baixo.y) / ((double) p.x - (double) r.baixo.x);
     
     //teste ao declive
     if (fabs(novo_declive - r.declive) < ERRO) {
        return true;
     }
     
     double y_recta = - r.declive * (r.baixo.x - p.x) + r.baixo.y;
     
     if (y_recta < p.y && y_recta > (p.y - 1)) {
        return true;
     }
     
     //cout << novo_declive << " " << r.declive << endl;
     return false; 
     
     
     
     
}

void actualiza (Ponto &p, Recta &r)
{
     p.x = r.baixo.x;
     p.y = r.baixo.y;
}

void processa_ponto (Ponto &p)
{
     while (p.y > 0) {
           
         bool colidiu = false;  
         list<Recta>::iterator it = rectas.begin();
         
         for ( ; it != rectas.end(); it++) {
             if (colide(p, *it)) {
                actualiza(p, *it);
                colidiu = true;
                //cout << it->num << endl;
                break;
             }    
         }
         
         if (! colidiu) {
               --p.y;
         }
     }
     
     
}



int main()
{
    
    //int n_tests;
    
    //cin >> n_tests;
    
    //bool first_run = true;
    
    //for ( ; n_tests; --n_tests) {
        
        //if (! first_run) cout << endl;
        //else first_run = false;
        
        int n_rectas;
        cin >> n_rectas;
        rectas.clear();
        
        int num = 1;
        
        for ( ; n_rectas; --n_rectas)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            
            Recta r(x1,y1,x2,y2);
            r.num = num++;
            
            rectas.push_back(r);
            
        }
        
        int n_pontos;
        
        cin >> n_pontos;
        
        for ( ; n_pontos; --n_pontos) {
            Ponto p;
            cin >> p.x >> p.y;    
            
            processa_ponto(p);
            //cout << p.x << " " << p.y << endl;
            cout << p.x << endl;
        }
        
        
    //}
    
    
    
    return 0;
}
