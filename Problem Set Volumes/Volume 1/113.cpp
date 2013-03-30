#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	
	double n, p;
	
	while (cin >> n >> p) {
		
		//long double k = floor(pow(p,1.0/n)+0.5);
		
		cout<<setiosflags(ios::fixed)<<setprecision(0)<<pow(p, 1.0/n)<<endl;
		
		/*
		for ( ; k <= p; k++) {
			
			if (pow(k,n) == p) {
				break;
			}
		}*/
		
		//cout << k << endl;
		
	}
	
	return 0;
}
			
