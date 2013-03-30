#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


struct ascii {
       
       int num;
       int freq;
};
       

char linha[1000];

ascii freq[128];

int compare(const void *a,const void *b) {
    
    ascii c,d;
    
    c=*(struct ascii*)a;
    d=*(struct ascii*)b;
    
    if (c.freq != d.freq) {
       return c.freq - d.freq;
    }
    
    return (d.num - c.num);
    
    //return 2;
}

int main()
{
    
    bool first_run = true;
    
    while (gets(linha)) {
          
          for (int i = 0; i < 128; i++) {
              freq[i].freq = 0;
              freq[i].num = i;
          }
    
          if (! first_run) {
                cout << endl;
          }
          else {
               first_run = false;
          }
          
          int tam = strlen(linha);
          
          for (int i = 0; i < tam; i++) {
              ++freq[(int)linha[i]].freq;    
          }     
          
          qsort(freq, 128, sizeof(struct ascii), compare);
          
          
          for (int i = 0; i < 128; i++) {
              if (freq[i].freq != 0) {
                 cout << freq[i].num << " " << freq[i].freq << endl;
              }
          }
          
          
    }
    
    
    return 0;
}
