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
int correct[55];
int answer[55];
int best[55];

int main()
{
    int temp, answ = 1;
    
    scanf("%d", &N);

    FOR(i, 0, N) {
        scanf("%d", &temp);
        correct[i] = temp;
    }

    while (scanf("%d", &temp) == 1) {
        answer[temp] = 0;

        FOR(i, 1, N) {
            scanf("%d", &temp);
            answer[temp] = i;
        }

        answ = 1;
        best[0] = 1;
        FOR(i, 1, N+1) {
            best[i] = 1;
            for (int j = i-1; j; j--) {
                if (correct[answer[j]] < correct[answer[i]]) {
                    best[i] = max(best[j]+1, best[i]);
                    answ = max(best[i], answ);
                    //printf("i: %d best: %d j: %d\n", i, best[i], j);
                    //break;
                }
            }
        }

        printf("%d\n", answ);
    }

    return 0;
}
