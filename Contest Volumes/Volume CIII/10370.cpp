#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    cout.setf(ios::fixed);
    
    int test_cases;
    
    cin >> test_cases;
    
    for (int i = 0; i < test_cases; i++) {
        
        int n;
        cin >> n;
        
        int* notas = new int[n];
        long long int somatorio = 0;
        
        for (int j = 0; j < n; j++) {
            cin >> notas[j];
            somatorio += notas[j];
        }
        
        long double media = somatorio / n;
        int n_acima = 0;
        
        for (int j = 0; j < n; j++) {
            if (notas[j] > media) {
               ++n_acima;
            }
        }
        
        long double percentagem = ( (double) n_acima / (double) n ) * 100;
        
        cout << setprecision(3) << percentagem << "%" << endl;
        
    }
    
    return 0;
}
