#include <iostream>
using namespace std;


int main()
{
    
    long long unsigned a, b;
    
    while (cin >> a >> b) 
    {
          long long unsigned dif;
          
          if (a > b) dif = a-b;
          else dif = b-a;
          
          
          cout << dif << endl;
    }
    
    
    return 0;
}
