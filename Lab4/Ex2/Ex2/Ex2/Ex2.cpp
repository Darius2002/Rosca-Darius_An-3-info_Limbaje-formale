#include <iostream>
using namespace std;

class MooreMachine {
private:
    string state;
    string transitionTable[2][2]; 
    string outputTable[2]; 

public:
    MooreMachine() {
       
        transitionTable[0][0] = "S1";  // S1 cu input A duce la S1
        transitionTable[0][1] = "S2";  // S1 cu input B duce la S2
        transitionTable[1][0] = "S1";  // S2 cu input A duce la S1
        transitionTable[1][1] = "S2";  // S2 cu input B duce la S2

        
        outputTable[0] = "O1";  
        outputTable[1] = "O2"; 

        
        state = "S1";
    }

    string processInput(char input) {
      
        int inputIndex;
        if (input == 'A') {
            inputIndex = 0;
        }
        else {
            inputIndex = 1;
        }

     
        int stateIndex;
        if (state == "S1") {
            stateIndex = 0; 
        }
        else {
            stateIndex = 1; 
        }

       
        state = transitionTable[stateIndex][inputIndex];

        
        if (state == "S1") {
            return outputTable[0]; 
        }
        else {
            return outputTable[1]; 
        }
    }

};


bool validateInputSequence(const string& inputSequence) {
    
    for (char c : inputSequence) {
        if (c != 'A' && c != 'B') {
            return false; 
        }
    }
    return true; 
}

int main() {
    MooreMachine moore;
    string inputSequence;
    cout << "Input: ";
    cin >> inputSequence;

    if (validateInputSequence(inputSequence)) {
        cout << "Output: ";
        for (char input : inputSequence) {
            cout << moore.processInput(input) << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Eroare la input!!!";
    }

    return 0;
}
