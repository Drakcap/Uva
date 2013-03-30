#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

struct Carta {
    int value;
    int suit;
    
    bool operator<(const Carta &c) const
    {
        if (value != c.value) {
            return value < c.value;        
        }
        return suit < c.suit;
    }
    
    bool operator>(const Carta &c) const
    {
        if (value != c.value) {
            return value > c.value;        
        }
        return suit > c.suit;
        
    }
    
} cartas[2][30];

int T, K;
bool used[30];
int answ;

void parseCard(char c[3], Carta &card)
{
    if (c[0] == 'T') {
        card.value = 10;    
    } else if (c[0] == 'J') {
        card.value = 11;
    } else if (c[0] == 'Q') {
        card.value = 12;
    } else if (c[0] == 'K') {
        card.value = 13;
    } else if (c[0] == 'A') {
        card.value = 14;
    } else {
        card.value = c[0] - '0';   
    }
    
    if (c[1] == 'H') {
        card.suit = 4;   
    } else if (c[1] == 'S') {
        card.suit = 3;   
    } else if (c[1] == 'D') {
        card.suit = 2;   
    } else if (c[1] == 'C') {
        card.suit = 1;   
    }
    
}

int getMaior()
{
    int ix = K-1;
    for ( ; ix >= 0; ix--) {
        if (!used[ix]) {
            return ix;           
        }
    }
    return 0;
}

int getMenor()
{
    int ix = 0;
    for ( ; ix < K; ix++ ) {
        if (!used[ix]) {
            return ix;           
        }
    }
    return 0;
}

int main()
{   
    cin >> T;
    char c[3];
    
    while (T--) {
        cin >> K;
        memset(used, 0, sizeof(used));
        answ = 0;
            
        for (int i = 0; i < K; i++) {
            cin >> c;
            parseCard(c, cartas[0][i]);  
        }
        for (int i = 0; i < K; i++) {
            cin >> c;
            parseCard(c, cartas[1][i]);  
        }
        sort(cartas[0], cartas[0]+K);
        sort(cartas[1], cartas[1]+K);
        
        for (int i = K-1; i >= 0; i--) {
            int ixMaior = getMaior();
            if (cartas[1][ixMaior] > cartas[0][i]) {
                used[ixMaior] = true;
                ++answ;    
            } else {
                used[getMenor()] = true;    
            }    
            
        }
        cout << answ << endl;
        
    }
    
    
}
