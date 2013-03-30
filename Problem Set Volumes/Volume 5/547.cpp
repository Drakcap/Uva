#include <iostream>
#include <vector>
using namespace std;

struct DDF {
       
       int tamanho;
       int prox_num;
};

int soma_digitos(int numero) 
{
    int soma = 0;
    
    int temp = numero;
    
    while (temp != 0) {
          soma += temp % 10;
          temp /= 10;
    }
    
    return soma;
}
    
    

int soma_factores(vector<int> &factores)
{
    int soma = 0;
    
    for (unsigned i = 0; i < factores.size(); i++) {
        soma += soma_digitos(factores[i]);
    }
    
    return soma;
}

int main()
{
    
    DDF ddf[3001];
    
    ddf[1].tamanho = 0;
    ddf[1].prox_num = 0;
    
    ddf[1].tamanho = 1;
    ddf[1].prox_num = 1;
    
    vector< vector<int> > factores;
    
    for (int i = 0; i < 3001; i++) {
        vector<int> temp;
        factores.push_back(temp);
    }
    

    
    
    for (int i = 1; i < 3001; i++) {
        
        for (int j = 1; j <= i/2; j++) {
                
                int div = i / j;
                
                if (div* j == i) {
                         factores[i].push_back(j);
                }    
        }
        
        factores[i].push_back(i);
    }
    
    
    for (unsigned i = 2; i < 3001; i++) {
        int soma = soma_factores(factores[i]);
        ddf[i].prox_num = soma;
        ddf[i].tamanho = 0;
        //ddf[i].tamanho = (ddf[soma].tamanho + 1);
    }
    
    for (unsigned i = 2; i < 3001; i++) {
        
        int num = i;
        int anterior = i;
        
        do {
               anterior = num;
               num = ddf[num].prox_num;
               
               ddf[i].tamanho++;
               
        } while (num != anterior && num != 1);
 
    }
    
    
    
    //leitura do input
    int min, max, numInput = 0;
    
    
    while (cin >> min >> max) {
          
          int temp_min = min;
          int temp_max = max;
          
          if (min > max) {
                  int temp = min;
                  min = max;
                  max = temp;
          }
                  
          numInput++;
          
          int tam_maximo = ddf[min].tamanho;
          int interessa = min;
          
          for (int i = min + 1; i <= max; i++) {
              
              if (ddf[i].tamanho > tam_maximo) {
                 tam_maximo = ddf[i].tamanho;
                 interessa = i;
              }
          }
          
          int tamanho = ddf[interessa].tamanho;
          
          cout << "Input" << numInput << ": " << temp_min << " " << temp_max << endl;
          cout << "Output" << numInput << ": ";
          
          //imprime primeiro
          cout << interessa;
          interessa = ddf[interessa].prox_num;
          
          for (int i = 1; i < tamanho; i++) {
              cout << " " << interessa;
              interessa = ddf[interessa].prox_num;
          }
          
          cout << endl;
              
    }  
    
    cin.get();
    
    return 0;
}
