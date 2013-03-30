#include <iostream>
#include <string>
using namespace std;


bool isleap(string &num)
{
     
     bool div100 = (num[num.size()-1] == '0' && num[num.size()-2] == '0');
     
     int temp = num[num.size()-1] + num[num.size()-2]*10;
     
     bool div4 = (temp % 4 == 0);

     int num4 = (num[num.size()-1] - '0');
     num4 += (num[num.size()-2] - '0') * 10;
     num4 += (num[num.size()-3] - '0') * 100;
     num4 += (num[num.size()-4] - '0') * 1000;
     
     bool div400 = (num4 % 400 == 0);
     
     if (!div4) {
        return false;
     }
     
     if (div100) {
        return (div400);
     }
     
     return true;
}

bool isHuluculu(string &num)
{
     long long int soma = 0;
     
     for (unsigned i = 0; i < num.size(); i++) {
         soma += num[i] - '0';
     }
     
     bool cinco = (num[num.size()-1] == '0' || num[num.size()-1] == '5');
     
     
     return (cinco && (soma % 3 == 0));
}

bool isBulukulu(string &num)
{
     long int soma = 0;
     bool sinal = true;
     
     for (unsigned i = 0; i < num.size(); i++) {
         if (sinal) {
            soma += num[i] - '0';
         }
         else soma -= num[i] - '0';
         
         sinal = !sinal;
     }
     
     bool div11 = (soma == 0);
     bool div5 = (num[num.size()-1] == '5' || num[num.size()-1] == '0');
     
     return (div5 && div11);
     
}



int main()
{
    
    string ano;
    
    bool primeiro = true;
    
    while (cin >> ano)
    {
          
          if (! primeiro) cout << endl;
          
          primeiro = false;
          
          bool is_smtg = false;
          
          bool is_leap = isleap(ano);
          bool is_hul = isHuluculu(ano);
          bool is_buk = false;
          
          if (is_leap) is_buk = isBulukulu(ano);
          
          is_smtg = is_leap || is_hul;
          
          if (is_leap) cout << "This is leap year." << endl;
          if (is_hul) cout << "This is huluculu festival year." << endl;
          if (is_buk) cout << "This is bulukulu festival year." << endl;
          
          
          if (! is_smtg) {
                cout << "This is an ordinary year." << endl;
          }
          
          
    }
    
    
    
    return 0;
}
