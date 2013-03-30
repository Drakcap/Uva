#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
using namespace std;

struct Tree
{
       int x;
       int y;
       int z;
       int vizinho;     
};

int calc_dist (Tree &arv1, Tree &arv2)
{
    int difx = arv1.x - arv2.x;
    int dify = arv1.y - arv2.y;
    int difz = arv1.z - arv2.z;
    
    int distx = difx * difx;
    int disty = dify * dify;
    int distz = difz * difz;
    
    return (int) sqrt(distx + disty + distz);
    
}



int main()
{
    
    Tree arvores[5000];
    
    int x, y, z;
    unsigned n_arv = 0;
    
    while (scanf("%d %d %d", &x, &y, &z)) {
          
          if (x == 0 && y == 0 && z == 0) break;
          
          Tree tree;
          tree.x = x;
          tree.y = y;
          tree.z = z;
          tree.vizinho = -1;
          
          arvores[n_arv] = tree;
          
          n_arv++;
    }
    
    int n_arvores[10];
    
    for (unsigned i = 0; i < 10; i++) n_arvores[i] = 0;
    
    for (unsigned i = 0; i < n_arv; i++) {
        
        for (unsigned j = i + 1; j < n_arv; j++) {
            int dist = calc_dist(arvores[i], arvores[j]);
            
            if (dist < 10) {
               if (dist < arvores[i].vizinho || arvores[i].vizinho == -1) arvores[i].vizinho = dist;
               if (dist < arvores[j].vizinho || arvores[j].vizinho == -1) arvores[j].vizinho = dist;
            }
            
        }
        
        if (arvores[i].vizinho != -1) n_arvores[arvores[i].vizinho]++;
        
    }
    
    for (unsigned i = 0; i < 10; i++) cout << setw(4) << n_arvores[i];
    
    cout << endl; 
    
    
    
    return 0;
}
