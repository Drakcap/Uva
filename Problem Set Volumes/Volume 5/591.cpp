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

int heights[60];

int main()
{
    int n, _set = 1, answ, somaH = 0, div;

    while (scanf("%d", &n) && n != 0) {
        somaH = answ = 0;
        FOR(i, 0, n) {
            scanf("%d", &heights[i]);
            somaH += heights[i];
        }
        div = somaH/n;

        FOR(i, 0, n) {
            answ += abs(heights[i]-div);
        }

        printf("Set #%d\n", _set++);
        printf("The minimum number of moves is %d.\n\n", answ/2);
        
    }

    return 0;
}
