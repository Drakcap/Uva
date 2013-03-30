#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long int N;
    
    while (cin >> N) {
          
         vector<long int> nums;
          
          for (long int i = 0; i < N; i++) {
              long int temp;
              cin >> temp;
              nums.push_back(temp);
          }
          
          long unsigned inversoes = 0;
          bool swaped = false;
          
          do {
              
              N--;
              swaped = false;
              
              for (long int i = 0; i < N; i++) {
              
                  if ( nums[i] > nums[i + 1]) {
                       long int temp = nums[i];
                       nums[i] = nums[i + 1];
                       nums[i + 1] = temp;
                       swaped = true;
                       inversoes++;
                  }
              }
          } while (swaped);
          
          cout << "Minimum exchange operations : " << inversoes << endl;      
    }
    
    return 0;
}
