#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define TAM_ALF 26

bool is_minuscula(char letra)
{
     if (letra >= 'a' && letra <= 'z')
        return true;
     
     return false;
 
}

bool is_maiuscula(char letra)
{
     if (letra >= 'A' && letra <= 'Z')
        return true;
     
     return false;
 
}

int main()
{
    
    string linha;
    
    int maiusculas[TAM_ALF];
    int minusculas[TAM_ALF];
    
    while (getline(cin, linha)) {
          
          for (int i = 0; i < TAM_ALF; i++) {
              maiusculas[i] = 0;
              minusculas[i] = 0;
          }
          
          for (unsigned i = 0; i < linha.size(); i++) {
              if (is_minuscula(linha[i])) {
                 minusculas[linha[i]-'a']++;
              }
              else if (is_maiuscula(linha[i])) {
                 maiusculas[linha[i]-'A']++;
              }
          }
          
          vector<char> maiores;
          int maior = 0;
          
          for (int i = 0; i < TAM_ALF; i++) {
              if (maiusculas[i] > maior) {
                 maiores.clear();
                 maior = maiusculas[i];
                 maiores.push_back(i + 'A');
              }
              else if (maiusculas[i] == maior) {
                   maiores.push_back(i + 'A');
              }
          }
          
          for (int i = 0; i < TAM_ALF; i++) {
              if (minusculas[i] > maior) {
                 maiores.clear();
                 maior = minusculas[i];
                 maiores.push_back(i + 'a');
              }
              else if (minusculas[i] == maior) {
                   maiores.push_back(i + 'a');
              }
          }
          
          if (maior > 0) {
              for (unsigned i = 0; i < maiores.size(); i++) {
                  cout << maiores[i];
              }
              cout << " " << maior << endl;
          }
    }
    
    return 0;
}
