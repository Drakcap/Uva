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
#include <cstring>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define SET(a, v) memset(a, v, sizeof(a))
#define EPS 0.000000001
#define FIND(s, v) ((s).find(v) != (s).end())
#define INF 100000

struct Town {
    bool ligs[110];
} towns[110];

struct query {
    int a, b, m;
} queries[1010];

int T, N, R, C, a, b, m, caso;
int dists[110][110];
string linha;
double probs[110][3100]; //probs[distancia][budget]

void resetProbs()
{
    FOR(i, 0, N) {
        FOR(j, 0, m+1) {
            probs[i][j] = 0.;
        }
    }
}

void calcProbs()
{
    FOR(i, 0, m+1)
        probs[0][i] = 1.;
    
    FOR(i, 1, N+1) {
        FOR(j, 1, m+1) {
            FOR(k, 1, R+1) {
                if (j - k >= 0) {
                    probs[i][j] += 1./((double)R) * probs[i-1][j-k];
                }
            }
        }
    }
}

void floyd()
{
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            dists[i][j] = (i == j ? 0 : INF);
            dists[i][j] = (towns[i].ligs[j] ? 1 : dists[i][j]);
        }
    }

    FOR(k, 0, N) {
        FOR(i, 0, N) {
            FOR(j, 0, N) {
                if (i == j) continue;
                    dists[i][j] = min(dists[i][j], dists[i][k]+dists[k][j]);
            }
        }
    }
}

int main()
{
    cin >> T;
    cout.setf(ios::fixed);
    
    while (T--) {
        cin >> N >> R;
  
        FOR(i, 0, N) {
            cin >> linha;
            FOR(j, 0, linha.size()) {
                towns[i].ligs[j] = (linha[j] == 'Y');
            }
        }
        
        //all pairs shortest paths
        floyd();
        
        cin >> C;
        m = 0;
        
        FOR(i, 0, C) {
            cin >> queries[i].a >> queries[i].b >> queries[i].m;
            queries[i].m = min(queries[i].m, 3000);
            m = max(m, queries[i].m);
        }
        
        resetProbs();
        calcProbs();
        
        cout << "Case " << ++caso << endl;
        
        FOR(i, 0, C) {
            cout << setprecision(6) << probs[dists[queries[i].a-1][queries[i].b-1]][queries[i].m] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
