#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct OutOfPlace {
    string name;
    int finalPosition;
    
    bool operator<(const OutOfPlace &o) const {
        return finalPosition < o.finalPosition;
    }
};

int T, N;
string originalPositions[200], finalPositions[200];

int main()
{
    string line;
    
    getline(cin, line);
    istringstream issT(line);
    issT >> T;
    
    while (T--) {
        getline(cin, line);
        istringstream iisN(line);
        iisN >> N;
        
        for (int i = 0; i < N; i++) {  
            getline(cin, originalPositions[i]);
        }
        
        for (int i = 0; i < N; i++) {
            getline(cin, finalPositions[i]);
        }
        
        int currentOriginal = N-1;
        vector<OutOfPlace> outOfPlace;
        
        while (currentOriginal >= 0) {
            if (finalPositions[currentOriginal+outOfPlace.size()] != originalPositions[currentOriginal]) {      
                OutOfPlace out;
                out.name = originalPositions[currentOriginal];
                
                for (int i = 0; i < N; i++) {
                    if (finalPositions[i] == out.name) {
                        out.finalPosition = i;
                        break;
                    }
                }
                
                outOfPlace.push_back(out);
            }
            
            --currentOriginal;
        }
        
        sort(outOfPlace.begin(), outOfPlace.end());
        
        for (int i = outOfPlace.size() - 1; i >= 0; i--) {
            cout << outOfPlace[i].name << endl;
        }
        
        cout << endl;
    }

    return 0;
}
