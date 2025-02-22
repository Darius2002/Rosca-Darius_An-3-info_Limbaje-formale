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
            {1, 2},
            {3, 0}, 
            {1, 3}, 
            {3, 3}  
        };

        initial_state = 0; 
        final_state = 3;   
    }

    bool processInput(const string& input) {
        int state = initial_state; 

        for (char symbol : input) {
            if (symbol != '0' && symbol != '1') { 
                cout << "Eroare: Input incorect" << endl;
                return false;
            }
            state = transitions[state][symbol - '0']; 
        }

        return state == final_state; 
    }
};

int main() {
    Automaton automaton;
    string input;

    cout << "Introduceti un sir binar: ";
    cin >> input;

    bool result = automaton.processInput(input);

    if (result) {
        cout << "Sirul este acceptat";
    }
    else
    {
        cout << "Sirul este respins";
    }

    return 0;
}
