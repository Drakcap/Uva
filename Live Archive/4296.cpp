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

struct No {
    int nLigs;
    int isLig[3010];
    int ligs[3010], tamLigs[3010];
    int tam, num, prev;
    
    bool operator<(const No &n) const
    {
        return tam > n.tam;
    }
    
} nos[3010];

int T, N, R;
priority_queue<No> fila;
bool inMst[3010];
map<int, int> mst;

void read_input()
{
    int a, b, l;
    cin >> N >> R;
        
    FOR(i, 0, N) {
        nos[i].nLigs = 0;
        nos[i].tam = -1;
        nos[i].num = i;
        SET(nos[i].isLig, 0);
    }
    FOR(j, 0, R) {
        cin >> a >> b >> l;
        --a, --b;
        
        if (! nos[a].isLig[b] || l < nos[a].isLig[b]) {
            nos[a].isLig[b] = l;
            nos[b].isLig[a] = l;
            nos[a].ligs[nos[a].nLigs] = b;
            nos[a].tamLigs[nos[a].nLigs++] = l;
            nos[b].ligs[nos[b].nLigs] = a;
            nos[b].tamLigs[nos[b].nLigs++] = l;
        }
    }
}

void doMst()
{
    while (! fila.empty()) {
        fila.pop();
    }
    nos[0].tam = 0;
    int added = 0;
    added = 1;
    SET(inMst, false);
    inMst[0] = true;
    mst.clear();
    
    while (! fila.empty() && added < N) {
        No no = fila.top();
        fila.pop();
        inMst[no.num] = true;
        mst[no.num] = no.prev;
        mst[no.prev] = no.num;
        
        FOR(i, 0, no.num) {
            if (! inMst[no.ligs[i]] && (no.tamLigs[i] < nos[no.ligs[i]].tam ||
                nos[no.ligs[i]].tam == -1)) 
            {
                nos[no.ligs[i]].tam = no.tamLigs[i];
                nos[no.ligs[i]].prev = no.num;
                fila.push(nos[no.ligs[i]]);
            }
        }
    
    }
}


int main()
{
    cin >> T;
    
    while (T--) {
        read_input();
        //doMst();
        /*map<int, int>::iterator it = mst.begin();
        for ( ; it != mst.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }*/
    
    }
    
    return 0;
}
