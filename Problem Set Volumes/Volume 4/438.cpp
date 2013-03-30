#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

#define PI 3.141592653589793

long double distancia (long double x1, long double y1, long double x2, long double y2)
{
     return sqrt ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );    
}


int main()
{
    
    long double x1;
    long double y1;
    long double x2;
    long double y2;
    long double x3;
    long double y3;
    
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
    {
          long double s = 0.5*((x2 - x3)*(x1 - x3) - (y2 - y3)*(y3 - y1));
          long double sUnder = (x1 - x2)*(y3 - y1) - (y2 - y1)*(x1 - x3);          
          
          s /= sUnder;

          long double xc = 0.5*(x1 + x2) + s*(y2 - y1); // center x coordinate
          long double yc = 0.5*(y1 + y2) + s*(x1 - x2); // center y coordinate
          
          long double raio = distancia (xc, yc, x1, y1);
          
          cout.setf(ios::fixed);
          
          cout << setprecision(2) << 2 * PI * raio << endl;          
          
          
    }
    
    
    
    
    
    return 0;
}
