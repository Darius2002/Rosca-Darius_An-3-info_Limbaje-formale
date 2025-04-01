#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class MealyMachine {
private:
    string state;
    string transitionTable[2][4];
    string outputTable[2][4];

public:
    MealyMachine() {
        transitionTable[0][0] = "S0"; 
        transitionTable[0][1] = "S1";  
        transitionTable[0][2] = "S0";
        transitionTable[0][3] = "S1";

        transitionTable[1][0] = "S1";
        transitionTable[1][1] = "S1";
        transitionTable[1][2] = "S0";
        transitionTable[1][3] = "S0";


        outputTable[0][0] = "0";  
        outputTable[0][1] = "1";  
        outputTable[0][2] = "0";  
        outputTable[0][3] = "1";

        outputTable[1][0] = "1";
        outputTable[1][1] = "1";
        outputTable[1][2] = "0";
        outputTable[1][3] = "0";


        state = "S0";
    }

    string processInput(string input) {
        int inputIndex;
        if (input == "0,0") {
            inputIndex = 0;
        }
        else if (input == "0,1"){
            inputIndex = 1;
        }
        else if(input == "1,0")
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
        return outputTable[stateIndex][inputIndex];
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
    MealyMachine mealy;
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
            cout << mealy.processInput(input) << " ";
        }
        cout << endl;
    }
    else {
        cout << "Eroare la input!!!" << endl;
    }

    return 0;
}
