#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAX 1000000

unsigned ciclos[MAX];

unsigned
num_ciclos (unsigned num) // determina o cycle length para cada numero

{
    unsigned n = 1, resto;
    
      
    while (num != 1)
    {
        n += 1;
        resto = num % 2;
        
        if (resto)
        num = 3*num + 1;
        else
        num = num/2;
        
        
        if (num < MAX && ciclos[num] != 0) {
           n += ciclos[num];
           --n;
           break;
        }
    }
    return n;
}


int 
main()
{
      for (int i = 1; i < MAX; i++) {
          ciclos[i] = 0;
      }
      
	unsigned num1, num2;
	
	while (scanf("%d %d", &num1, &num2) == 2) {
		
		unsigned n1 = num1;
		unsigned n2 = num2;
		
		if (num1 > num2)
		{
			unsigned temp = num1;
			num1 = num2;
			num2 = temp;
		}
		
		unsigned c_max = 0;
	
		while (num1 <= num2) {
		
			unsigned c;
            
            if (ciclos[num1] == 0) {
               c = num_ciclos(num1);
               ciclos[num1] = c;
            }
            else {
                 c = ciclos[num1];
            }
		
			if (c > c_max)
				c_max = c;
			
			++num1;
		}
		
		printf("%d %d %d\n", n1, n2, c_max);
		//cout << n1 << " " << n2 << " " << c_max << endl;
	}
	
	return 0;
	
}

