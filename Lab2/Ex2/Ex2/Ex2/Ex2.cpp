#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Automaton {
private:
    vector<vector<int>> transitions;
    int initial_state;
    int final_state;

public:
    Automaton() {
       
        
        transitions = {
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
            {2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0}, 
            {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}, 
        };

        initial_state = 0; 
        final_state = 3;   
    }

    bool processInput(const string& input) {
        int state = initial_state;

        for (char symbol : input) {
            
            if (symbol < 'a' || symbol > 'z') {
                cout << "Eroare: Introduceti doar litere mici" << endl;
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

int main() {
    Automaton automaton;
    string input;

    cout << "Introduceti un sir de caractere: ";
    cin >> input;

    bool result = automaton.processInput(input);

    if (result) {
        cout << "Cuvantul 'cat' a fost gasit!" << endl;
    }
    else {
        cout << "Cuvantul 'cat' nu a fost gasit." << endl;
    }

    return 0;
}
