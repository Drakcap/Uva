#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

struct Task {
    bool visited;
    int num;
    int nlig;
    int lig[100];
} tasks[100];

int N;
int bigger, task, cnt;

int dfs(int task)
{
    tasks[task].visited = true;
    int res = 1;

    for (int i = 0; i < tasks[task].nlig; i++) {
        if (! tasks[tasks[task].lig[i]].visited) {
            res += dfs(tasks[task].lig[i]);
        }
    }
    return res;
}

int main()
{   
    for (int i = 0; i < 100; i++) {
        tasks[i].num = i;
    }
    while (cin >> N && N != 0) 
    {
        bigger = -1;
        task = -1;
        
        for (int i = 0; i < N; i++) {
            cin >> tasks[i].nlig;
            for (int j = 0; j < tasks[i].nlig; j++) {
                cin >> tasks[i].lig[j];
                --tasks[i].lig[j];
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tasks[j].visited = false;
            }
            cnt = dfs(i);
            if (cnt > bigger) {
                bigger = cnt;
                task = i;
            }
        }
        cout << task+1 << endl;
    }
    
    return 0;
}
