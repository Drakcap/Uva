#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;

struct Switch {
    int nBulbs;
    int mask;
} switches[40];

int visited[32768];

int n, m;
int T;

void bfs()
{
    queue<pair<int, int> > fila;
    fila.push(make_pair(0, 0));
    int novoN;
    visited[0] = 0;
    
    while (! fila.empty()) {
        pair<int, int> par = fila.front();
        fila.pop();
        
        for (int i = 0; i < m; i++) {
            novoN = par.first ^ switches[i].mask;
            //cout << novoN << " " << par.first << " " << switches[i].mask << endl;
            if (par.second+1 < visited[novoN] || visited[novoN] == -1) {
                visited[novoN] = par.second+1;
                fila.push(make_pair(novoN, par.second+1));
            }
        }
    }
}

int converte(string str)
{
    int ix = str.size()-1;
    int value = 0, mult = 1;
    
    for ( ; ix >= 0; ix--) {
        if (str[ix] == '1') {
            value += mult;
        }
        mult *= 2;
    }
    return value;
}

int main()
{
    cin >> T;
    int nCase = 1;
    int temp;
    int nQueries;
    string query;
    
    while (T--) {
        cin >> n >> m;
        int nEstados = (1 << n);
        memset(visited, -1, nEstados*sizeof(int));
        
        for (int i = 0; i < m; i++) {
            cin >> switches[i].nBulbs;
            switches[i].mask = 0;
            
            for (int j = 0; j < switches[i].nBulbs; j++) {
                cin >> temp;
                switches[i].mask |= (1 << temp);
            }
            //cout << switches[i].mask << endl;
        }
        
        bfs();
        
        cin >> nQueries;
        cout << "Case " << nCase++ << ":" << endl;
        for (int i = 0; i < nQueries; i++) {
            cin >> query;
            cout << visited[converte(query)] << endl;
        }
        cout << endl;
        
    }

    return 0;
}
