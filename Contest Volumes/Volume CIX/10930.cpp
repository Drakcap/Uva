#include <iostream>
#include <string>
#include <list>
using namespace std;

#define MAX 1100

bool somas[MAX];
list<int> l_somas;
int seq[30];

int main()
{
    int D;
    int n_case = 0;
    
    while (cin >> D)
    {
          ++n_case;
          
          l_somas.clear();
          
          for (int i = 0; i < MAX; i++) {
              somas[i] = false;
          }
          
          bool is_seq = true;
          //int n_nums;
          
          cin >> seq[0];
          
          cout << "Case #" << n_case << ": " << seq[0];
          
          for (int i = 1; i < D; i++) {
            
             cin >> seq[i];
             cout << " " << seq[i];
             
             if (seq[i-1] >= seq[i]) { //numero seguinte e' menor ou igual ao numero anterior
                is_seq = false;
             }
             
             if (somas[seq[i]] == true) { //o numero pode ser formado com soma de numeros anteriores
                is_seq = false;                 
             }
             
             
             list<int>::iterator it = l_somas.begin();
             list<int> temp = l_somas;
             
             //forma somas com as somas anteriores
             for ( ; it != l_somas.end(); it++) {
                 int soma = seq[i] + *it;
                 if (soma < MAX && somas[soma] == false) {
                    somas[soma] = true;
                    temp.push_back(soma);
                 }        
             }
             
             l_somas = temp;
             
             //forma somas com os numeros que ja sairam na sequencia
             for (int j = 0; j < i; j++) {
                 int soma = seq[j] + seq[i];
                 if(soma < MAX && somas[soma] == false) {
                    somas[soma] = true;
                    l_somas.push_back(soma);
                 }      
             }
             
             
             
             
          }
          
          cout << endl;
          
          if (is_seq) {
             cout << "This is an A-sequence." << endl;
          }
          else {
               cout << "This is not an A-sequence." << endl;
          } 
          
         // cout << l_somas.size() << endl;
          /*
          list<int>::iterator it = l_somas.begin();
          
          for ( ; it != l_somas.end(); it++) {
              cout << *it << " ";
          }
          cout << endl;*/
          
          
          
    }
    
    
    
    return 0;
}
