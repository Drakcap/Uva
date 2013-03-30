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

#define MAX 1000000

int N, G;
int sins[300];
int visited[MAX+10];
int maior;

bool da(int n) {
    
    int mod;
    
    for (int i = 0; i < G; i++) {
        mod = sins[i] % n;
        if (visited[mod] == n) {
            return false;            
        }
        visited[mod] = n;
    }
    return true;
}

int main()
{
    
    cin >> N;
    
    while (N--) {
        cin >> G;
        maior = 0;
        
        for (int i = 0; i < G; i++) {
            cin >> sins[i];
            if (sins[i] > maior) {
                maior = sins[i];        
            }
        }
        
        for (int i = 0; i <= maior+1; i++) {
            visited[i] = -1;    
        }
        
        for (int i = G; i <= maior+1; i++) {
            if (da(i)) {
                cout << i << endl;
                break;        
            }
        }
       
    }
   
    return 0;
}
