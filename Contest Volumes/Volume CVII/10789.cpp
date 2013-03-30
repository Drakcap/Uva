#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

#define MAX 2001
bool isprime[MAX];

int minusculas[26];
int maiusculas[26];
int numeros[10];

char palavra[2001];


void cria_crivo()
{
     
     int i, j;
     double raiz;
     
     memset(isprime,true,sizeof(isprime));
     isprime[0] = false; isprime[1] = false;
     
     raiz = sqrt(MAX);
     
     for (i = 2; i <= raiz; i++) {
         if (isprime[i]) {
            for (j = 2; j* i < MAX; j++) {
                isprime[i*j] = false;
            }
         }
     }
}

int main()
{
    
    int n_testes;
    cin >> n_testes;
    cria_crivo();
    
    for (int i = 0; i < n_testes; i++) {
    
        for (int j = 0; j < 26; j++) {
            minusculas[j] = 0;
            maiusculas[j] = 0;
        }
        
        for (int j = 0; j < 10; j++) {
            numeros[j] = 0;
        }
        
        cin >> palavra;
        
        int tam = strlen(palavra);
        
        for (int j = 0; j < tam; j++) {
            
            if (palavra[j] >= 'a') {
               ++minusculas[palavra[j]-'a'];               
            }
            else if (palavra[j] >= 'A') {
                 ++maiusculas[palavra[j]-'A'];
            }
            else {
                 ++numeros[palavra[j] - '0'];
            }    
            
        }
        
        cout << "Case " << i + 1 << ": ";
        bool empty = true;
        
        for (int j = 0; j < 10; j++) {
            if (isprime[numeros[j]]) {
               cout << (char) (j + '0');
               empty = false;
            }
        }
        
        for (int j = 0; j < 26; j++) {
            if (isprime[maiusculas[j]]) {
               cout << (char) (j + 'A');
               empty = false;
            }
        }
        
        
        for (int j = 0; j < 26; j++) {
            if (isprime[minusculas[j]]) {
               cout << (char) (j + 'a');
               empty = false;
            }
        }
        
        //cout << maiusculas[2] << endl;
        if (empty) {
           cout << "empty";
        }
        cout << endl;
        
    }
    
    
    return 0;   
}
