#include <iostream>
using namespace std;

int main()
{
    
    long long unsigned num;
    
    long long unsigned moedas[5]={1,5,10,25,50};
    long long unsigned count[30001];
    
    count[0] = 1;
    //count[1]= 1;

    for(long long unsigned i=2; i<= 30000; i++) {
       count[i]=0;
    }

    for(long long unsigned i=0; i < 5; i++) {
       
       for(long long unsigned j = moedas[i]; j <= 30000; j++){
         
         long long unsigned temp = j-moedas[i] ;
         
         count[j] += count[temp];
        }
    } 
    
    
    while (cin >> num) {
          
          if (count[num] == 1) {
             cout << "There is only 1 way to produce " << num << " cents change." << endl;
          }
          
          else {
               cout << "There are " << count[num] << " ways to produce " << num << " cents change." << endl;
          }
    }
    
    return 0;
    
}
