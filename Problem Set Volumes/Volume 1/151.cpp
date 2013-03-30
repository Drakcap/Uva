#include <iostream>
#include <vector>
using namespace std;


int main()
{
	unsigned n_reg;
	
	cin >> n_reg;
	
	while (n_reg != 0) {
		
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
				
				if (pos_actual == 12)
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
		
		cout << m << endl;
		
		cin >> n_reg;
	}
	
	
	
	return 0;
}
