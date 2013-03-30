#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
    
    char num[1000];
    
    while (gets(num) != 0) {
    
          int tam = strlen(num);
          
          if (tam == 1 && num[0] == '0') break;
          
          int conta = 0;
          int sinal = 1;
          int i;
          
          for (i = tam-1; i >= 0; i--) {
              if (sinal)
                 conta += num[i] - '0';
              else
                  conta -= num[i] - '0';
                  
              sinal = (sinal == 0 ? 1 : 0);    
          }
          
          printf(num);
          
          if (conta % 11 == 0) {
             printf(" is a multiple of 11.\n");
          }
          else {
              printf(" is not a multiple of 11.\n");           
          }
          
              
          
          
    }
    
    return 0;
    
    
    
}
