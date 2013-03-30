#include <stdio.h>
#include <stdlib.h>
using namespace std;

char ascii[128];

void inicia() {
     
     ascii[(int)' '] = ' ';
     
     ascii[(int)'0'] = '9';
     ascii[(int)'1'] = '`';
     ascii[(int)'-'] = '0';
     ascii[(int)'='] = '-';
     
     int i;
     
     for (i = (int) '2'; i <= (int) '9'; i++) {
         ascii[i] = i-1;
     }
     
    ascii[(int)'W'] = 'Q';
    ascii[(int)'E'] = 'W';
    ascii[(int)'R'] = 'E';
    ascii[(int)'T'] = 'R';
    ascii[(int)'Y'] = 'T';
    ascii[(int)'U'] = 'Y';
    ascii[(int)'I'] = 'U';
    ascii[(int)'O'] = 'I';
    ascii[(int)'P'] = 'O';
    ascii[(int)'['] = 'P';
    ascii[(int)']'] = '[';
    ascii[92] = ']';
    
    ascii[(int)'S'] = 'A';
    ascii[(int)'D'] = 'S';
    ascii[(int)'F'] = 'D';
    ascii[(int)'G'] = 'F';
    ascii[(int)'H'] = 'G';
    ascii[(int)'J'] = 'H';
    ascii[(int)'K'] = 'J';
    ascii[(int)'L'] = 'K';
    ascii[(int)';'] = 'L';
    
    ascii[(int)'X'] = 'Z';
    ascii[(int)'C'] = 'X';
    ascii[(int)'V'] = 'C';
    ascii[(int)'B'] = 'V';
    ascii[(int)'N'] = 'B';
    ascii[(int)'M'] = 'N';
    ascii[(int)','] = 'M';
    ascii[(int)'.'] = ',';
    ascii[(int)'/'] = '.';
    
    ascii[39] = ';';
}



int main()
{
    
    char car;
    inicia();
    
    while ((car = getchar()) != EOF) {

          if (car == '\n') {
                  printf("%c",car);
          }
          
          else {
               printf("%c",ascii[(int)car]);
          }        
          
          
          
    }
    //printf("%c",'\n');
    
    return 0;
}
