#include <iostream>
#include <list>
#include <math.h>
using namespace std;

/*
list<long long unsigned> calcula_quirk_quatro()
{
          list<long long unsigned> lista;
          
          for (long long unsigned i = 0; i < 9999; i++) {
          
              long long unsigned parte_esquerda = i / 100;
              long long unsigned parte_direita = i % 100;
              long long unsigned soma = parte_direita + parte_esquerda;
                   
              if (pow (soma, 2) == i)  {
                 lista.push_back(i);
              }
                 
          }
          
          return lista;
}

list<long long unsigned> calcula_quirk_seis()
{
          list<long long unsigned> lista;
          
          for (long long unsigned i = 0; i < 999999; i++) {
          
              long long unsigned parte_esquerda = i / 1000;
              long long unsigned parte_direita = i % 1000;
              long long unsigned soma = parte_direita + parte_esquerda;
                   
              if (pow (soma, 2) == i)  {
                 lista.push_back(i);
              }
                 
          }
          
          return lista;
}

list<long long unsigned> calcula_quirk_oito()
{
          list<long long unsigned> lista;
          
          for (long long unsigned i = 0; i < 99999999; i++) {
          
              long long unsigned parte_esquerda = i / 10000;
              long long unsigned parte_direita = i % 10000;
              long long unsigned soma = parte_direita + parte_esquerda;
                   
              if (pow (soma, 2) == i)  {
                 lista.push_back(i);
              }
                 
          }
          
          return lista;
}
*/
void imprime_dois()
{
     cout << "00" << endl;
     cout << "01" << endl;
     cout << "81" << endl;
}

void imprime_quatro()
{
     cout<<"0000"<<endl;
     cout<<"0001"<<endl;
     cout<<"2025"<<endl;
     cout<<"3025"<<endl;
     cout<<"9801"<<endl; 
}
     

void imprime_seis()
{
     cout << "000000" << endl;
     cout << "000001" << endl;
     cout << "088209" << endl;
     cout << "494209" << endl;
     cout << "998001" << endl;
}

void imprime_oito()
{
     cout << "00000000" << endl;
     cout << "00000001" << endl;
     cout << "04941729" << endl;
     cout << "07441984" << endl;
     cout << "24502500" << endl;
     cout << "25502500" << endl;
     cout << "52881984" << endl;
     cout << "60481729" << endl;
     cout << "99980001" << endl;
}


int main()
{
    
    /*
    list<unsigned> dois_digitos;
    dois_digitos.push_back(0);
    dois_digitos.push_back(1);
    dois_digitos.push_back(81);
    
    list<long long unsigned> quatro_digitos = calcula_quirk_quatro();
    //list<long long unsigned> seis_digitos = calcula_quirk_seis();
    //list<long long unsigned> oito_digitos = calcula_quirk_oito();
    
    
    list<long long unsigned>::iterator it = quatro_digitos.begin();
    
    for ( ; it != quatro_digitos.end(); it++) {
        cout << *it << endl;
    }
    
    cin.get();*/
    
    int n_digitos;
    
    while (cin >> n_digitos) {
          
          switch (n_digitos) {
                 case 2:
                      imprime_dois();
                      break;
                 case 4:
                      imprime_quatro();
                      break;
                 case 6:
                      imprime_seis();
                      break;
                 case 8:
                      imprime_oito();
                      break;
                 }
    }
    
    
    return 0;
}
