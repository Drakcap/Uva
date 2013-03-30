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

int N;
string people[12];
int money[12];
map<string, int> mapa;

int main()
{
    string temp, temp2;
    int m, nPeople, ix, div;
    bool first_run = true;
    
    while (cin >> N) {
        if (! first_run) {
            cout << endl;
        } else {
            first_run = false;   
        }
        
        SET(money, 0);
        FOR(i, 0, N) {
            cin >> people[i];
            mapa[people[i]] = i;
        }
        FOR(i, 0, N) {
            cin >> temp >> m >> nPeople;
            ix = mapa[temp];
            //money[ix] += m;
            if (nPeople == 0) continue;
            div = m/nPeople;
            
            FOR(j, 0, nPeople) {
                cin >> temp2;
                money[ix] -= div;
                money[mapa[temp2]] += div;    
            }
        }
        FOR(i, 0, N) {
            cout << people[i] << " " << money[i] << endl;
        }
    }
    return 0;
}
