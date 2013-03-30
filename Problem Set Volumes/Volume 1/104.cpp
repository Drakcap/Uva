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
#define EPS 0.0000000000000001
#define FIND(s, v) ((s).find(v) != (s).end())

struct No {
    double ligacoes[25];
    int num;
} nos[25];

int N;
double best[25][25][25];
VI prev[25][25][25];

bool solve()
{
    FOR(i, 0, N) {
        best[i][i][0] = 1.;
    }

    FOR(tam, 2, N+1) {
        FOR(i, 0, N) {
            FOR(j, 0, N) {
                FOR(k, 0, N) {
                    if (j == k) continue;
                    if (best[i][k][tam-1]*nos[k].ligacoes[j] > best[i][j][tam]) {
                        best[i][j][tam] = best[i][k][tam-1]*nos[k].ligacoes[j];
                        prev[i][j][tam] = prev[i][k][tam-1];
                        prev[i][j][tam].push_back(k);
                    }

                    if (i == j && best[i][i][tam] > (1.01 + EPS)) {
                        FOR(l, 0, prev[i][i][tam].size()) {
                            cout << prev[i][i][tam][l] + 1 << " ";
                        }
                        cout << i + 1 << endl;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    while (cin >> N) {
        FOR(i, 0, N) {
            FOR(j, 0, N) {
                FOR(k, 0, N+1) {
                    prev[i][j][k].clear();
                    best[i][j][k] = 0.;
                }
            }
        }

        FOR(i, 0, N) {
            nos[i].num = i;
            FOR(j, 0, N) {
                if (j == i) continue;
                cin >> nos[i].ligacoes[j];
                best[i][j][1] = nos[i].ligacoes[j];
                prev[i][j][1].push_back(i);
            }
        }
        cout << (solve() ? "" : "no arbitrage sequence exists\n");
    }
    
    return 0;
}
