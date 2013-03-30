#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100000

int values[MAXN];
int somas[MAXN];
int N, S;
int answ;
int ix;

int bs(int start, int end, int value)
{
    if (end < start) {
        return -1;
    }
    int middle = (start+end)/2;
    
    if (somas[middle] <= value) {
        return max(middle, bs(middle+1, end, value));
    } else {
        return bs(start, middle-1, value);
    }
}

int main()
{

    while (cin >> N >> S) {
        answ = -1;
        for (int i = 0; i < N; i++) {
            cin >> values[i];
            if (i > 0) somas[i] = values[i-1] + somas[i-1];
        }
        for (int i = 0; i < N; i++) {
            ix = bs(0, i, values[i]+somas[i]-S);
            //cout << i << " " << ix << " " << values[i]+somas[i]-S << endl;
            if (ix != -1 && ((i - ix + 1) < answ || answ == -1)) {
                answ = i - ix + 1;
            }
        }
        cout << (answ == -1 ? 0 : answ) << endl;
    
    }
    
    return 0;
}
