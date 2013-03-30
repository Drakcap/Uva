#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int *calculados = new int[150];
    
    for (unsigned i = 0; i < 150; i++) {
        calculados[i] = 0;
    }
    
    calculados[3] = 2;
    calculados[4] = 5;
    calculados[5] = 2;
    calculados[6] = 4;
    calculados[7] = 3;
    calculados[8] = 11;
    calculados[9] = 2;
    calculados[10] = 3;
    calculados[11] = 8;
    calculados[12] = 16;
    
	unsigned n_reg;
	
	cin >> n_reg;
	
	while (n_reg != 0) {
        
        if (calculados[n_reg] != 0) {
           cout << calculados[n_reg] << endl;
           n_reg = 0;
        }
 
         
        else {
		     
		     int coiso = n_reg;
    		bool serve = false;
    		
    		unsigned m = 0;
    		
    		while (serve == false) {
    			
    			unsigned *estado = new unsigned[n_reg];
    			unsigned n_apagadas = 0;
    		
    			for (unsigned i = 0; i < n_reg; i++)
    				estado[i] = 0;
    			
    			m++;
    			unsigned pos_actual = 0;
    			
    			//enquando nao apagar todas menos uma
    			while (n_apagadas < n_reg) {
    				
    				if (pos_actual == 1)
    					break;
    				
    				else if (estado[pos_actual] == 0) {
    					estado[pos_actual] = 1;
    					n_apagadas++;
    				}
    				
    				//passa para a posicao seguinte
    				for (unsigned i = 0; i < m; i++) {
    					
    					pos_actual++;
    					pos_actual = pos_actual % n_reg;
    					
    					//se for uma regiao ja apagada
    					while (estado[pos_actual] == 1) {
    						pos_actual++;
    						pos_actual = pos_actual % n_reg; 
    					}
    				}
    			}
    			
    			if (n_reg - n_apagadas <= 1)
    				serve = true;
    				 
    		}
    		calculados[coiso] = m;
    		cout << m << endl;
        }
		
		cin >> n_reg;
	}
	
	
	
	return 0;
}
