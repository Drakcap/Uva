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
    string s, t;
    size_t ixs, ixt;

    while (cin >> s >> t) {
        ixs = 0, ixt = 0;

        while (ixs < s.size() && ixt < t.size()) {
            if (s[ixs] == t[ixt]) {
                ++ixs, ++ixt;
            } else {
                ++ixt;
            }
        }

        cout << (ixs == s.size() ? "Yes" : "No") << endl;
    }
    return 0;
}
