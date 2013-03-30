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
#define SET(a, v) memset(a, v, sizeof(a))
#define MAXN 500


struct Person {
    int h;
    string music, sport;
    int nLigs;
    int ligs[MAXN+10];
} men[MAXN+10], women[MAXN+10];

int nMen;
int nWomen;
bool visited[MAXN+10];
int match[MAXN+10];

bool can(int m, int w)
{
    return (abs(men[m].h - women[w].h) <= 40 && men[m].music == women[w].music && men[m].sport != women[w].sport);
}

bool go(int m)
{
    int w;
    for (int i = 0; i < men[m].nLigs; i++) {
        w = men[m].ligs[i];
        if (visited[w]) {
            continue;
        }
        visited[w] = true;
        
        if (match[w] < 0 || go(match[w])) {
            match[w] = m;
            return true;
        }
    }
    return false;
}

int main()
{
    int T, nPeople;
    cin >> T;
    int h;
    char genre;
    string music, sport;
    int ret;
    
    while (T--) {
        cin >> nPeople;
        nMen = 0;
        nWomen = 0;
        SET(match, -1);
        
        FOR(i, nPeople) {
            cin >> h >> genre >> music >> sport;
            if (genre == 'F') {
                women[nWomen].h = h;
                women[nWomen].music = music;
                women[nWomen++].sport = sport;
            } else {
                men[nMen].nLigs = 0;
                men[nMen].h = h;
                men[nMen].music = music;
                men[nMen++].sport = sport;
            }
        }
        
        FOR(i, nMen) {
            FOR(j, nWomen) {
                if (can(i, j)) {
                    men[i].ligs[men[i].nLigs++] = j;
                }
            }
        }
        
        ret = 0;
        FOR(i, nMen) {
            SET(visited, false);
            if (go(i)) {
                ++ret;
            }
        }
        cout << nPeople - ret << endl;
    
    }
}
