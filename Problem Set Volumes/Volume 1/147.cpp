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

int moedas[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
int nM = 11;

long long ways[30050];

void solve()
{
    ways[0] = 1;
    FOR(j, 0, nM) {
        FOR(i, 0, 30001) {
            if (i - moedas[j] >= 0 && ways[i-moedas[j]]) {
                ways[i] += ways[i-moedas[j]];
            }
        }
    }
}

int main()
{
    solve();
    double num;
    int numI;
    cout.setf(ios::fixed);

    while (cin >> num && fabs(num-0.) > EPS) {
        numI = (int) (num*100. + EPS);
        cout << setprecision(2) << setw(6) << num << setw(17) << ways[numI] << endl;
    }

    return 0;
}
