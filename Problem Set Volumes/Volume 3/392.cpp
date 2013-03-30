#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <sstream>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define SET(a, v) memset(a, v, sizeof(a))
#define EPS 0.000000001
#define FIND(s, v) ((s).find(v) != (s).end())

int coeffs[10];

int main()
{
    bool showConstant;
    while (scanf("%d", &coeffs[0]) == 1) {
        showConstant = true;
        FOR(i, 0, 9) {
            if (i)
                scanf("%d", &coeffs[i]);

            if (i == 8) {
                if (showConstant) {
                    cout << (coeffs[i] < 0 ? "-" : "");
                    cout << abs(coeffs[i]);
                } else if (coeffs[i] != 0) {
                    cout << (coeffs[i] < 0 ? " - " : " + ");
                    cout << abs(coeffs[i]);
                }
            } else {
                if (coeffs[i] == 0) continue;
                
                if (showConstant) {
                    cout << (coeffs[i] < 0 ? "-" : "");
                } else {
                    cout << (coeffs[i] < 0 ? " - " : " + ");
                }

                if (coeffs[i] != 1 && coeffs[i] != -1) {
                    cout << abs(coeffs[i]);
                }
                cout << "x";
                if (8-i > 1)
                    cout << "^"  << 8-i;

                showConstant = false;
            }
        }
        cout << "\n";
    }
    return 0;
}
