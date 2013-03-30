#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int solucao[14] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};

int k;

bool serve (vector<bool> circulo, int m)
{
     
     //cout << "m: " << m << endl;
     
     int bad = k;
     
     int pos = (m-1) % circulo.size();

     //good guy in the killing position
     if (circulo[pos]) {
        return false;
     }
     
     //kill the bad guy 
     //cout << "matou " << pos << endl;          
     circulo.erase(circulo.begin() + pos);
     --bad;
     //cout << circulo.size() << endl;       
     
     while (bad > 0) {
           pos = ((pos + m - 1) % circulo.size());
           
           //good guy in the killing position
           if (circulo[pos]) {
                //cout << pos << endl;
                return false;
           }
           
           //kill the bad guy
           //cout << "matou " << pos << endl;
           circulo.erase(circulo.begin() + pos);
           --bad;
           //cout << circulo.size() << endl;           
     }
     
     return true;
     
     
}

int main()
{
    //cout << 1741 % 18 << endl;
    while (scanf("%d", &k) && k != 0) {
          
          /*
          int m = k+1;
          //int m = k;
          vector<bool> v;
          
          for (int i = 0; i < k; i++) {
              v.push_back(true);
          }
          
          for (int i = 0; i < k; i++) {
              v.push_back(false);
          }          
          
          while (!serve(v, m)) {
                ++m;
                //break;
          }*/
          
          printf("%d\n", solucao[k]);
          
          
    }
    
    
    
    return 0;   
}
