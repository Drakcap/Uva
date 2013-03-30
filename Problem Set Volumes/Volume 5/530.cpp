#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
     if (a % b == 0) return b; else return gcd(b, a%b);
}

void divbygcd(long long &a, long long &b)
{
     long long g = gcd(a,b);
     a /= g;
     b /= g;
}

long long comb(int n, int k)
{
     long long numerator = 1, denominator = 1, toMul, toDiv, i;
     
     if (k > n/2) k = n-k;
     
     for (i = k; i; i--) {
         
         toMul = n - k + i;
         toDiv=i;
         
         divbygcd(toMul, toDiv);
         divbygcd(numerator, toDiv);
         divbygcd(toMul, denominator);
         numerator *= toMul;
         denominator *= toDiv;
     }
     
     return numerator/denominator;
}

int main()
{
    
    long long n, k;
    
    while (cin >> n >> k) {
          
          if (n == 0 && n == 0)
             break;
             
          cout << comb(n,k) << endl;
    }
          
    return 0;
}
