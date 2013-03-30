#include <iostream>
using namespace std;


int main()
{
    
    long long int n_tests;
    
    cin >> n_tests;
    
    for (long long int i = 0; i < n_tests; i++) {
        
        long long int sum, dif;
        
        cin >> sum >> dif;
        
        if (! (sum >= dif) )
           cout << "impossible" << endl;
           
        else if (! ((sum+dif) % 2 == 0) )
             cout << "impossible" << endl;
             
        else if (! ((sum-dif) % 2 == 0) )
             cout << "impossible" << endl;
             
        else {
        
            long long int a, b;
            
            b = (sum - dif) / 2;
            a = sum - b;
            
            if (a < 0 || b < 0) cout << "impossible" << endl;
            
            else if (a > b) {
                  cout << a << " " << b << endl;
            }
            else {
                 cout << b << " " << a << endl;
            }
        }
        
        
    }
    
    
    return 0;
}
