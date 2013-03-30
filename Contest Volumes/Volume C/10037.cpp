#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;

struct CrossingInfo {
    int nPeople;
    int person1;
    int person2;
};

struct Solution {
    vector<CrossingInfo> crossings;
    int totalTime;
};

int crossingTimes[1000];
int nPeople;

void state0(list<int> &initialSide, list<int> &finalSide, Solution &solution)
{
    if (initialSide.size() >= 2) {
        list<int>::iterator it1 = initialSide.begin(), it2;
        it2 = it1;
        it2++;
        
        finalSide.push_front(*it2);
        finalSide.push_front(*it1);
    
        CrossingInfo info;
        info.nPeople = 2;
        info.person1 = *it1;
        info.person2 = *it2;
        solution.crossings.push_back(info);
        solution.totalTime += *it2;
        
        initialSide.erase(it1);
        initialSide.erase(it2);
    } else {
        list<int>::iterator it1 = initialSide.begin();

        finalSide.push_front(*it1);
    
        CrossingInfo info;
        info.nPeople = 1;
        info.person1 = *it1;
        solution.crossings.push_back(info);
        solution.totalTime += *it1;
        
        initialSide.erase(it1);
    }
}

void state1(list<int> &initialSide, list<int> &finalSide, Solution &solution)
{
    list<int>::iterator it = finalSide.begin();
    initialSide.push_front(*it);
    
    CrossingInfo info;
    info.nPeople = 1;
    info.person1 = *it;
    solution.crossings.push_back(info);
    solution.totalTime += *it;
    
    finalSide.erase(it);
}

void state2(list<int> &initialSide, list<int> &finalSide, Solution &solution)
{
    if (initialSide.size() >= 2) {
        list<int>::iterator it1 = initialSide.end(), it2;
        --it1;
        it2 = it1;
        --it2;
        
        //use fastest or two slowest?
        int withFaster = *initialSide.begin() + *it1 + *it2;
        int withSlowest = *it1 + (*finalSide.begin())*2;
        
        if (withSlowest <= withFaster) {
            finalSide.push_back(*it2);
            finalSide.push_back(*it1);
        
            CrossingInfo info;
            info.nPeople = 2;
            info.person1 = *it2;
            info.person2 = *it1;
            solution.crossings.push_back(info);
            solution.totalTime += *it1;
            
            initialSide.erase(it1);
            initialSide.erase(it2);
        } else {
            finalSide.push_back(*it1);
            finalSide.push_front(*initialSide.begin());
            
            CrossingInfo info;
            info.nPeople = 2;
            info.person1 = *initialSide.begin();
            info.person2 = *it1;
            solution.crossings.push_back(info);
            solution.totalTime += *it1;
        
            initialSide.erase(it1);
            initialSide.erase(initialSide.begin());
        }
    } else {
        list<int>::iterator it1 = initialSide.end();
        --it1;
        
        finalSide.push_back(*it1);
    
        CrossingInfo info;
        info.nPeople = 1;
        info.person1 = *it1;
        solution.crossings.push_back(info);
        solution.totalTime += *it1;
        
        initialSide.erase(it1);
    }
}

void state3(list<int> &initialSide, list<int> &finalSide, Solution &solution)
{
    list<int>::iterator it = finalSide.begin();
    list<int>::iterator initialIt = initialSide.begin();
    
    if (*initialIt < *it) {
        ++initialIt;
    }
    
    initialSide.insert(initialIt, *it);
    
    CrossingInfo info;
    info.nPeople = 1;
    info.person1 = *it;
    solution.crossings.push_back(info);
    solution.totalTime += *it;
    
    finalSide.erase(it);
}

Solution solve()
{
    Solution solution;
    solution.totalTime = 0;
    list<int> initialSide, finalSide;
    
    sort(crossingTimes, crossingTimes+nPeople);
    
    for (int i = 0; i < nPeople; i++) {
        initialSide.push_back(crossingTimes[i]);
    }

    int state = 0;
    
    while (! initialSide.empty()) {
        //cout << "State: " << state << endl;
        if (state == 0) {
            state0(initialSide, finalSide, solution);
        } else if (state == 1) {
            state1(initialSide, finalSide, solution);
        } else if (state == 2) {
            state2(initialSide, finalSide, solution);
        } else if (state == 3) {
            state3(initialSide, finalSide, solution);
        }   
    
        state = (state + 1) % 4;
    }

    return solution;
}

int main()
{
    int nTestCases;
    
    cin >> nTestCases;
    
    bool firstRun = true;
    
    while (nTestCases--) {
        if (! firstRun) {
            cout << endl;
        } else {
            firstRun = false;
        }
    
        cin >> nPeople;
        
        for (int i = 0; i < nPeople; i++) {
            cin >> crossingTimes[i];
        }
        
        Solution sol = solve();
        
        cout << sol.totalTime << endl;
        
        for (int i = 0; i < sol.crossings.size(); i++) {
            if (sol.crossings[i].nPeople == 1) {
                cout << sol.crossings[i].person1 << endl;
            } else {
                cout << sol.crossings[i].person1 << " " << sol.crossings[i].person2 << endl;
            }
        }
    }
    
    return 0;
}
