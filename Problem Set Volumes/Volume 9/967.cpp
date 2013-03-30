#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

int circulares[42] = {113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 993319, 999331};


/*
#define MAX 1000010
bool isprime[MAX];
bool circularprime[MAX];
bool calculado[MAX];
//int contador = 0;
vector<int> circulares;

void cria_crivo() {
     
     int i,j;
     double raiz;
     
     memset(isprime, true, sizeof(isprime));
     isprime[0] = false; isprime[1] = false;
     
     raiz = sqrt(MAX);
     
     for (i = 2; i<=raiz;i++)
         if(isprime[i])
            for (j = 2; j*i < MAX; j++)
                isprime[i*j] = false;
                
}

void troca_digitos (vector<int> &digitos)
{
     int temp = digitos[0];
     digitos.erase(digitos.begin());
     digitos.push_back(temp);
}

int faz_numero (vector<int> &digitos)
{
    int num = 0;
    int mult = 1;
    int n_digitos = digitos.size();
    
    for (int i = 0; i < n_digitos; i++) {
        num += (mult * digitos[i]);
        mult *= 10;
    }
    
    return num;
    
}

void calcula (int num)
{
     
     vector<int> digitos;
     vector<int> permutacoes;
     permutacoes.push_back(num);
     
     bool flag = isprime[num];
     
     if (! flag) {
           return;
     }
     
     
     while (num != 0) {
           digitos.push_back(num % 10);
           num /= 10;
     }
     
     int n_digitos = digitos.size();     
     int max = n_digitos-1;
     
     troca_digitos(digitos);
     
     
     for (int i = 0; i < max; i++) {
         int n = faz_numero(digitos);
         permutacoes.push_back(n);
         flag = isprime[n];
         
         if (! flag) {
               //cout << n << endl;
               return;
         }
         
         troca_digitos(digitos);
     }
     
     
     
     max = permutacoes.size();
     
     
     for (int i = 0; i < max; i++) {
         circulares.push_back(permutacoes[i]);
         calculado[permutacoes[i]] = true;
          
     }
     
     
}*/


int main()
{
    
    /*
    cria_crivo();
    memset(calculado, false, sizeof(isprime));
    
    
    for (int i = 100; i < MAX; i++) {
    
        if (! calculado[i] ) {
           calcula(i);      
        }    
        
    }
    
    sort(circulares.begin(), circulares.end());
    
    cout << "{ ";
    
    for (int i = 0; i < 42; i++) {
        cout << circulares[i] << ", ";
    }
    
    cout << "}";*/
    
    
    int min, max;
    
    while (cin >> min && min != -1)
    {
          cin >> max;
          
          if (min > max) {
             swap(min,max);
          }      
          
          int n_nums = 0;
          
          for (int i = 0; i < 42; i++) {
              if (circulares[i] <= max && circulares[i] >= min) {
                 ++n_nums;
              }
              else if (circulares[i] > max) {
                   break;
              }
          }
          
          if (n_nums == 0) {
             cout << "No Circular Primes.";
          }
          else if (n_nums == 1) {
               cout << "1 Circular Prime.";     
          }
          else {
               cout << n_nums << " Circular Primes.";
          }
          cout << endl;
          
          
    }
    
    
    return 0;
}
