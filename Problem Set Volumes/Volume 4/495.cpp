#include <iostream>
#include <string>
using namespace std;


void soma (string &s, string &c)
{
     unsigned i = 0, carry = 0;
     
     for ( ; i < s.size() && i < c.size(); i++) {
         
         string soma = " ";
         
         soma[0] = s[s.size() - i - 1] + c[c.size() - i - 1] + carry - '0';
         
         
         if (soma[0] > '9') {
            carry = (unsigned) (soma[0] - '0') / 10;
            soma[0] = (unsigned) (soma[0] - '0') % 10 + '0';
         }
         
         else {
                    carry = 0;
         }
         
         s[s.size() - i - 1] = soma[0];
     }
     

     //as string têm o mesmo tamamnho, mas ha carry
     if (i == s.size() && i == c.size() && carry > 0) {
           string novo = " ";
           novo[0] = '0' + carry;
           novo.append(s);
           s = novo;
     }
     
     
     //a string a somar e' menor do que a original
     else if (i < s.size()) {
          
          while (carry > 0 && i < s.size()) {
                
                string soma = " ";
                
                soma[0] = s[s.size() - i - 1] + carry;
                
                if (soma[0] > '9') {
                   carry = (unsigned) (soma[0] - '0') / 10;
                   soma[0] = (unsigned) (soma[0] - '0') % 10 + '0';
                }
                
                else {
                     carry = 0;
                }
                
                s[s.size() - i - 1] = soma[0];

                
                i++;
          }
     }
     
     //a string a somar e' maior do que a original
     else if (i < c.size()) {
          
          while (carry > 0 || i < c.size()) {
                
                string soma = " ";
                
                soma[0] = c[c.size() - i - 1] + carry;
                
                if (soma[0] > '9') {
                   carry = (unsigned) (soma[0] - '0') / 10;
                   soma[0] = (unsigned) (soma[0] - '0') % 10 + '0';
                }
                
                else {
                     carry = 0;
                }
                
                string novo = "";
                novo.append(soma);
                novo.append(s);
                s = novo;
                
                i++;
          }
     }                 
                
}
         
         


int main()
{
         
    string *calculados = new string[5001];
    
    
    calculados[0] = "0";
    calculados[1] = "1";
    string temp = "1";
    
    for (unsigned i = 2; i <= 5000; i++) {
        calculados[i] = temp;
        soma (temp, calculados[i-1]);
    }
    
    unsigned num;
    
    while (cin >> num) {
          
          
          cout << "The Fibonacci number for " << num << " is " << calculados[num] << endl;
          
    }
    
    return 0;
    
}
        
        
        
