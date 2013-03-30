#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int value (char c)
{
    
    if (c >= 'a' && c <= 'z') {
          return (c - 'a' + 1);
    }
    else {
         return (c - 'A' + 27);
    }
    
    
}


int is_prime(const unsigned num)
{
     unsigned test_num, test_limit;
     
     if (num == 1)
        return 1;
     
     else if (num == 2)
          return 1;
     
     if (num % 2 == 0)
        return 0;
     
     test_num = 3;
     test_limit = num;
     
     while (test_limit > test_num) {
           
           if (num % test_num == 0)
              return 0;
           
           test_limit = num / test_num;
           
           test_num += 2;
     }
     
     return 1;
}

int main()
{
    
    char word[20];
    
    while (gets(word) != 0) {
    
          int tam = strlen(word);
          int soma = 0, i;
          
          for (i = 0; i < tam; i++) {
              soma += value(word[i]);    
          }
          
          if (is_prime(soma)) {
             printf("It is a prime word.\n");
          }
          else {
               printf("It is not a prime word.\n");
          }
                
          
          
    }
    
    
    
    return 0;
}
