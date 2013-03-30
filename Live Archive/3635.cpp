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
#include <iomanip>
using namespace std;

#define EPS 0.001
#define MAX 10000

double pi = acos(-1);
double pies[MAX+10];
int N, F;

bool da(double vol)
{
    int nfatias = 0;
        
    for (int i = 0; i < N; i++) {
        nfatias += (int)(pies[i] / vol);    
    }
    return nfatias > F;
    
}

int main()
{
    int T, raio;
    cin >> T;
    cout.setf(ios::fixed);
    
    while (T--) {
        cin >> N >> F;
            
        for (int i = 0; i < N; i++) {
            cin >> raio;
            pies[i] = pi*(double)raio*(double)raio;    
        }
        double low = 0.0, high = 10000. * 10000. * pi, middle;
        while (low + EPS < high) {
            middle = (low + high)/2.;
            if (da(middle)) {
                low = middle;        
            } else {
                high = middle;    
            }
            
        }
        cout << setprecision(4) << low << endl;
    }
    
    return 0;
}
