#include <iostream>
#include <math.h>
using namespace std;


bool 
is_Kaprekar(const unsigned num)
{
	/*
	unsigned square = pow (num, 2);
	
	for (unsigned i = 10; i < square; i *= 10) {
		
		unsigned part1 = square % i;
		unsigned part2 = square / i;
		
		
		if ((part1 + part2) == num && part1 > 0 && part2 > 0)
			return true;
	}*/
	
	
	if (num == 9 || num == 45 || num == 55 || num == 99 || num == 297 ||
		num == 703 || num == 999 || num == 2223 || num == 2728 || num == 4879 ||
		num == 4950 || num == 5050 || num == 5292 || num == 7272 || num == 7777 ||
		num == 9999 || num == 17344 || num == 22222 || num == 38962)
			return true;
	else
		return false;
		
}


int
main()
{
	/*
	unsigned already_calc = new unsigned[40000];
	
	for (unsigned i = 0; i < 40000; i++) {
		already_calc[i] = 0;
	}*/
	
	unsigned n_samples, actual_sample = 1;
	unsigned inf, sup, n_kaprekar = 0;
	
	cin >> n_samples;
	
	cin >> inf >> sup;
	
	//imprime primeiro
	cout << "case #" << actual_sample << endl;
	
	for (unsigned i = inf; i <= sup; i++) {
			
	    if (is_Kaprekar(i) == true) {
				n_kaprekar++;
				cout << i << endl;
			}
		}
		
		
	if (n_kaprekar == 0) {
			cout << "no kaprekar numbers" << endl;// << endl;
	}
	
	n_samples--;
	actual_sample++;
	
	while (n_samples != 0) {
		
		unsigned inf, sup, n_kaprekar = 0;
		
		cin >> inf >> sup;
		
		cout << "\ncase #" << actual_sample << endl;
		
		for (unsigned i = inf; i <= sup; i++) {
			
			if (is_Kaprekar(i) == true) {
				n_kaprekar++;
				cout << i << endl;
			}
		}
		
		
		
		if (n_kaprekar == 0) {
			cout << "no kaprekar numbers" << endl;// << endl;
		}
		
		/*
		else {
			cout << endl;
		}*/
		
		n_samples--;
		actual_sample++;
	}
		
	
	return 0;
}

