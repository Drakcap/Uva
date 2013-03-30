#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int n_words = 0;
string words[2000];

string phrase;
vector<string> phrase_words;
char letters[20];
int n_letters;

struct state {
    bool is_filled[20];
    int used_words[20];
    int n_used_words;
    int to_fill;
};

void 
debug(string variable, string value) {
    cout << variable << ": " << value << endl;
}

void 
debug(string variable, int value) {
    cout << variable << ": " << value << endl;
}

bool 
is_complete(state &st) {
    //do not include the set of the original words
    bool has_differences = false;
    
    for (int i = 0; i < phrase_words.size(); i++) {
        if (i >= st.n_used_words) {
            has_differences = true;
            break;
        }
        if (phrase_words[i] != words[st.used_words[i]]) {
            has_differences = true;
            break;
        }
    }
    
    if (!has_differences) {
        return false;
    }
    
    return st.to_fill == 0;    
}

void 
print_state(state &st) {
    cout << phrase << " =";
    
    for (int i = 0; i < st.n_used_words; i++) {
        cout << " " << words[st.used_words[i]];
    }
    
    cout << endl;
}

bool 
can_use_word(state st, int word) {
    if(words[word].size() > st.to_fill) {
        return false;
    }
    
    //PROBABLY THIS CAN BE IMPROVED IF WE SORT THE LETTERS IN THE STATE
    for (int i = 0; i < words[word].size(); i++) {
        bool letter_used = false;
        
        for (int j = 0; j < n_letters; j++) {
            if (words[word][i] == letters[j] && ! st.is_filled[j]) {
                st.is_filled[j] = true;
                letter_used = true;
                break;
            }            
        }
        
        if (! letter_used) {
            return false;
        }
    }
    //debug("USING (WORD, PHRASE)", "(" + words[word] + ", " + phrase + ")");
    //debug("WORD", words[word]);
    return true;
}

state 
use_word(state st, int word) {
    st.used_words[st.n_used_words++] = word;

    for (int i = 0; i < words[word].size(); i++) {
        for (int j = 0; j < n_letters; j++) {
            if (words[word][i] == letters[j] && !st.is_filled[j]) {
                st.is_filled[j] = true;
                --st.to_fill;
                break;
            }            
        }
    }
    
    return st;
}

bool
can_prune(state &st, int current_word) {
    if (current_word >= n_words) {
        return true;
    }
    
    return false;
}

//PASS BY REFERENCE
void 
go(state current_state, int current_word) {
    if (is_complete(current_state)) {
        print_state(current_state); //found a solution
        return;
    }
    
    if (can_prune(current_state, current_word)) {
        return;
    }

    state state_snapshot = current_state;
    
    if (can_use_word(current_state, current_word)) {
        go(use_word(current_state, current_word), current_word + 1);
    }

    //try without using the current word
    go(state_snapshot, current_word + 1);
}

int 
main() 
{
    //handle input
    string line, word, phrase_word;
    
    //read dictionary
    while (getline(cin, line)) {
        istringstream stream(line);
        stream >> word;
        
        //end of dictionary
        if (word == "#") {
            break;
        }
        
        words[n_words++] = word;
    }
    
    //read words and calculate anagrams for each word
    while (getline(cin, line)) {
        istringstream stream(line);
        stream >> phrase_word;
        
        //end of phrases
        if (phrase_word == "#" && stream.eof()) {
            break;
        }
        
        state initial_state;
        phrase = "";
        n_letters = 0;
        initial_state.n_used_words = 0;
        
        for (int i = 0; i < line.size(); i++) {
            if (! isspace(line[i])) {
                phrase += line[i];
                initial_state.is_filled[n_letters] = false;
                letters[n_letters++] = line[i];
            } else if (line[i] == ' ' && i != line.size()-1) {
                phrase += line[i];
            }
        }
        
        istringstream stream2(line);
        phrase_words.clear();

        while (stream2 >> phrase_word) {
            phrase_words.push_back(phrase_word);
        }
        
        sort(phrase_words.begin(), phrase_words.end());
        
        initial_state.to_fill = n_letters;
        //cout << "initial_state phrase: " << initial_state.phrase << endl;
        go(initial_state, 0);
    }

    return 0;
}
