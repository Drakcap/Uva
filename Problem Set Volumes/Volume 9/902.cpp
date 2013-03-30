#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, int> passwords;
string best;
int bestOcurr;
int N;
int alfa = 'z' - 'a' + 1;
int alfaToNminus1;
string message;

int calculateHash(int lastHash, int ixStart, int ixEnd)
{
    int hash = 0;

    if (lastHash == -1) {
        int exp = 1;
        for (int i = ixEnd; i >= ixStart; i--) {
            alfaToNminus1 = exp;
            hash += exp * (message[i] - 'a');
            exp *= alfa;
        }
        //cout << alfaToNminus1 << endl;
    } else {
        hash = (lastHash - (message[ixStart-1]-'a') * alfaToNminus1) * alfa + (message[ixEnd] - 'a');
    }
    //cout << hash << endl;
    return hash;
}

int main()
{
    int hash, lastHash = -1;

    while (cin >> N) {
        cin >> message;
        passwords.clear();
        best = "";
        bestOcurr = 0;
        lastHash = -1;
        
        for (int i = N; i <= message.size(); i++) {
            hash = calculateHash(lastHash, i-N, i-1);
            
            map<int, int>::iterator it = passwords.find(hash);
            
            if (it != passwords.end()) {
                ++it->second;
                if (it->second > bestOcurr) {
                    bestOcurr = it->second;
                    best = message.substr(i-N, N);
                }
            } else {
                passwords.insert(make_pair(hash, 1));
                if (bestOcurr == 0) {
                    bestOcurr = 1;
                    best = message.substr(i-N, N);
                }
            }
            lastHash = hash;
        }
        
        cout << best << endl;
    }


    return 0;
}
