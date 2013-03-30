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

#define FOR(i,a,b) for(int i = a, n = b; i < n; i++)
#define SET(a, v) memset(a, v, sizeof(a))
#define EPS 0.000000001
#define FIND(s, v) ((s).find(v) != (s).end())

struct Pos {
    int value;
    int best;
    bool hasBest;
    VI prev;
    int lin, col;
} matriz[12][110];

int nLin, nCol;

void solve()
{
    int c, l;
    FOR(j, 1, nCol) {
        FOR(i, 0, nLin) {
            FOR(k, -1, 2) {
                l = i+k;
                l = (l < 0 ? nLin-1 : l % nLin);
                c = j-1;
                matriz[l][c].prev.push_back(l);

                if (! matriz[i][j].hasBest || (matriz[l][c].best + matriz[i][j].value < matriz[i][j].best) ||
                   (matriz[l][c].best + matriz[i][j].value == matriz[i][j].best &&
                    matriz[l][c].prev < matriz[i][j].prev)) {
                    matriz[i][j].hasBest = true;
                    matriz[i][j].prev = matriz[l][c].prev;
                    matriz[i][j].best = matriz[l][c].best + matriz[i][j].value;
                }

                matriz[l][c].prev.pop_back();
            }

        }
    }
}

int main()
{
    while (cin >> nLin >> nCol) {
        FOR(i, 0, nLin) {
            FOR(j, 0, nCol) {
                scanf("%d", &matriz[i][j].value);
                matriz[i][j].best = matriz[i][j].value;
                matriz[i][j].lin = i;
                matriz[i][j].col = j;
                matriz[i][j].hasBest = false;
                matriz[i][j].prev.clear();
            }
        }

        solve();

        int linSol = -1;
        int best;
        VI prev;

        FOR(i, 0, nLin) {
            matriz[i][nCol-1].prev.push_back(i);
            if (linSol == -1 || matriz[i][nCol-1].best < best || 
               (matriz[i][nCol-1].best == best && matriz[i][nCol-1].prev < prev)) {
                linSol = i;
                best = matriz[i][nCol-1].best;
                prev = matriz[i][nCol-1].prev;
            }
        }

        printf("%d", prev[0]+1);

        FOR(i, 1, prev.size()) {
            printf(" %d", prev[i]+1);
        }
        printf("\n%d\n", best);

    }
    
    return 0;
}
