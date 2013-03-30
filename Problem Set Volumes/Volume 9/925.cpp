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
using namespace std;

struct No {
    int num;
    bool visited;
    bool dep[120];
    set<int> lig;
} nos[120];

int K, N;
string numnome[120];
map<string, int> nomenum;

void bfs(int source)
{   
    for (int i = 0; i < K; i++) {
        nos[i].visited = false;
        nos[source].dep[i] = false;
    }
    queue<No> fila;
    nos[source].visited = true;
    fila.push(nos[source]);
    
    while(! fila.empty())
    {
        No no = fila.front();
        fila.pop();
        
        for (set<int>::iterator it = no.lig.begin(); it != no.lig.end(); it++) {
            if (nos[*it].visited) {
                nos[source].dep[*it] = false;
            } else if (no.num == source) {
                nos[source].dep[*it] = true;
            }
            nos[*it].visited = true;
            fila.push(nos[*it]);
        }
        
    }
    
}

int
main()
{

    cin >> N;
    string temp, no;
    int ndep, nlig, ino;
    
    while (N--)
    {
        //cout << N << endl;
        nomenum.clear();
        cin >> K;
        
        for (int i = 0; i < K; i++) {
            cin >> temp;
            nomenum[temp] = i;
            numnome[i] = temp;
            nos[i].num = i;
            nos[i].lig.clear();
        }
        cin >> ndep;
        
        for (int i = 0; i < ndep; i++) {
            cin >> no >> nlig;
            ino = nomenum[no];
        
            for (int j = 0; j < nlig; j++) {
                cin >> temp;
                nos[ino].lig.insert(nomenum[temp]);
                //cout << "ligar " << ino << " a " << nomenum[temp] << endl;
            }
        }
        
        //cout << "li" << endl;
        
        for (int i = 0; i < K; i++) {
            if (nos[i].lig.size()) {
                bfs(i);
            }
        }
        
        //cout << "bfs" << endl;
        
        map<string, int>::iterator it = nomenum.begin();
        vector<string> res;
        
        for (; it != nomenum.end(); it++) {
            if (nos[it->second].lig.size()) {
                //cout << nos[it->second].lig.size() << " ";
                res.clear();
                for (int i = 0; i < K; i++) {
                    if (nos[it->second].dep[i]) {
                        res.push_back(numnome[i]);
                    }
                }
                sort(res.begin(), res.end());
                cout << it->first << " " << res.size();
                
                for (unsigned i = 0; i < res.size(); i++) {
                    cout << " " << res[i];
                }
                cout << endl;
            }
            
        }
        
    }
    
    

    return 0;
}
