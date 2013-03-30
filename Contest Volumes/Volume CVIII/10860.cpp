#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define INF 10000000

char longStr[10001];
int best[10001];
char shortStrs[50][101];
int tams[50];
int longLen;
int S;
int N;

bool fit(int str, int ixi)
{
    if (ixi + tams[str] > longLen) {
        return false;
    }
    
    bool da = true;
    
    for (int i = 0; i < tams[str]; i++) {
        if (longStr[ixi+i] != shortStrs[str][i]) {
            da = false;
            break;
        }
    }
    
    if (da) return true;
    da = true;
    
    for (int i = tams[str]-1, ix = ixi; i >= 0; i--, ix++) {
        if (longStr[ix] != shortStrs[str][i]) {
            da = false;
            break;
        }
    }

    return da;
}

int main()
{
    cin >> S;
    int nTest = 1;
    
    while (S--) {
    
        cin >> longStr;
        longLen = strlen(longStr);
        for (int i = 0; i <= longLen; i++) {
            best[i] = INF;
        }
        //cout << best[longLen] << endl;
        //cout << INF << endl;
        
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> shortStrs[i];
            tams[i] = strlen(shortStrs[i]);
        }
        best[0] = 0;
        
        for (int i = 0; i < longLen; i++) {
            for (int j = 0; j < N; j++) {
                if (fit(j, i) && best[i]+1 < best[i+tams[j]]) {
                    best[i+tams[j]] = best[i]+1;
                }
            }
        }
    
        cout << "Set " << nTest++ << ": "; 
        if (best[longLen] < INF) {
            cout << best[longLen];
        } else {
            cout << "Not possible";
        }
        cout << "." << endl;
    }

    return 0;
}
