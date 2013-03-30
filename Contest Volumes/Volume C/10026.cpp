#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Job {
    int duration;
    int fine;
    int ix;
    double ratio;
    
    bool operator <(const Job &j) const {
        if (abs(ratio-j.ratio) < 0.000000001) {
            return ix < j.ix;
        }
    
        return ratio < j.ratio;
    }
    
} jobs[1000];

int T, N;

int main()
{

    cin >> T;
    
    bool firstCase = true;
    
    while (T--) {
        cin >> N;
        
        for (int i = 0; i < N; i++) {
            cin >> jobs[i].duration >> jobs[i].fine;
            jobs[i].ix = i+1;
            jobs[i].ratio = (double) jobs[i].duration / (double) jobs[i].fine;
        }
        
        sort(jobs, jobs+N);
        
        if (! firstCase) {
            cout << endl;
        } else {
            firstCase = false;
        }
        
        cout << jobs[0].ix;
        
        for (int i = 1; i < N; i++) {
            cout << " " << jobs[i].ix;
        }
        
        cout << endl;
    
    }

    return 0;
}


