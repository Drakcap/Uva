#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Word {
    string word;   
    string lower;
    
    bool operator<(const Word &w) const {
        return lower < w.lower;    
    }
    
};

Word words[1200];
int nwords;
string sol[1200];
int tamSol;

string tolower(string &s)
{
    string nova = s;
        
    for (size_t i = 0; i < s.size(); i++) {
        nova[i] = tolower(nova[i]);   
    }
    sort(nova.begin(), nova.end());
    return nova;
}

int main()
{
    string word;
    
    while (cin >> word && word != "#") {
            words[nwords].word = word;
            words[nwords++].lower = tolower(word);
    }
    sort(words, words+nwords);
    
    int last = 0;
    words[nwords].lower = "#";
    
    for (int i = 1; i <= nwords; i++) {
        if (words[i].lower != words[i-1].lower) {
            if (last == i-1) {
                sol[tamSol++] = words[i-1].word;            
            }
            last = i;
        }
    }
    sort(sol, sol+tamSol);
    
    for (int i = 0; i < tamSol; i++) {
        cout << sol[i] << endl;   
    }
    
    
}
