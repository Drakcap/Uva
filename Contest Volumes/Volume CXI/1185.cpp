#include <iostream>
using namespace std;

int main()
{
    
    long long int num;
    
    cin >> num;
    
    while (num >= 0) {
          
          long long unsigned res = 0, i = 1;
          
          
          while (num > 0) {
                
                res += (num % 3) * i;
                
                i *= 10;
                
                num /= 3;
                
          }
          
          cout << res << endl;
          
          cin >> num;      
                 
          
    }
    
    
    return 0;
    
    
}
