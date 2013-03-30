#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

#define MAX 10000
bool isprime[MAX];

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
    cria_crivo();
    
    int n_testes;
    
    cin >> n_testes;
    
    for (int i = 0; i < n_testes; i++) {
        int num;
        cin >> num;
        
        int pos = (num / 2) + 1;
        
        while (! isprime[pos]) ++pos;
        
        cout << pos << endl;
        
    }
    
    return 0;
}
