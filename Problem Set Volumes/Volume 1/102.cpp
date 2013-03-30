#include <iostream>
#include <string>
using namespace std;

int 
main() {
	
	long long unsigned n0, n1, n2, n3, n4, n5, n6, n7, n8;
	
	while (cin >> n0 >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8) {
		
		long long unsigned *possibilidades = new long long unsigned[6];
		
		possibilidades[0] = n3 + n6 + n2 + n8 + n1 + n4;
		
		possibilidades[1] = n3 + n6 + n1 + n7 + n2 + n5;
		
		possibilidades[2] = n5 + n8 + n0 + n6 + n1 + n4;
		
		possibilidades[3] = n5 + n8 + n1 + n7 + n0 + n3;
		
		possibilidades[4] = n4 + n7 + n0 + n6 + n2 + n5;
		
		possibilidades[5] = n4 + n7 + n2 + n8 + n0 + n3;
		
		long long unsigned min_mov = possibilidades[0];
		unsigned pos = 0;
		
		for (unsigned i = 1; i < 6; i++) {
			if (possibilidades[i] < min_mov) {
				pos = i;
				min_mov = possibilidades[i];
			}
		}
		
		string res;
		
		switch (pos) {
			case 0 :
				res = "BCG";
				break;
			case 1:
				res = "BGC";
				break;
			case 2:
				res = "CBG";
				break;
			case 3:
				res = "CGB";
				break;
			case 4:
				res = "GBC";
				break;
			case 5:
				res = "GCB";
				break;
		}
		
		cout << res << " " << min_mov << endl;
		
		delete possibilidades;
	}
	
	return 0;
	
}
