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

struct Build {
    int l, h, r;
    bool operator<(const Build &b) const {
        return l < b.l;
    }
    
} builds[5010];

int nBuild;
int alturas[10100];
int maxR, minL = 20000;

void solve()
{
    cout << minL << " " << alturas[minL] << " ";
    FOR(i, minL+1, maxR) {
        if (alturas[i] != alturas[i-1]) {
            cout << i << " " << alturas[i] << " ";
        }
    }
    cout << maxR << " " << 0 << endl;
}

int main()
{
    while (cin >> builds[nBuild].l >> builds[nBuild].h >> builds[nBuild].r) {
        maxR = max(maxR, builds[nBuild].r);
        minL = min(minL, builds[nBuild].l);
        FOR(i, builds[nBuild].l, builds[nBuild].r) {
            alturas[i] = max(alturas[i], builds[nBuild].h);
        }
        ++nBuild;
    }
    solve();
    
    return 0;
}
