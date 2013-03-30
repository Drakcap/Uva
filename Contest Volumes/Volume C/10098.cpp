#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    unsigned samples;
	
	cin >> samples;
	
	while (samples != 0) {
		
		string palavra;
		vector<char> letras;
	
		cin >> palavra;
	
		for (unsigned i = 0; i < palavra.size(); i++)
			letras.push_back(palavra[i]);
		
		sort (letras.begin(), letras.end());
	
		vector<char> inicial = letras;
		
		for (unsigned i = 0; i < letras.size(); i++) {
            cout << letras[i];
        }
        
        cout << endl;
        
        next_permutation (letras.begin(), letras.end());
        
        while (letras != inicial) {
              
              for (unsigned i = 0; i < letras.size(); i++) {
                  cout << letras[i];
              }
              
              cout << endl;
              
              next_permutation (letras.begin(), letras.end());
        }
        
        cout << endl;
        
        
        samples--;
		
    }
    
    
    return 0;
    
}
