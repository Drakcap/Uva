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

char palavra[30];

int getDigit(int i) {
    if (palavra[i] == 'B' || palavra[i] == 'F' || palavra[i] == 'P' ||
            palavra[i] == 'V') {
        return 1;
    } else if (palavra[i] == 'C' || palavra[i] == 'G' ||
            palavra[i] == 'J' || palavra[i] == 'K' ||
            palavra[i] == 'Q' || palavra[i] == 'S' ||
            palavra[i] == 'X' || palavra[i] == 'Z') {
        return 2;
    } else if (palavra[i] == 'D' || palavra[i] == 'T') {
        return 3;
    } else if (palavra[i] == 'L') {
        return 4;
    } else if (palavra[i] == 'M' || palavra[i] == 'N') {
        return 5;
    } else if (palavra[i] == 'R') {
        return 6;
    }
    return -1;
}

int main()
{  
    int tam, d;

    while (scanf("%s", palavra) == 1) {
        tam = strlen(palavra);

        FOR(i, 0, tam) {
            if (i > 0 && getDigit(i) == getDigit(i-1)) {
                continue;
            }
            d = getDigit(i);
            if (d != -1)
                printf("%d", d);
        }
        printf("\n");
    }
    return 0;
}
