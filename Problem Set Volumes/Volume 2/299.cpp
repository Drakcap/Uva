#include <iostream>
using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    for (int k = 0; k < N; k++) {
        
        int L;
        
        cin >> L;
          
          int* nums = new int[L];
          
          for (int i = 0; i < L; i++) {
              cin >>  nums[i];
          }
          
          int inversoes = 0;
          
          for (int i = 0; i < L-1; i++) {
              
              for (int j = i + 1; j < L; j++) {
                  
                  if (nums[i] > nums[j]) {
                        inversoes++;
                  }
              }
          }
          
          cout << "Optimal train swapping takes " << inversoes << " swaps." << endl;      
    }
    
    return 0;
}
