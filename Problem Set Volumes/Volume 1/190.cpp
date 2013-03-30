#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

long double distancia(long double &x1, long double &y1, long double &x2, long double &y2)
{
       return (sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)));
}


int main()
{
    cout.setf(ios::fixed);
    
    long double x1;
    long double y1;
    long double x2;
    long double y2;
    long double x3;
    long double y3;

    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    
          long double s = 0.5*((x2 - x3)*(x1 - x3) - (y2 - y3)*(y3 - y1));
          long double sUnder = (x1 - x2)*(y3 - y1) - (y2 - y1)*(x1 - x3);

          if(sUnder == 0) {
	          continue;
          }

          s /= sUnder;

          long double xc = 0.5*(x1 + x2) + s*(y2 - y1); // center x coordinate
          long double yc = 0.5*(y1 + y2) + s*(x1 - x2); // center y coordinate
          long double radius = distancia(x1, y1, xc, yc);
          
          string sinalx, sinaly;
          
          double c, d, e;
          string sinalc, sinald, sinale;
          
          c = -2 * xc;
          d = -2 * yc;
          e = pow(xc, 2) + pow(yc, 2) - pow(radius, 2);
          
          if (c < 0) {
                sinalc = "-";
                c *= -1;
          } else {
                 sinalc = "+";
          }
          
          if (d < 0) {
                sinald = "-";
                d *= -1;
          } else {
                 sinald = "+";
          }
          
          if (e < 0) {
                sinale = "-";
                e *= -1;
          } else {
                 sinale = "+";
          }
          
                    if (xc < 0) {
                 sinalx = "+";
                 xc *= -1;
          } else {
                 sinalx = "-";
          }
          
          if (yc < 0) {
                 sinaly = "+";
                 yc *= -1;
          } else {
                 sinaly = "-";
          }
    
          cout << setprecision(3) << "(x " << sinalx << " " << xc << ")^2 + (y " << sinaly << " " << yc << ")^2 = "
               << radius << "^2" << endl;
               
          cout << setprecision(3) << "x^2 + y^2 " << sinalc << " " << c << "x "
               << sinald << " " << d << "y " << sinale<< " " << e << " = 0" << endl << endl;
    }
    
    return 0;
}
