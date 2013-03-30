#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nums[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

int main()
{
    
    char exp[30];
    
    while (gets(exp) != 0) {
          
          unsigned tam = strlen(exp);
          unsigned i;
          
          for (i = 0; i < tam; i++) {
              if (exp[i] == '0' || exp[i] == '1' || exp[i] == '-') {
                 printf("%c", exp[i]);
              }
              else {
                   printf("%d", nums[exp[i] - 'A']);
              }
              
          }
          printf("\n");
          
    }
    
    return 0;
}
