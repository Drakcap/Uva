#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define MAX 1000010
bool isprime[MAX];

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

int inverso (int n)
{
    
    vector<int> digitos;   
    
    while (n > 0) {
          
          int d = n % 10;
          digitos.push_back(d);
          n /= 10;
    }
    
    int res = 0;
    int mult = 1;
    int tam = digitos.size();
    
    for (int i = tam-1; i >= 0; --i) {
        res += digitos[i] * mult;
        mult *= 10;
    }
    
    return res;
    
}


int main()
{
    
    int n;
    cria_crivo();
    
    while (cin >> n) {
          
          if (!isprime[n]) {
             cout << n << " is not prime." << endl;
          }
          else {
               int inv = inverso(n);
               
               if (inv != n && isprime[inv]) {
                  cout << n << " is emirp." << endl;
               }
               else {
                    cout << n << " is prime." << endl;
               }
          }
    }
    
    
    
    return 0;
}
