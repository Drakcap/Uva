#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool caminho_completo (vector<bool> nos, vector<bool> ligacoes)
{    /*
     for (unsigned i = 0; i < 5; i++) {
         if (nos[i] == false) {
            return false;
         }
     }*/
     
     for (unsigned j = 0; j < 8; j++) {
         if (ligacoes[j] == false) {
            return false;
         }
     }
     
     return true;
}

void calcula_caminhos (vector<bool> nos, vector<bool> ligacoes, vector<string> &caminhos, int no_actual, string caminho_actual)
{
     
     if (caminho_completo(nos, ligacoes)) {
        caminhos.push_back(caminho_actual);
     }
     
     else if (no_actual == 1) {
          
          
            if (ligacoes[0] == false) {
                string novo_caminho = caminho_actual + "2";       
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[0] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 2, novo_caminho);
            }
            
            if (ligacoes[5] == false) {
                string novo_caminho = caminho_actual + "3";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[5] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 3, novo_caminho);
            }
          
            
            if (ligacoes[2] == false) {  
                string novo_caminho = caminho_actual + "5";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[2] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 5, novo_caminho);
            }
     }
     
     else if (no_actual == 2) {
          
          if (ligacoes[0] == false) {       
                string novo_caminho = caminho_actual + "1";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[0] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 1, novo_caminho);
          }
            
            if (ligacoes[1] == false) {
                string novo_caminho = caminho_actual + "3";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[1] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 3, novo_caminho);
            }
            
            if (ligacoes[4] == false) {    
                string novo_caminho = caminho_actual + "5";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[4] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 5, novo_caminho);
            }
     }
     
     else if (no_actual == 3) {
          
          if (ligacoes[1] == false) {       
                string novo_caminho = caminho_actual + "2";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[1] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 2, novo_caminho);
          }
            
            if (ligacoes[7] == false) {
                string novo_caminho = caminho_actual + "4";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[7] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 4, novo_caminho);
            }
            
            if (ligacoes[3] == false) {    
                string novo_caminho = caminho_actual + "5";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[3] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 5, novo_caminho);
            }
            
            if (ligacoes[5] == false) {    
                string novo_caminho = caminho_actual + "1";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[5] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 1, novo_caminho);
            }
     }
     
          else if (no_actual == 4) {
          
          if (ligacoes[6] == false) {       
                string novo_caminho = caminho_actual + "5";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[6] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 5, novo_caminho);
          }
            
            if (ligacoes[7] == false) {
                string novo_caminho = caminho_actual + "3";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[7] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 3, novo_caminho);
            }
          }
          
          
          else if (no_actual == 5) {
          
          if (ligacoes[4] == false) {       
                string novo_caminho = caminho_actual + "2";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[4] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 2, novo_caminho);
          }
            
            if (ligacoes[6] == false) {
                string novo_caminho = caminho_actual + "4";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[6] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 4, novo_caminho);
            }
            
            if (ligacoes[3] == false) {    
                string novo_caminho = caminho_actual + "3";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[3] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 3, novo_caminho);
            }
            
            if (ligacoes[2] == false) {    
                string novo_caminho = caminho_actual + "1";
                vector<bool> nova_ligacoes = ligacoes;
                nova_ligacoes[2] = true;
                calcula_caminhos(nos, nova_ligacoes, caminhos, 1, novo_caminho);
            }
     }
          
          
          
     
}
                  




int main()
{
    vector<bool> nos;
    vector<bool> ligacoes;
    
    for (unsigned i = 0; i < 5; i++) {
        nos.push_back(false);
    }
    
    for (unsigned i = 0; i < 8; i++) {
        ligacoes.push_back(false);
    }
    
    vector<string> caminhos;
    calcula_caminhos(nos, ligacoes, caminhos, 1, "1");
    
    sort(caminhos.begin(), caminhos.end());
    
    for (unsigned i = 0; i < caminhos.size(); i++) {
        cout << caminhos[i] << endl;
    }
    
    
    return 0;
}
        
