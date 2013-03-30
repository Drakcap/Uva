#include <iostream>
using namespace std;

int main() {
	
	unsigned n_samples;
	
	cin >> n_samples;
	
	while (n_samples > 0) {
		
		double long long num1, num2;
		
		cin >> num1 >> num2;
		
		if (num1 > num2)
			cout << ">" << endl;
		
		else if (num1 < num2)
			cout << "<" << endl;
			
		else
			cout << "=" << endl;
			
			n_samples--;
		
	}
	
	
	
	return 0;
}
