#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

struct Bond {
    int value;  
    int interest;
} bonds[12];

int best[50000], amount, years, nbonds;

int main()
{
    int T, topo;
    double temp;
    cin >> T;
    
    while (T--) {
        cin >> amount >> years >> nbonds;
        temp = amount;   
        for (int i = 0; i < years; i++) {
            temp *= 1.1;     
        }
        topo = (int) temp;
        topo /= 1000;
        memset(best, 0, sizeof(int)*(topo+1));
        
        for (int i = 0; i < nbonds; i++) {
            cin >> bonds[i].value >> bonds[i].interest;
            bonds[i].value /= 1000;    
            //cout << bonds[i].interest << endl;
        }
        
        for (int i = 0; i <= topo; i++) {
            for (int j = 0; j < nbonds; j++) {
                if (i + bonds[j].value <= topo && best[i] + bonds[j].interest > best[i + bonds[j].value]) {
                    //cout << "coiso: " << bonds[j].value << endl;
                    best[i+bonds[j].value] = best[i]+bonds[j].interest;            
                }
            }
        }
        /*for (int i = 0; i <= topo; i++) {
            cout << i << " " << best[i] << endl;    
        }*/
        
        for (int i = 0; i < years; i++) {
            //cout << amount << endl;
            amount += best[amount/1000];    
        }
        
        cout << amount << endl;
        
    }
    
    return 0;
}
