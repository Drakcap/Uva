#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct Ligacao {
    int e, w;
    
    bool operator<(const Ligacao &l) const
    {
        if (e != l.e) return e < l.e;
        return w < l.w;
    }
} ligs[1000000];

int T, N, M, K;
long long answ;
int cnt[1000];

int main()
{
    cin >> T;
    int nTest = 1;
    
    while (T--) {
        answ = 0;
        cin >> N >> M >> K;
        
        for (int i = 0; i < M; i++) {
            cnt[i] = 0;
        }
        
        for (int i = 0; i < K; i++) {
            cin >> ligs[i].e >> ligs[i].w;
            --ligs[i].e , --ligs[i].w;
        }
        sort(ligs, ligs+K);
                
        for (int i = 0; i < K; i++) {
            for (int j = ligs[i].w+1; j < M; j++) {
                answ += cnt[j];
            }
            ++cnt[ligs[i].w];
        }
    
        cout <<  "Test case " << nTest++ << ": " << answ << endl;

    }
    
    return 0;
}
