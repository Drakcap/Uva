#include <iostream>
using namespace std;

typedef long long int llu;

class DisjSets {
      
      public:
             
          llu *conjuntos;
          llu nElementos;
          
          DisjSets (llu numElementos)
          {
                 nElementos = numElementos;  
                 conjuntos = new llu[numElementos];
                 
                 for (llu i = 0; i < numElementos; i++) {
                     conjuntos[i] = -1;
                 }
          }
          
          void uniao (llu raiz1, llu raiz2)
          {
               //raiz1 tem mais elementos
               if (conjuntos[raiz1] < conjuntos[raiz2]) {
                  conjuntos[raiz1] += conjuntos[raiz2];
                  conjuntos[raiz2] = raiz1;
               }
               
               //raiz2 tem mais elementos
               else if (conjuntos[raiz2] < conjuntos[raiz1]) {
                    conjuntos[raiz2] += conjuntos[raiz1];
                    conjuntos[raiz1] = raiz2;
               }
               
               //com os mesmos elementos
               else if (raiz1 != raiz2) {
                    conjuntos[raiz1] += conjuntos[raiz2];
                    conjuntos[raiz2] = raiz1;
               }
               
                                         
          }
          
          llu find (llu x)
          {
              if (conjuntos[x] < 0){
                 return x;
              }
              
              else {
                   return conjuntos[x] = find(conjuntos[x]);
              }
          }
          
          llu max_amigos()
          {
              llu num_max = -1;
              
              for (llu i = 0; i < nElementos; i++)
              {
                  if (conjuntos[i] < num_max) {
                     num_max = conjuntos[i];
                  }
              }
              
              return num_max * -1;
          }

              
};

int main()
{
    
    llu n_samples;
    
    cin >> n_samples;
    
    for (llu i = 0; i < n_samples; i++) {
        
        llu N, M;
        
        cin >> N >> M;
        
        DisjSets conj(N);
    
        for (llu j = 0; j < M; j++) {
            llu a, b;
            cin >> a >> b;
            
            conj.uniao(conj.find(a-1), conj.find(b-1));
        }
        
        cout << conj.max_amigos() << endl;
        
    }
    
    
    return 0;
}
