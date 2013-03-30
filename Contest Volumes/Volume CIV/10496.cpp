#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_B 10
#define INFINITO 10000

int n_beepers;

struct Ponto
{
       int x;
       int y;
       
};

Ponto beepers[MAX_B];

int calc_dist(Ponto& p1, Ponto& p2)
{
    return (abs(p1.x -p2.x) + abs(p1.y - p2.y));
}

void calc_dist(Ponto &karel, vector<int> &perms, int &best)
{
     
     int actual = 0;
     Ponto pos;
     pos.x = karel.x;
     pos.y = karel.y;
     
     for (int i = 0; i < n_beepers; i++) {
         actual += calc_dist(pos, beepers[perms[i]]);
         pos.x = beepers[perms[i]].x;
         pos.y = beepers[perms[i]].y;
         
         if (actual >= best) {
            return;
         }
     }
     actual += calc_dist(karel, pos);
     
     if (actual < best) best = actual;
     
}

int main()
{
    
    int n_cenarios;
    
    cin >> n_cenarios;
    
    for (int i = 0; i < n_cenarios; i++) {
        
        int dimX, dimY;
        cin >> dimX >> dimY;
        
        Ponto karel;
        
        cin >> karel.x;
        cin >> karel.y;
        
        cin >> n_beepers;
        
        for (int j = 0; j < n_beepers; j++) {
            cin >> beepers[j].x;
            cin >> beepers[j].y;
        }
        vector<int> perms;
        
        for (int j = 0; j < n_beepers; j++) {
            perms.push_back(j);
        }
        
        int best = INFINITO;
        
        calc_dist(karel, perms, best);
    
        while (next_permutation(perms.begin(), perms.end())) {
              calc_dist(karel, perms, best);
        }
        
        cout << "The shortest path has length " << best << endl;
              
    
        
    }
    
    return 0;
}
    
    
