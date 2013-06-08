#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int cuts[52];
int dp[52][52];

int solve(int start, int end) {
    if (end - start == 1) {
        return 0;
    }
    
    if (dp[start][end] > 0) {
        return dp[start][end];
    }
    
    int thisCost = cuts[end] - cuts[start];
    int best = 10000, bestIx, cost;
    
    for (int i = start+1; i < end; i++) {
        cost = solve(start, i) + solve(i, end);
        
        if (cost < best) {
            best = cost;
            bestIx = i;
        }
    }
    
    dp[start][end] = thisCost+best;
    return dp[start][end];

}

int main()
{
    int l, c;
    
    scanf("%d", &l);
    
    while (l != 0) {
        scanf("%d", &c);
        
        cuts[0] = 0;
        
        for (int i = 0; i < c; i++) {
            scanf("%d", &cuts[i+1]);
        }
        
        cuts[c+1] = l;
        
        memset(dp, 0, sizeof(dp));
        
        printf("The minimum cutting is %d.\n", solve(0, c+1));
        
        scanf("%d", &l);
    
    }


    return 0;
}
