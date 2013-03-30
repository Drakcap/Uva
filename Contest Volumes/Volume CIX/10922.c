#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    
    char num[1000];
    
    while (gets(num) != 0)
    {
          
          unsigned tam = strlen(num);
          
          if (tam == 1 && num[0] == '0') { 
                  break;
          }
          
          unsigned soma = 0;
          unsigned i;
          
          for (i = 0; i < tam; i++) {
              soma += num[i] - '0';    
          }
          
          int degree = 1;
          
          while (soma != 9)
          {
                if (soma % 9 != 0) {
                   break;
                }
                
                int temp_soma = 0;
                
                while (soma != 0) {
                      temp_soma += soma % 10;
                      soma /= 10;      
                }
                
                soma = temp_soma;
                degree++;
                
          }
          
          if (soma == 9) {
                   printf(num);
                   printf(" is a multiple of 9 and has 9-degree %d.\n", degree);
          }
          else {
               printf(num);
               printf(" is not a multiple of 9.\n");     
          }
          
          
    }
    
    
    return 0;
}
