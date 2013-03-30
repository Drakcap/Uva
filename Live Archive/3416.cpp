#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define MAX 1000

struct Person {
    int f, b;
} people[MAX+10];

int N, F, B;

int calcBoxes(int time)
{
    int answ = 0;
    int nCaixas = 0;
    int t, restante;
    for (int i = 0; i < N; i++) {
        nCaixas = 0;
        t = 0;
        if (people[i].b) {
            t += (F - people[i].f + F);
        } else {
            t = people[i].f;
        }
        restante = time-t;
        nCaixas = restante/(2*F); //subir e descer
        if (restante % (2*F) >= F) ++nCaixas; //so subir
        //cout << i << " " << nCaixas << endl;
        answ += nCaixas;
    }
    
    return answ;
}   

int bs(int start, int end)
{
    //cout << start << " " << end << endl;
    if (start == end-1) {
        return end;
    }
    
    int middle = ((long long)start+(long long)end)/(long long)2;
    int nB = calcBoxes(middle);
    //cout << "calculado: " << middle << " " << nB << endl;
    
    if (nB >= B) {
        return bs(start, middle);
    } else {
        return bs(middle, end);
    }

}

int main()
{
    int T;
    cin >> T;
    
    while (T--) {
        cin >> N >> F >> B;
        for (int i = 0; i < N; i++) {
            cin >> people[i].f >> people[i].b;
        }
        //cout << calcBoxes(8) << endl;
        cout << bs(0, 2*F*B) << endl;
    }
    
    return 0;
}
