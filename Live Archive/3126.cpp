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
#include <cstring>
#include <cstdio>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; i++)
#define MAXM 500

struct Ride {
    int begin, end;
    int xi, yi;
    int xf, yf;
    int nLig;
    int ligs[MAXM];
} rides[MAXM];

int M;
int match[MAXM];
bool visited[MAXM];

inline int converte(int hora, int min)
{
    return hora*60+min;
}

inline int dist(int xi, int yi, int xf, int yf)
{
    return abs(xi-xf)+abs(yi-yf);
}

bool can(int ride1, int ride2)
{
    return (rides[ride1].end + dist(rides[ride1].xf, rides[ride1].yf, rides[ride2].xi, rides[ride2].yi)) < rides[ride2].begin;
}

bool go(int ride)
{
    int lig;
    for (int i = 0; i < rides[ride].nLig; i++) {
        lig = rides[ride].ligs[i];
        if (visited[lig]) continue;
        visited[lig] = true;
        
        if (match[lig] < 0 || go(match[lig])) {
            match[lig] = ride;
            return true;
        }
    }
    return false;
}

int main()
{
    int N, hora, min, answ;
    cin >> N;
    char temp[10];
    
    while (N--) {
        cin >> M;
        memset(match, -1, sizeof(match));
        FOR(i, M) {
            cin >> temp;
            sscanf(temp, "%d:%d", &hora, &min);
            rides[i].begin = converte(hora, min);
            cin >> rides[i].xi >> rides[i].yi >> rides[i].xf >> rides[i].yf;
            rides[i].end = dist(rides[i].xi, rides[i].yi, rides[i].xf, rides[i].yf) + rides[i].begin;
            rides[i].nLig = 0;
        }
        FOR(i, M) {
            FOR(j, M) {
                if (i != j) {
                    if (can(i, j)) {
                        rides[i].ligs[rides[i].nLig++] = j;
                    }
                }
            }
        }
        answ = 0;
        FOR(i, M) {
            memset(visited, false, sizeof(visited));
            if (go(i)) ++answ;
        }
        cout << M-answ << endl;
    }

}
