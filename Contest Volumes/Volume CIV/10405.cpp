#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

#define MAX 1000

char X[MAX], Y[MAX];
int i, j, m, n, c[MAX][MAX], b[MAX][MAX];

int LCSlength()
{
	//m = strlen(X);
	//n = strlen(Y);
	
	for (int i= 1; i <= m ; i++) c[i][0] = 0;
	for (int j=0; j<= n; j++)	c[0][j] = 0;
	
	for (int i=1; i <= m ;i++)
		for (int j=1; j <= n ;j++)
			if (X[i-1]==Y[j-1])
			{
				c[i][j] = c[i-1][j-1] +1 ;
				b[i][j] = 1;
			}
			else if (c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			}
			else
			{ 
				c[i][j] = c[i][j-1];
				b[i][j] =3; 
			}
	
	return c[m][n];
}


int main()
{
    
    string linha1, linha2;
    
    
    while (getline(cin, linha1)) {
        
        getline(cin, linha2);  
  		for (unsigned i = 0; i < linha1.size(); i++) {
			X[i] = linha1[i];
		}
		
		for (unsigned i = 0; i < linha2.size(); i++) {
			Y[i] = linha2[i];
		}
		
		m = linha1.size();
		n = linha2.size();
		
        cout << LCSlength() << endl;
          
          
    }
    return 0;
    
}
