#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

struct State {
    int vals[4];
    int value, nMoves;
};

int N, nForbidden;
State initialState, finalState;
bool processed[10000];
set<int> forbidden;

int toStateVal(int val1, int val2, int val3, int val4)
{
    return val1 * 1000 + val2 * 100 + val3 * 10 + val4;
}

vector<State> nextStates(State state)
{
    vector<State> states;
    int mult = 1000;
    
    for (int i = 0; i < 4; i++) {
        //rotate left
        State newState = state;
        newState.vals[i] = (newState.vals[i] + 1) % 10;
        newState.value = toStateVal(newState.vals[0], newState.vals[1], newState.vals[2], newState.vals[3]);
        ++newState.nMoves;
        
        if (!processed[newState.value] && forbidden.find(newState.value) == forbidden.end()) {
            states.push_back(newState);
        }
        
        //rotate right
        newState = state;
        newState.vals[i] = (newState.vals[i] == 0 ? 9 : newState.vals[i] - 1);
        newState.value = toStateVal(newState.vals[0], newState.vals[1], newState.vals[2], newState.vals[3]);
        ++newState.nMoves;
        
        if (!processed[newState.value] && forbidden.find(newState.value) == forbidden.end()) {
            states.push_back(newState);
        }
    }
    
    return states;
}

int go()
{
    queue<State> states;
    State nextState;

    states.push(initialState);
    processed[initialState.value] = true;
    
    while (! states.empty()) {
        nextState = states.front();
        states.pop();
        
        if (nextState.value == finalState.value) {
            return nextState.nMoves;
        }
        
        vector<State> statesToAdd = nextStates(nextState);
        
        for (int i = 0; i < statesToAdd.size(); i++) {
            states.push(statesToAdd[i]);
            processed[statesToAdd[i].value] = true;
        }
    }

    return -1;
}

int main()
{
    cin >> N;
    
    int val1, val2, val3, val4;
    
    while (N--) {
        forbidden.clear();
        memset(processed, 0, sizeof(processed));
    
        cin >> initialState.vals[0] >> initialState.vals[1] >> initialState.vals[2] >> initialState.vals[3];
        initialState.value = toStateVal(initialState.vals[0], initialState.vals[1], initialState.vals[2], initialState.vals[3]);
        initialState.nMoves = 0;
        
        cin >> finalState.vals[0] >> finalState.vals[1] >> finalState.vals[2] >> finalState.vals[3];
        finalState.value = toStateVal(finalState.vals[0], finalState.vals[1], finalState.vals[2], finalState.vals[3]);
        
        cin >> nForbidden;
        
        for (int i = 0; i < nForbidden; i++) {
            cin >> val1 >> val2 >> val3 >> val4;
            forbidden.insert(toStateVal(val1, val2, val3, val4));
        }
    
        cout << go() << endl;
    
    }
    
    return 0;
}
