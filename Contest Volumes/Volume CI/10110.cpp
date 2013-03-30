#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned n;
    double root;
    unsigned rootInt;
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        root = sqrt(n);
        rootInt = (unsigned) (root + 0.000000001);
        
        if (rootInt * rootInt == n) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
