#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

int somas[MAX];


int main()
{
    somas[1] = 1;
    
    for (int i = 2; i < MAX; i++) {
    
        if (i % 2 == 0) {
              somas[i] = somas[i-1];
        }
        else {
             somas[i] = somas[i-1] + i;
        }
        
    }

    
    int n_testes;
    cin >> n_testes;
    
    
    for (int k = 0; k < n_testes; k++) {
        
        int a, b;
        
        cin >> a >> b;
        
        if (a > b) {
              swap(a,b);
        }
        
        int soma = somas[b] - somas[a];
        
        if (a % 2 == 1) {
              soma += a;
        }
        
        cout << "Case " << k +1 << ": " << soma << endl;
        
        
        
    }
    
    
    
    
    return 0;   
}
