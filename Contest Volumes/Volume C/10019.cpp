#include <iostream>
using namespace std;

typedef long long unsigned llu;

llu conta_uns(int numero)
{
    llu uns = 0;
    
    while (numero > 0) {
    
          int resto = numero % 2;
          if (resto) uns++;
          numero = numero >> 1;       
    }
    
    return uns;
    
}

llu hex_to_int(int numero)
{
    llu res = 0;
    llu mul = 1;
    
    while (numero > 0) {
          
          int resto = numero % 10;
          res += resto * mul;
          mul *= 16;
          numero /= 10;
    }
    
    return res;
    
}

int main()
{
    int n_tests;
    
    cin >> n_tests;
    
    for (int i = 0; i < n_tests; i++) {
        int M;
        cin >> M;
        
        cout << conta_uns(M) << " ";
        
        llu hexa = hex_to_int(M);
        cout << conta_uns(hexa) << endl;
    }
    
    return 0;
}
