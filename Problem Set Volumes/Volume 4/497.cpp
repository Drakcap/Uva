#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

#define MAX 100000

int bs (int elem[], int best[], int nb, int x)
{
       int i = 0;
       int j = nb - 1;
       int mid = 0;
       
       while (i <= j) {
             mid = (i + j) / 2;
             
             if (x < elem[best[mid]]) j = mid - 1;
             else if (x > elem[best[mid]]) i = mid + 1;
             else return mid;
       }
       
       if (mid < nb && x > elem[best[mid]]) ++mid;
       if (mid > 0 && x < elem[best[mid-1]]) --mid;
       
       return mid;
}

int lis (int elem[], int prev[], int ne)
{
    int best[MAX], k = 0;
    
    for (int i = 0; i < ne; i++) {
        
        int j = bs (elem, best, k, elem[i]);
        if (j == 0) prev[i] = -1;
        else prev[i] = best[j-1];
        best[j] = i;
        if (j+1>k) k = j+1;
    }
    return best[k-1];
    
}


int main()
{
    int n_tests;
    bool first_run = true;
    string l;
    getline(cin,l);
    istringstream is(l);
    
    is >> n_tests;
    getline(cin,l); //le linha em branco
    for ( ; n_tests; --n_tests) {
    
        int elem[MAX];
        int prev[MAX];
        int ne = 0;
        string linha;
        

        
        while (getline(cin, linha) && linha != "") {
              //cout << linha << endl;
              //cout << (linha == "") << endl;
              istringstream str(linha);
              
              str >> elem[ne];
              //cout << elem[ne] << endl;
              ++ne;
        }
        
        int e = lis(elem, prev, ne);
        list<int> sequencia;
        
        while (e != -1) {
              sequencia.push_front(elem[e]);
              e = prev[e];
        }
        
        if (! first_run) {
              cout << endl;
        }
        else {
             first_run = false;
        }
                
        cout << "Max hits: " << sequencia.size() << endl;
        
        list<int>::iterator it = sequencia.begin();
        

        
        for ( ; it != sequencia.end(); it++) {
            cout << *it << endl;
        }
        
    }
    
    
    return 0;
}
