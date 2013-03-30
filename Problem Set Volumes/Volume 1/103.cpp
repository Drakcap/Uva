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

int K, N, answ, last;

struct Box {
    int values[12];
    int num, best;
    int maiores[35];
    int nMaiores;
    int prev;
    bool visited;

    bool operator<(const Box &b) const
    {
        FOR(i, 0, N) {
            if (values[i] >= b.values[i]) {
                return false;
            }
        }
        return true;
    }
} boxes[35];

void dfs(int box)
{
    boxes[box].visited = true;
    if (boxes[box].best > answ) {
        last = box;
        answ = boxes[box].best;
    }

    FOR(i, 0, boxes[box].nMaiores) {
        if (boxes[boxes[box].maiores[i]].best < boxes[box].best+1) {
            boxes[boxes[box].maiores[i]].best = boxes[box].best+1;
            boxes[boxes[box].maiores[i]].prev = box;
            dfs(boxes[box].maiores[i]);
        }
    }
}

void solve()
{
    FOR(i, 0, K) {
        if (! boxes[i].visited) {
            dfs(i);
        }
    }
}


int main()
{
    while (cin >> K >> N) {
        answ = 0;

        FOR(i, 0, K) {
            FOR(j, 0, N) {
                cin >> boxes[i].values[j];
            }
            boxes[i].num = i;
            boxes[i].best = 1;
            boxes[i].nMaiores = 0;
            boxes[i].visited = false;
            boxes[i].prev = -1;
            sort(boxes[i].values, boxes[i].values+N);
        }

        FOR(i, 0, K) {
            FOR(j, 0, K) {
                if (i != j && boxes[i] < boxes[j]) {
                    boxes[i].maiores[boxes[i].nMaiores++] = j;
                }
            }
        }
        solve();
        cout << answ << endl;

        VI all;
        while(last != -1) {
            all.push_back(last+1);
            last = boxes[last].prev;
        }
        cout << all[all.size()-1];
        for(int i = all.size()-2; i >= 0; i--) {
            cout << " " << all[i];
        }
        cout << endl;
    }
    return 0;
}
