#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <queue>
using namespace std;

long long gcd(long long a, long long b) {
	while(b)  std::swap(a%=b, b);	
	return a;
}

long long a10s[1010];

int main()
{
	long long soma;
	long long T, C, a, a10, mdc, diff;
	
	cin >> T;
	
	while (T--) {
		mdc = -1;
		cin >> C;
		for (int c = 0; c < C; c++) {
			soma = 0;
			for (int i = 0; i < 9; i++) {
				cin >> a;
				soma += a;
			}
			cin >> a10;
			diff = (soma-a10);
			diff = (diff < 0 ? - diff : diff);
			mdc = (mdc == -1 ? diff : gcd(mdc, diff));
			a10s[c] = a10;
		}
		for (int i = 0; i < C; i++) {
			if (mdc <= a10s[i]) {
				mdc = 1;
				break;
			}
		}
		
		if (mdc <= 1) {
			cout << "impossible" << endl;
		} else {
			cout << mdc << endl;
		}
		
	}
	
	
	return 0;
}
