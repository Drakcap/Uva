#include <iostream>
#include <set>
using namespace std;

long long n;
set<long long> winning;
set<long long> not_winning;

bool can_win(int player, long long p)
{
    set<long long>::iterator it = winning.find(p);
    
    if (it != winning.end()) {
        return true;
    } else {
        set<long long>::iterator it2 = not_winning.find(p);
        
        if (it2 != not_winning.end()) {
            return false;
        }
    
        for (long long i = 9; i >= 2; i--) {
            if (i * p >= n) {
                winning.insert(p);
                return true;
            }
        }
        for (long long i = 9; i >= 2; i--) {
            if (i * p >= n) {
                winning.insert(p);
                return true;
            }
        }
        
        for (long long i = 9; i >= 2; i--) {
            if (! can_win(1-player, i * p)) {
                return true;
            }
        }
    }
    
    not_winning.insert(p);
    return false;
}

int main()
{

    while (cin >> n) {
        winning.clear();
        not_winning.clear();
        if (can_win(0, 1)) {
            cout << "Stan wins." << endl;
        } else {
            cout << "Ollie wins." << endl;
        }
    }

    return 0;
}
