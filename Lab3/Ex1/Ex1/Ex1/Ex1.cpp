#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>

using namespace std;

class Automaton {
private:
    vector<vector<int>> transitions;
    int initial_state;
    int final_state;

public:
    Automaton() {
        transitions = {
            {1, 2, 3, 4},
            {4},
            {4},
            {4},
            {0}
        };

        initial_state = 0;
        final_state = 4;
    }

    int processInput(const string& input) {
        int state = initial_state;

        for (char symbol : input) {

            int symbolIndex = symbol - '0';

            if (symbolIndex >= 0 && symbolIndex < transitions[state].size()) {
                state = transitions[state][symbolIndex];
            }
        }

        return state;
    }
};


bool isValidString(const string& str) {
    regex pattern("^(C|T|A|H|OK)*$");
    return regex_match(str, pattern);
}

string convertString(const string& str) {
    unordered_map<string, string> mapping = {
        {"C", "1"}, {"T", "2"}, {"A", "3"}, {"H", "4"}, {"OK", "0"}
    };

    string result;
    size_t i = 0;

    while (i < str.size()) {
        
        if (i + 1 < str.size() && str.substr(i, 2) == "OK") {
            result += "0";
            i += 2;  
        }
        else {
            string current_char(1, str[i]);
            if (mapping.find(current_char) != mapping.end()) {
                result += mapping[current_char];
            }
            i++;
        }
    }

    return result;
}

int main() {
    Automaton automaton;
    string input;
    
    
    cout << "Scrieti lista de operatii:" << endl;
    cin >> input;

    if (isValidString(input)) {
        
        string a = convertString(input);
        int nr = automaton.processInput(a);
        if (nr == 4) {
            cout << "Am ajuns in starea finala si ne am oprint";
        }
        else {
            cout << "Nu ne am oprit in starea finala";
        }
    }
    else
    {
        cout << "lista gresita!!!" << endl;
    }


    return 0;
}
