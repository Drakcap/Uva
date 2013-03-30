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

int pancakes[35];
int tempPancakes[35];
int N;
string linha;
int flips[100];
int nFlips;
map<int, int> mapa; //<posicao final em que deve estar, peso>

void flip(int pos)
{
    int ix1 = pos, ix2 = 0;

    while(ix1 > ix2) {
        swap(pancakes[ix1], pancakes[ix2]);
        --ix1, ++ix2;
    }
    flips[nFlips++] = pos;
}

void solve()
{
    //analisa de baixo para cima
    for(int i = N-1; i >= 0; i--) {
        //se esta posicao ja esta correcta, continua
        if (mapa[i] == pancakes[i]) {
            continue;
        }
        //para cada posicao acima da actual
        for(int j = i-1; j >= 0; j--) {
            //foi encontrada a pancake que deve estar na posicao i
            if (mapa[i] == pancakes[j]) {
                //e' preciso um flip adicional para colocar a pancake no topo
                if (j != 0) {
                    flip(j);
                }
                //coloca a pancake na posicao i
                flip(i);
                break;
            }
        }
    }
}

int main()
{
    while (getline(cin, linha)) {
        N = 0;
        nFlips = 0;
        mapa.clear();
        istringstream iss(linha);
        while (iss >> pancakes[N]) {
            tempPancakes[N] = pancakes[N];
            cout << (N > 0 ? " " : "") << pancakes[N];
            ++N;
        }
        cout << endl;

        sort(tempPancakes, tempPancakes + N);
        FOR(i, 0, N) {
            mapa[i] = tempPancakes[i];
        }

        solve();
        FOR(i, 0, nFlips) {
            cout << N-flips[i] << " ";
        }
        cout << 0 << endl;
    }
    return 0;
}
