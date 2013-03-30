#include <iostream>
#include <algorithm>
using namespace std;

int relatives[500];
int nRelatives;

int main()
{
    int nTestCases, housePosition, result;
    
    cin >> nTestCases;
    
    while (nTestCases--) {
        cin >> nRelatives;
        
        for (int i = 0; i < nRelatives; i++) {
            cin >> relatives[i];
        }
        
        sort(relatives, relatives+nRelatives);
        
        if (nRelatives % 2 == 0) {
            housePosition = (relatives[nRelatives/2] + relatives[(nRelatives-1)/2])/2;
        } else {
            housePosition = relatives[nRelatives/2];
        }
        
        result = 0;
        for (int i = 0; i < nRelatives; i++) {
            result += abs(housePosition-relatives[i]);
        }
    
        cout << result << endl;
    }
}
