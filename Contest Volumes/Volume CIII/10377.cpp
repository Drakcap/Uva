#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define N 0
#define E 1
#define S 2
#define W 3

char matriz[60][60];
int linhas, colunas;
int pos_linha, pos_coluna;
int o = N;

enum Direccao { R = 0, L = 1 };

void muda_orientacao (Direccao &d)
{
     
     if (d == R) {
     
        if (o == W) {
              o = N;
        }
        else {
             ++o;
        }      
           
     }
     
     else if (d == L) {
          
        if (o == N) {
              o = W;
        }
        else {
             --o;
        }  
          
     }
}


void avanca()
{
     
     bool fora_dimensoes = (pos_linha <= 1) || (pos_coluna <= 1) || (pos_linha > linhas) || (pos_coluna > colunas);
     
     if (o == N) {
     
        if (fora_dimensoes) {
           --pos_linha;
        }
        else if (matriz[pos_linha-2][pos_coluna-1] == ' ') {
             --pos_linha;
        }      
           
     }
     
     else if (o == S) {
          
        if (fora_dimensoes) {
           ++pos_linha;
        }
        //ve na posicao abaixo
        else if (matriz[pos_linha][pos_coluna-1] == ' ') {
             ++pos_linha;
        }             
          
     }
     
     
     else if (o == W) {
          
        if (fora_dimensoes) {
           --pos_coluna;
        }
        //ve na posicao 'a esquerda
        else if (matriz[pos_linha-1][pos_coluna-2] == ' ') {
             --pos_coluna;
        }             
          
     }      
     
     else if (o == E) {
          
        if (fora_dimensoes) {
           ++pos_coluna;
        }
        //ve na posicao 'a direita
        else if (matriz[pos_linha-1][pos_coluna] == ' ') {
             ++pos_coluna;
        }             
          
     }     
     
     
     
}

int main()
{
    
    int n_tests;
    bool first_run = true;
    
    scanf("%d", &n_tests);
    
    for ( ; n_tests; --n_tests) {
        
        if (! first_run) {
              cout << endl;
        }
        else {
             first_run = false;
        }
        
        o = N;
    
        scanf("%d %d\n", &linhas, &colunas);
        
        //cin.ignore('\n');   
    
        for (int i = 0; i < linhas; i++) {
            gets(matriz[i]);
        }
        
        scanf("%d %d", &pos_linha, &pos_coluna);   
        
        /*
        for (int i= 0; i < linhas; i++) {
            cout << matriz[i] << endl;
        }*/
        
        string instrucoes;
        
        cin >> instrucoes;
        //cout << instrucoes << endl;
        
        while (instrucoes[instrucoes.size()-1] != 'Q') {
              string temp;
              cin >> temp;
              instrucoes += temp;
              //cout << instrucoes << endl;
        }
        
        int tam = instrucoes.size();
        --tam;
        
        for (int i = 0; i < tam; i++) {
            
            if (instrucoes[i] == 'R') {
               Direccao r = R;
               muda_orientacao(r);                  
            } 
            else if (instrucoes[i] == 'L') {
                 Direccao l = L;
                 muda_orientacao(l);
            }
            else {
                 avanca();
               /*  cout << pos_linha << " " << pos_coluna << " ";
                 
                 
        if (o == N) {
              cout << "N";
        }
        else if (o == S) {
             cout << "S";
        }
        else if (o == W) {
             cout << "W";
        }
        else if (o == E) {
             cout << "E";
        }
        cout << endl; */
        
                         
            }
        }
        
        cout << pos_linha << " " << pos_coluna << " ";
        
        if (o == N) {
              cout << "N";
        }
        else if (o == S) {
             cout << "S";
        }
        else if (o == W) {
             cout << "W";
        }
        else if (o == E) {
             cout << "E";
        }
        cout << endl; 
        
        
    }
    
    
    
    return 0;
}
