#include <iostream>
#include <string>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    
    //string p;
    char c[128];
    int n;
    
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        
        gets(c);
        stack<char> pilha;
        pilha.push('Z');
    
        int tamanho = strlen(c);
        /*
        if (tamanho == 0) {
             cout << "Yes" << endl;
             continue;
        }*/
        
        for (int j = 0; j < tamanho; j++) {
            if (c[j] == '(') {
               pilha.push('C');
            }
            else if (c[j] == '[') {
                 pilha.push('R');
            }
            else if (c[j] == ')' && pilha.top() == 'C') {
                 pilha.pop();
            }
            else if (c[j] == ']' && pilha.top() == 'R') {
                 pilha.pop();
            }
            
            else {
                 pilha.push('A');
                 break;
            }
            
        }
        
        if (pilha.top() == 'Z') {
           cout << "Yes" << endl;
        }
        
        else {
             cout << "No" << endl;
        }

          
    }
    
    
    
    
    
    return 0;
}
