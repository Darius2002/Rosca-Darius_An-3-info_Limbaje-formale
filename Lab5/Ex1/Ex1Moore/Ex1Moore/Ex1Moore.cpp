#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class MooreMachine {
private:
    string state;
    string transitionTable[2][4];
    string outputTable[2];

public:
    MooreMachine() {
        transitionTable[0][0] = "S0";
        transitionTable[0][1] = "S1";
        transitionTable[0][2] = "S0";
        transitionTable[0][3] = "S1";

        transitionTable[1][0] = "S1";
        transitionTable[1][1] = "S1";
        transitionTable[1][2] = "S0";
        transitionTable[1][3] = "S0";


        outputTable[0] = "0";
        outputTable[1] = "1";

        state = "S0";
    }

    string processInput(string input) {
        int inputIndex;
        if (input == "0,0") {
            inputIndex = 0;
        }
        else if (input == "0,1") {
            inputIndex = 1;
        }
        else if (input == "1,0")
        {
            inputIndex = 2;
        }
        else
        {
            inputIndex = 3;
        }


        int stateIndex;
        if (state == "S0") {
            stateIndex = 0;
        }
        else {
            stateIndex = 1;
        }

        state = transitionTable[stateIndex][inputIndex];
        return outputTable[stateIndex];
    }

    void Final() {
        if (state == "S0") {
            cout << "0 ";
        }
        else
        {
            cout << "1 ";
        }

    }
};

bool validateInputSequence(const vector<string>& inputSequence) {
    for (const string& s : inputSequence) {
        if (s != "0,0" && s != "0,1" && s != "1,0" && s != "1,1") {
            return false;
        }
    }
    return true;
}

int main() {
    MooreMachine moore;
    string inputLine;
    vector<string> inputSequence;

    cout << "Input: ";
    getline(cin, inputLine);

    stringstream ss(inputLine);
    string token;
    while (ss >> token) {
        inputSequence.push_back(token);
    }

    if (validateInputSequence(inputSequence)) {
        cout << "Output: ";
        for (const string& input : inputSequence) {
            cout << moore.processInput(input) << " ";
        }
        moore.Final();
        cout << endl;
    }
    else {
        cout << "Eroare la input!!!" << endl;
    }

    return 0;
}
