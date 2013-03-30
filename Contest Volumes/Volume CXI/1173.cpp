#include <iostream>
#include <math.h>
using namespace std;   


long long double 
grey_code (long long double n, long long double k)
{
	
	if (n == 1 && k == 0)
		return 0;
		
	else if (n == 1 && k == 1)
		return 1;
	
	else if (k >= pow(2, n-1)) {
		return (pow(2, n-1) + grey_code(n-1, pow(2, n) - 1 - k));
	}
	
	else
		return (grey_code(n-1, k));
		
		
}




int main() {
    
    unsigned n_samples;
    
    cin >> n_samples;
    
    while (n_samples > 0) {
        
        long long double n, k;
        
        cin >> n >> k;
	
	    cout << grey_code(n,k) << endl;
	    
	    n_samples--;
     
     }
	
	return 0;
	
}
