#include <iostream>
#include <string>
using namespace std;

int resposta;

void soma (string &s, string &c)
{
     unsigned i = 0, carry = 0;
     unsigned tam_s = s.size(), tam_c = c.size();
     
     for ( ; i < tam_s && i < tam_c; i++) {
         
         string soma = " ";
         
         soma[0] = s[tam_s - i - 1] + c[tam_c - i - 1] + carry - '0';
         
         
         if (soma[0] > '9') {
            ++resposta;
            carry = (unsigned) (soma[0] - '0') / 10;
            soma[0] = (unsigned) (soma[0] - '0') % 10 + '0';
         }
         
         else {
                    carry = 0;
         }
         
         s[tam_s - i - 1] = soma[0];
     }
     

     //as string têm o mesmo tamamnho, mas ha carry
     if (i == tam_s && i == tam_c && carry > 0) {
           string novo = " ";
           novo[0] = '0' + carry;
           novo.append(s);
           s = novo;
     }
     
     
     //a string a somar e' menor do que a original
     else if (i < tam_s) {
          
          while (carry > 0 && i < tam_s) {
                
                string soma = " ";
                
                soma[0] = s[tam_s - i - 1] + carry;
                
                if (soma[0] > '9') {
                   ++resposta;
                   carry = (unsigned) (soma[0] - '0') / 10;
                   soma[0] = (unsigned) (soma[0] - '0') % 10 + '0';
                }
                
                else {
                     carry = 0;
                }
                
                s[tam_s - i - 1] = soma[0];

                
                i++;
          }
     }
     
     //a string a somar e' maior do que a original
     else if (i < tam_c) {
          
          while (carry > 0 || i < tam_c) {
                
                string soma = " ";
                
                soma[0] = c[tam_c - i - 1] + carry;
                
                if (soma[0] > '9') {
                   ++resposta;
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
    
    string num1, num2;
    
    while (cin >> num1 >> num2) {
          
          if (num1 == "0" && num2 == "0") break;
          
          resposta = 0;
          soma(num1, num2);
          
          if (resposta == 0) {
             cout << "No carry operation." << endl;
          }
          else if (resposta == 1) {
               cout << "1 carry operation." << endl;
          }
          else {
               cout << resposta << " carry operations." << endl;
          }
                
    }
    
    return 0;
}
