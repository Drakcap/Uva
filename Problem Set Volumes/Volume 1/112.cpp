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

int I, ix;
bool did;
string temp;

void resetIx()
{
    if (ix == (int)temp.size()) {
        cin >> temp;
        ix = 0;
        //cout << "here: " << ix << " " << temp << endl;
    }
}

int parseNumber()
{
    char num[15];
    int nDigits = 0;

    while(temp[ix] != '(' && ix < (int)temp.size()) {
        num[nDigits++] = temp[ix];
        ++ix;
    }

    resetIx();
    num[nDigits] = 0;
    return atoi(num);
}

void solveAux(int sum, int parent, bool firstRun)
{
    resetIx();
    //skip '('
    ++ix;
    resetIx();
    bool hasChildren = false;

    //no first child
    if (temp[ix] == ')') {
        ++ix;
    } else { //has first child
        int child1 = parseNumber();
        hasChildren = true;
        //cout << parent << " has child1 " << child1 << endl;
        solveAux(sum+child1, child1, false);
    }
    
    if (firstRun) return;

    resetIx();
    //skip '('
    ++ix;
    resetIx();

    //no second child
    if (temp[ix] == ')') {
        ++ix;
    } else { //has second child
        int child2 = parseNumber();
        hasChildren = true;
        //cout << parent << " has child2 " << child2 << endl;
        solveAux(sum+child2, child2, false);
    }
    resetIx();
    //skip ')'
    ++ix;

    if (! hasChildren && sum == I) {
        did = true;
    }

    //cout << "parent: " << parent << " stopped in: " << ix << " with temp: " << temp << endl;
}

void solve()
{
    did = false;
    ix = 0;
    cin >> temp;

    //check if we have an empty tree
    if (temp.size() == 1) {
        cin >> temp;
        if (temp[0] == ')') {
            ix = 1;
            return;
        }
    } else if (temp[1] == ')') {
        ix = 2;
        return;
    }

    resetIx();
    solveAux(0, 0, true);
}

int main()
{
    while(cin >> I) {
        solve();
        cout << (did ? "yes" : "no") << endl;
        //cout << "last one: " << temp[ix] << " " << temp.size() << " " << ix  << endl;
    }
    return 0;
}
