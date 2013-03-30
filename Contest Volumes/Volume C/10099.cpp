#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int dists[100][100];
int N, R, start, end, passengers;

void readInput()
{
    int n1, n2, value;
    memset(dists, INT_MAX, sizeof(dists));

    for (int i = 0; i < R; i++) {
        cin >> n1 >> n2 >> value;
        --n1; --n2; --value;
        
        dists[n1][n2] = max(dists[n1][n2], value);
        dists[n2][n1] = max(dists[n2][n1], value);
    }
    
    cin >> start >> end >> passengers;
    --start; -- end;
}

void solve(int scenario)
{
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dists[i][j] = max(dists[i][j], min(dists[i][k], dists[k][j]));
            }
        }
    }

    int lowest = dists[start][end];
    int nTrips;
    
    //cout << lowest << endl;
    
    if (lowest != 0 && start != end) {
        nTrips = passengers / lowest;
    
        if (passengers % lowest != 0) {
            ++nTrips;
        }
    } else {
        nTrips = 0;
    }
    
    cout << "Scenario #" << scenario << endl;
    cout << "Minimum Number of Trips = " << nTrips << endl;
    cout << endl;
}

int main()
{
    int scenario = 1;

    while (cin >> N >> R) {
        if (N == 0 && R == 0) {
            break;
        }
        
        readInput();
        solve(scenario++);
    }
    
    return 0;
}
