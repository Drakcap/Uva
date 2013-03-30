#include<iostream>
#include<string.h>
using namespace std;

int main(){

    char a[100001],b[1001];
    
    int k,i,j,c,d;
    
    cin >> c;               //numero de test cases

    for(i=0; i<c; i++) {
             cin >> a;      //string principal
             cin >> d;      //numero de queries
             
             for(j=0; j<d; j++) {
                      cin >> b;      //le uma query
                      int sw=0,z=0,len2=strlen(b);
                      
                      for(k=0 ; ; k++) {
                              
                              if(sw==len2)        //encontrou ocorrencia
                                 break;
                              
                              if(b[sw] == a[z]) { //faz match
                                       sw++;
                                       z++;
                              }
                              else {
                                   z++;
                                   sw=0;
                              }
                              
                              if(z == len2)
                                   break;
                      }
                      
                      
                      if(sw == len2)
                            cout << "y" << endl;
                            
                      else
                          cout << "n" << endl;
             }
    }
    
    return 0;
} 
