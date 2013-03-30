#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;

long double estudantes[1001];
int n_estudantes = 0; 

int main()
{
    
    while (cin >> n_estudantes && n_estudantes != 0)
    {
          long double soma = 0;
          
          for (int i = 0; i < n_estudantes; i++) {
              cin >> estudantes[i];
              soma += estudantes[i];
          }
          
          long double media = soma / (long double) n_estudantes;
          
          long double mult = media * 100;
          long double acima = ceil(mult);
          long double abaixo = floor(mult);
          acima /= 100;
          abaixo /= 100;
          
          //cout << acima << endl;
          //cout << abaixo << endl;
          
          long double diferenca = 0;
          long double resposta = 0;
          
          for (int i = 0; i < n_estudantes; i++) {
              if (estudantes[i] > acima) {
                     long double diff = estudantes[i] - acima;
                     resposta += diff;
                     diferenca += diff;
              }
              else if (estudantes[i] < abaixo) {
                   long double diff = abaixo - estudantes[i];
                   diferenca -= diff;
              }
              
          }
          
          if (diferenca < 0) {
             resposta -= diferenca;
          }
          
          cout.setf(ios::fixed);
          cout << "$" << setprecision(2) << resposta << endl;
          
          
          
    }
    

    
    
    return 0;
}
