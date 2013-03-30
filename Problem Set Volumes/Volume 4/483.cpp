#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    
    string linha;
    
    while (getline(cin,linha))
    {
          istringstream i(linha);
          string palavra;
          bool first_run = true;
          
          while (! i.eof()) {
                
                if (! first_run) {
                      cout << " ";
                }
                else {
                     first_run = false;
                }
                
                i >> palavra;      
                
                for (int j = palavra.size()-1; j >= 0; j--) {
                    cout << palavra[j];
                }
          }
          
          cout << endl;      
          
          
    }
    
    
    
    
    return 0;
}
