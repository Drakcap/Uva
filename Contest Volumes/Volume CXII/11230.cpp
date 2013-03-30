#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, r, c;
char obj[100][100];


int
go()
{
    int maxi = (n - r);
    int maxj = (m - c);
    int answ = 0;
    
    for (int i = 0; i <= maxi; i++) {
        for (int j = 0; j <= maxj; j++) {
            if (obj[i][j] == '1') {
                //cout << i << " " << j << endl;
                ++answ;
                for (int k = 0; k < r; k++) {
                    for (int l = 0; l < c; l++) {
                        obj[i+k][j+l] = (obj[i+k][j+l] == '0' ? '1' : '0');
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (! (obj[i][j] == '0')) return -1;
        }
    }

    return answ;
}

int
main()
{
    while (cin >> n >> m >> r >> c)
    {
        if (! (n | m | r | c)) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> obj[i];
        }
        cout << go() << endl;
    
    }
    
    

    return 0;
}
