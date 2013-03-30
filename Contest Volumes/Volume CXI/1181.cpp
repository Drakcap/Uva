#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

long long unsigned factorial (unsigned n)
{
         long long unsigned acumula = 1;
         
         while (n > 0) {
               
               acumula *= n;
               n--;
         }
         
         return acumula;
}

long long unsigned combinacoes (const unsigned n, const unsigned r)
{
         return (factorial(n) / (factorial(r)* factorial(n-r)));
         
}


int main()
{
    cout.setf(ios::fixed);
    unsigned N, r;
    unsigned c = 1;
    
    cin >> N >> r;
    
    while (N != 0 || r != 0) {  
          
          cout << "Case " << c << ":" << endl;
          c++;
          
          long double *probabilidades = new long double[N];
          long double casos_possiveis = 0;
          long double *casos_favoraveis = new long double[N];
          
          for (unsigned i = 0; i < N; i++) {
              casos_favoraveis[i] = 0;
          }
          
          for (unsigned i = 0; i < N; i++) {
              cin >> probabilidades[i];
          }
          
          
          
          if (r == N) {
               
               for (unsigned i = 0; i < N; i++) {
                   cout << setprecision(6) << 1.000000 << endl;
                }
          }
          
          else if (r == 0) {
               
               for (unsigned i = 0; i < N; i++) {
                   cout << setprecision(6) << 0.000000 << endl;
               }
          }
          
          else {
               
               
               long long unsigned n_ciclos = combinacoes(N,r);
               vector<unsigned> possibilidades;
                
               for (unsigned i = 0; i < N; i++) {
                   
                   if (i < (N - r)) {
                          possibilidades.push_back(0);
                    }
                    
                   else {
                         possibilidades.push_back(1);
                    }
                } //end for
                
                for (unsigned i = 0; i < n_ciclos; i++) {
                    
                    long double temp = 1;
                    
                    for (unsigned j = 0; j < N; j++) {
                        
                        if (possibilidades[j] == 0) {
                           temp *= (1 - probabilidades[j]);
                        }
                        
                        else {
                             temp *= probabilidades[j];
                        }
                    }
                    
                    for (unsigned j = 0; j < N; j++) {
                        if (possibilidades[j] == 1) {
                           casos_favoraveis[j] += temp;
                        }
                    }
                    
                    next_permutation(possibilidades.begin(), possibilidades.end());  
                    
                    casos_possiveis += temp;
                } //end for (unsigned i = 0; i < n_ciclos; i++) {
                      
                        
                for (unsigned i = 0; i < N; i++) {
                    cout << setprecision(6) << casos_favoraveis[i] / casos_possiveis << endl;
                }
                
          }//end else
          cin >> N >> r;
          
    }//end while
}
                
                
          
