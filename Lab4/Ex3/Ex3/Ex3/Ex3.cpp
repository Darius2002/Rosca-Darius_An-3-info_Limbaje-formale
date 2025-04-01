#include <iostream>
using namespace std;

class MealyMachine {
private:
    string state;
    string transitionTable[2][2];  
    string outputTable[2][2];        

public:
    MealyMachine() {
        transitionTable[0][0] = "Q2";  // Q1 cu 'X' duce la Q2
        transitionTable[0][1] = "Q1";  // Q1 cu 'Y' duce la Q1
        transitionTable[1][0] = "Q1";  // Q2 cu 'X' duce la Q1
        transitionTable[1][1] = "Q2";  // Q2 cu 'Y' duce la Q2

        outputTable[0][0] = "O1";  // Q1 cu 'X' => O1
        outputTable[0][1] = "O1";  // Q1 cu 'Y' => O1
        outputTable[1][0] = "O2";  // Q2 cu 'X' => O2
        outputTable[1][1] = "O2";  // Q2 cu 'Y' => O2

        state = "Q1";
    }

    string processInput(char input) {
        int inputIndex;
        if (input == 'X') {
            inputIndex = 0;
        }
        else {
            inputIndex = 1;
        }

        int stateIndex;
        if (state == "Q1") {
            stateIndex = 0;  
        }
        else {
            stateIndex = 1;  
        }

        state = transitionTable[stateIndex][inputIndex];
        return outputTable[stateIndex][inputIndex];
    }
};

bool validateInputSequence(const string& inputSequence) {

    for (char c : inputSequence) {
        if (c != 'X' && c != 'Y') {
            return false;
        }
    }
    return true;
}

int main() {
    MealyMachine mealy;
    string inputSequence;
    cout << "Input: ";
    cin >> inputSequence;

    if (validateInputSequence(inputSequence)) {
        cout << "Output: ";
        for (char input : inputSequence) {
            cout << mealy.processInput(input) << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Eroare la input!!!";
    }

    return 0;
}
