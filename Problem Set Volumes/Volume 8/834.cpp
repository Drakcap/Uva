#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


int main()
{
    
    int num, denum;
    
    while (cin >> num >> denum) {
          
          cout << "[";
          
          int primeiro = num / denum;
          
          num = num - primeiro * denum;
          
          cout << primeiro;
          
          if (num != 0) {
          
              cout << ";";
        
              
              swap(num, denum);
              
              int segundo = num / denum;
              
              cout << segundo;
    
              num = num - segundo * denum;
              int prox;          
              
              while (num > 0) {
                    
                    swap(num, denum);
                    
                    prox = num / denum;
                    
                    cout << "," << prox;
                    
                    num = num - prox * denum;
                    
              }
          }
          
          cout << "]" << endl;
    }
    
    return 0;
    
}
