#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>  

using namespace std;

class Automaton {
private:
    vector<vector<int>> transitions;
    int initial_state;
    int final_state;

public:
    Automaton() {


        transitions = {
            {1, 0, 0, 0},
            {1, 2, 1, 1},
            {2, 2, 2, 3},
            {3, 3, 3, 3},
        };

        initial_state = 0;
        final_state = 3;
    }

    bool processInput(const string& input) {
        int state = initial_state;

        for (char symbol : input) {

            if (symbol != 'a' && symbol != 'b' && symbol != 'c' && symbol != 'd') {
                cout << "Eroare" << endl;
                return false;
            }

            int index = symbol - 'a';
            state = transitions[state][index];

            if (state == final_state) {
                return true;
            }
        }

        return false;
    }
};


vector<string> generateWords() {
    vector<char> alphabet = { 'a', 'b', 'c', 'd' };
    vector<string> words;

    for (int i = 0; i < alphabet.size(); ++i) {
        for (int j = 0; j < alphabet.size(); ++j) {
            for (int k = 0; k < alphabet.size(); ++k) {
                string word = string(1, alphabet[i]) + string(1, alphabet[i]) +
                    string(1, alphabet[j]) + string(1, alphabet[j]) +
                    string(1, alphabet[k]) + string(1, alphabet[k]);
                words.push_back(word);
            }
        }
    }

    return words;
}


int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<string> words = generateWords();
    Automaton automaton;

    /*cout << "Cuvintele generate din limbajul L sunt:" << endl;
    for (const string& word : words) {
        cout << word << endl;
    }
    */

    for (int i = 0; i < 3; ++i) {

        int index = rand() % words.size();

        bool r = automaton.processInput(words[index]);
        if (r) {
            cout << "Cuvantul " << words[index] << " face parte din L" << endl;
        }
        else {
            cout << "Cuvantul " << words[index] << " nu face parte din L" << endl;
        }
    }



    return 0;
}
