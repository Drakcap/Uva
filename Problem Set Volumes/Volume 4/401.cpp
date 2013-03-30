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

set<char> equals;
set<char> noReverse;

void buildSets()
{
    equals.insert('A');
    equals.insert('H');
    equals.insert('I');
    equals.insert('M');
    equals.insert('O');
    equals.insert('T');
    equals.insert('U');
    equals.insert('V');
    equals.insert('W');
    equals.insert('X');
    equals.insert('Y');
    equals.insert('1');
    equals.insert('8');

    noReverse.insert('B');
    noReverse.insert('C');
    noReverse.insert('D');
    noReverse.insert('F');
    noReverse.insert('G');
    noReverse.insert('K');
    noReverse.insert('N');
    noReverse.insert('P');
    noReverse.insert('Q');
    noReverse.insert('R');
    noReverse.insert('4');
    noReverse.insert('6');
    noReverse.insert('7');
    noReverse.insert('9');
}

bool is_pal(char* word, int len)
{
    int ix1 = 0, ix2 = len-1;

    while (ix1 < ix2) {
        if (word[ix1] != word[ix2]) {
            return false;
        }
        ++ix1, --ix2;
    }
    return true;
}

char convert(char l)
{
    if (l == 'E') return '3';
    if (l == 'J') return 'L';
    if (l == 'L') return 'J';
    if (l == 'S') return '2';
    if (l == 'Z') return '5';
    if (l == '2') return 'S';
    if (l == '3') return 'E';
    if (l == '5') return 'Z';

    return -1;
}

bool is_mirrored(char* word, int len)
{
    static char temp[30];

    //build mirrored string
    FOR(i, 0, len) {
        if (FIND(noReverse, word[i])) {
            return false;
        } else if (FIND(equals, word[i])) {
            temp[i] = word[i];
        } else {
            temp[i] = convert(word[i]);
        }
    }

    FOR(i, 0, len) {
        if (word[i] != temp[len-i-1]) {
            return false;
        }
    }

    return true;
}

int main()
{
    char word[30];
    int len;
    bool isPal, isMir;

    buildSets();

    while (scanf("%s", word) == 1) {
        len = strlen(word);
        isPal = is_pal(word, len);
        isMir = is_mirrored(word, len);

        printf("%s", word);

        if (isPal && isMir) {
            printf(" -- is a mirrored palindrome.");
        } else if (isMir) {
            printf(" -- is a mirrored string.");
        } else if (isPal) {
            printf(" -- is a regular palindrome.");
        } else {
            printf(" -- is not a palindrome.");
        }
        printf("\n\n");
    }
    return 0;
}
