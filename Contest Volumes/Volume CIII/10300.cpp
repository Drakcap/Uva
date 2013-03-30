#include <iostream>
using namespace std;

int main()
{
    int n_testes;
    
    cin >> n_testes;
    
    for (int i = 0; i < n_testes; i++) {
        
        int n_farmers;
        long double total = 0;
        
        cin >> n_farmers;
        
        for (int j = 0; j < n_farmers; j++) {
            
            long double tam_quinta, n_animais, env;
            
            cin >> tam_quinta >> n_animais >> env;
            
            long double bonus = (tam_quinta / n_animais) * env * n_animais;
            total += bonus;
            
        }
        
        cout << total << endl;
        
    }
    
    return 0;
}
