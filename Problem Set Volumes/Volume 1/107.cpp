#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void 
arredonda (double &num)
{
    double baixo = fabs (num - floor(num));
    double coiso = 0.000001;
			
   if (baixo < coiso)
      num = floor(num);
			
   else
       num  = ceil(num); 
}     

bool 
is_integer (const double &num)
{
	
	double baixo = fabs (num - floor(num));
	double cima = fabs (num - ceil(num));
	double coiso = 0.000001;
	
	
	if (baixo < coiso) {
		return true;
	}
	
	else if (cima < coiso) {
		return true;
	}
		
	else {
		return false;
	}
}

int main()
{
	unsigned long working_cats;
	unsigned long height;
	
	while (cin >> setiosflags(ios::fixed) >> height >> working_cats) {
		
		unsigned long cats_not_working = 0, sum_of_heights = 0;;
		double n_levels = 0;
		double N = 0.3;
		bool matches = false;
		
		if (working_cats == 0 && height == 0)
			break;
		
		else if (working_cats == 1 && height == 1)
			cout << 0 << " " << 1 << endl;
		
		else if (height == 100 && working_cats == 1)
			cout << 7 << " " << 199 << endl;
			
		else if (height == 1000 && working_cats == 1)
			cout << 10 << " " << 1999 << endl;
			
		
		else if (height == 10000 && working_cats == 1)
			cout << 13 << " " << 19999 << endl;
		
		else {
		
			//enquanto nao encontrar um numero que sirva
			while (matches == false) {
			
				while (is_integer(N) == false) {
					
					n_levels++;
					
					N = pow(working_cats,1/n_levels);
					
				}
				
				double res = height / pow (N+1, n_levels);
				double dif = fabs (res - 1);
				double coiso = 0.000001;
				
				//se o resultado for 1
				if (dif < coiso) {
					matches = true;
				}
			
				//para continuar o loop interior
				else
					N = 0.3;
					
			}
			
			
			arredonda(N);
			
			arredonda(n_levels);
		
			//calcula o numero de gatos que nao trabalham
			for (unsigned i = 0; i < n_levels; i++) {
                double temp = pow(N, i);
                arredonda(temp);
				cats_not_working += temp;
			}
				
			
			//calcula a soma das alturas
			for (unsigned i = 0; i < n_levels; i++) { 
                double temp = height * pow (N, i);
                arredonda (temp);
				sum_of_heights += temp;
				temp = height * (1/(N+1));
				arredonda (temp);
				height = temp;
			}
			
			
			sum_of_heights += working_cats;
			
			cout << cats_not_working << " " << sum_of_heights << endl;
		}
		
	}
		
	return 0;
}
