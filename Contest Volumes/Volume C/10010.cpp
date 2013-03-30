#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

struct State {
    bool visited[60][60];
    int nextLetter;
    int m, n;
    int deltaM, deltaN;
};

int nCases, m, n;
char grid[60][60];
string words[30];
int nWords;

void readInput()
{
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> grid[i];
        for (int j = 0; j < n; j++) {
            grid[i][j] = tolower(grid[i][j]);
        }
        //cout << grid[i] << endl;
    }
        
    cin >> nWords;
    
    for (int i = 0; i < nWords; i++) {
        cin >> words[i];
        for (int j = 0; j < words[i].size(); j++) {
            words[i][j] = tolower(words[i][j]);
        }
        //cout << words[i] << endl;
    }
}

bool go(int wordIx, int startM, int startN)
{
    string word = words[wordIx];

    if (word[0] != grid[startM][startN]) {
        return false;
    }

    queue<State> states;
    State initialState;
    memset(initialState.visited, 0, sizeof(initialState.visited));
    initialState.nextLetter = 1;
    initialState.m = startM;
    initialState.n = startN;
    initialState.visited[startM][startN] = true;
    initialState.deltaM = initialState.deltaN = 0;
    states.push(initialState);
    int nextM, nextN;
    
    while (! states.empty()) {
        State nextState = states.front();
        states.pop();
    
        //cout << nextState.m << " " << nextState.n << endl;
    
        if (nextState.nextLetter >= word.size()) {
            return true;
        }
        
        if (nextState.deltaM != 0 || nextState.deltaN != 0) {
            nextM = nextState.m + nextState.deltaM;
            nextN = nextState.n + nextState.deltaN;
            
            if (nextM >= 0 && nextM < m && nextN >= 0 && nextN < n && 
                !nextState.visited[nextM][nextN] && 
                grid[nextM][nextN] == word[nextState.nextLetter]) {
                
                State newState = nextState;
                newState.visited[nextM][nextN] = true;
                newState.m = nextM;
                newState.n = nextN;
                ++newState.nextLetter;
                
                states.push(newState);
            }
            
        } else {
        
            for (int deltaM = -1; deltaM <= 1; deltaM++) {
                for (int deltaN = -1; deltaN <= 1; deltaN++) {
                    if (deltaM == 0 && deltaN == 0) {
                        continue;
                    }
                
                    nextM = nextState.m + deltaM;
                    nextN = nextState.n + deltaN;
                    
                    if (nextM >= 0 && nextM < m && nextN >= 0 && nextN < n && 
                        !nextState.visited[nextM][nextN] && 
                        grid[nextM][nextN] == word[nextState.nextLetter]) {
                        
                        State newState = nextState;
                        newState.visited[nextM][nextN] = true;
                        newState.m = nextM;
                        newState.n = nextN;
                        newState.deltaM = deltaM;
                        newState.deltaN = deltaN;
                        ++newState.nextLetter;
                        
                        states.push(newState);
                    }
                }
            }
        }
    
    }
    
    return false;
}

void solveWord(int word)
{
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
            if (go(word, j, k)) {
                cout << j + 1 << " " << k + 1 << endl;
                return;
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < nWords; i++) {
        solveWord(i);
    }
}

int main()
{
    cin >> nCases;
    
    for (int i = 0; i < nCases; i++) {
        if (i > 0) {
            cout << endl;
        }
        
        readInput();
        solve();
    }

    return 0;
}
