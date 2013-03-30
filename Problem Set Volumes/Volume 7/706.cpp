#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

char LCD[23][103];
int tam;
int linha;
int coluna;
int n_linhas;
int n_colunas;
int total_linhas;
int total_colunas;

void imprime_LCD()
{
     
     for (int i = 0; i < total_linhas; i++) {
         for (int j = 0; j < total_colunas; j++) {
             cout << LCD[i][j];
         }
         cout << endl;
     }
     cout << endl;
}

//imprime linha em branco
void branco()
{
     int c = coluna;
     
     for (int i = 0; i < n_colunas; i++) {
         LCD[linha][coluna] = ' ';
         ++coluna;
     }
     ++linha;
     coluna = c;
     
}


void horizontal()
{

     int c = coluna;
     LCD[linha][coluna] = ' ';
     ++coluna;
     
     for (int i = 0; i < tam; i++) {
         LCD[linha][coluna] = '-';
         ++coluna;
     }
     
     LCD[linha][coluna] = ' ';
     ++linha;
     coluna = c;     
     
}

void vertical_direita()
{
     
     int c = coluna;
     
     for (int i = 0; i < tam; i++) {
         
         int max = n_colunas-1;
         for (int j = 0; j < max; j++) {
             LCD[linha][coluna] = ' ';
             ++coluna;
         }
         LCD[linha][coluna] = '|';
         ++linha;
         coluna = c;
     }    
}

void vertical_esquerda()
{
     int c = coluna;  
     for (int i = 0; i < tam; i++) {
         
         LCD[linha][coluna] = '|';
         ++coluna;
         
         int max = n_colunas-1;
         for (int j = 0; j < max; j++) {
             LCD[linha][coluna] = ' ';
             ++coluna;
         }
         ++linha;
         coluna = c;
     }     
        
}

void duplo_vertical()
{
     int c = coluna;
     
     for (int i = 0; i < tam; i++) {
         LCD[linha][coluna] = '|';
         ++coluna;
         
         for (int j = 0; j < tam; j++) {
             LCD[linha][coluna] = ' ';
             ++coluna;
         }
         LCD[linha][coluna] = '|';
         ++linha;
         coluna = c;
     }
}

void coluna_branco()
{
     
     for (int i = 0; i < n_linhas; i++) {
         LCD[linha][coluna] = ' ';
         ++linha;
     }
}
     
     

void um ()
{    
     branco();
     vertical_direita();
     branco();
     vertical_direita();
     branco();
     
}

void dois()
{
     horizontal();
     vertical_direita();
     horizontal();
     vertical_esquerda();
     horizontal();
}

void tres()
{
     horizontal();
     vertical_direita();
     horizontal();
     vertical_direita();
     horizontal();
}

void quatro()
{
     branco();
     duplo_vertical();
     horizontal();
     vertical_direita();
     branco();
}

void cinco()
{
     horizontal();
     vertical_esquerda();
     horizontal();
     vertical_direita();
     horizontal();
}

void seis()
{
     horizontal();
     vertical_esquerda();
     horizontal();
     duplo_vertical();
     horizontal();
}

void sete()
{
     horizontal();
     vertical_direita();
     branco();
     vertical_direita();
     branco();
}

void oito()
{
     horizontal();
     duplo_vertical();
     horizontal();
     duplo_vertical();
     horizontal();
}

void nove()
{
     horizontal();
     duplo_vertical();
     horizontal();
     vertical_direita();
     horizontal();
}

void zero()
{
     horizontal();
     duplo_vertical();
     branco();
     duplo_vertical();
     horizontal();
}

int main()
{
    
    string num;
    //bool first_run = true;
    
    while (cin >> tam >> num) {
          
          if (tam == 0 && num == "0") {
                  break;
          }
          
          linha = 0;
          coluna = 0;
          n_linhas = 2*tam + 3;
          total_linhas = n_linhas;
          n_colunas = tam + 2;
          total_colunas = n_colunas * num.size() + num.size() - 1;
          
          /*
          if (! first_run) {
                cout << endl;
          }
          else {
               first_run = false;
          }*/
          
          int t = num.size();
          
          int i = 0;
          
          while (num[i] == '0') {
                ++i;
          }
          
          if (i == 1 && num.size() == 1) {
                i = 0;
          }
          
          for ( ; i < t; i++) {
              
              if (num[i] == '0') {
                 zero();
              }
              else if (num[i] == '1') {
                   um();
              }
              else if (num[i] == '2') {
                   dois();
              }
              else if (num[i] == '3') {
                   tres();
              }
              else if (num[i] == '4') {
                   quatro();
              }
              else if (num[i] == '5') {
                   cinco();
              }
              else if (num[i] == '6') {
                   seis();
              }
              else if (num[i] == '7') {
                   sete();
              }
              else if (num[i] == '8') {
                   oito();
              }
              else if (num[i] == '9') {
                   nove();
              }
              coluna += n_colunas;
              linha = 0;
              
              if (i < t - 1) {
                  //++coluna;
                  coluna_branco();
                  linha = 0;
                  ++coluna;
              }
              //cout << coluna << endl;
              //cout << linha << endl;
              //imprime_LCD();
          }
          imprime_LCD();
          
    }
          
          
    return 0;

}
