#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;

int m, p, a, b;
double xmin, xmax;
double valSomatorio;
double vals[2000];
double res;

int main()
{
    while (cin >> m >> p >> a >> b) {
        xmin = -1./sqrt(a);
        xmax = sqrt(a);
        valSomatorio = (double)b*sqrt(a);
        
        double res = 0.0;
        double somaActual = 0.0;
        double subAvailable = xmin*(double)m;
        //double fixe;
        
        for (int i = 0; i < m; i++) {
            subAvailable -= xmin;
            
            if (somaActual + subAvailable + xmax < valSomatorio) {
                vals[i] = xmax;    
            } else if (somaActual + subAvailable <= valSomatorio) {
                vals[i] = valSomatorio - (somaActual + subAvailable);    
            } else {
                vals[i] = max(xmin, valSomatorio - somaActual);    
            }
            somaActual += vals[i];
        }
        
        for (int i = 0; i < m; i++) {
            res += pow(vals[i], (double)p); 
        }
        
        cout << int(res+0.5) << endl;
    }
            
    
    return 0;  
}
