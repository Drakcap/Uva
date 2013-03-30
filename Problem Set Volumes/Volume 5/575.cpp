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


int main()
{
    string n;
    int answ;

    while (cin >> n && n != "0") {
        answ = 0;
        FOR(i, 0, n.size()) {
            answ += (n[n.size()-i-1]-'0')*((1 << (i+1)) -1);
        }
        printf("%d\n", answ);
    }
    return 0;
}
