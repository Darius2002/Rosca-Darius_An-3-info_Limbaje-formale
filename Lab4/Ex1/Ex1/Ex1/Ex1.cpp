#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

class NFA {
public:
    set<int> states;
    set<char> alphabet;
    map<int, map<char, set<int>>> transitions;
    set<int> initial_states;
    set<int> final_states;
    bool foundFinalState = false;
    unordered_set<string> uniquePaths;

    void addTransition(int from, char symbol, int to) {
        transitions[from][symbol].insert(to);
    }

    void addFinalState(int state) {
        final_states.insert(state);
    }

    void addInitialState(int state) {
        initial_states.insert(state);
    }

    void exploreEpsilonTransitions(int current_state, set<int>& epsilonClosure) {
        if (epsilonClosure.find(current_state) != epsilonClosure.end()) return;
        epsilonClosure.insert(current_state);

        /*if (transitions[current_state].find('E') != transitions[current_state].end()) {
            for (int next_state : transitions[current_state]['E']) {
                exploreEpsilonTransitions(next_state, epsilonClosure);
            }
        }*/
    }

    void explorePaths(int current_state, string input, int index, string path) {
        path += to_string(current_state) + "-";

        
        if (uniquePaths.find(path) != uniquePaths.end()) return;
        uniquePaths.insert(path);

        set<int> epsilonClosure;
        exploreEpsilonTransitions(current_state, epsilonClosure);

        for (int epsilonState : epsilonClosure) {
            if (epsilonState != current_state) {
                explorePaths(epsilonState, input, index, path);
            }
        }

        if (index == input.size()) {
            if (final_states.find(current_state) != final_states.end()) {
                cout << path << "stare finala" << endl;
                foundFinalState = true;
            }
            else {
                cout << path << "nu este stare finala" << endl;
            }
            return;
        }

        char symbol = input[index];

        if (transitions[current_state].find(symbol) != transitions[current_state].end()) {
            for (int next_state : transitions[current_state][symbol]) {
                explorePaths(next_state, input, index + 1, path);
            }
        }
    }

    void processWord(string input) {
        foundFinalState = false;
        uniquePaths.clear();
        cout << "Intrare: " << input << endl;

        for (int state : initial_states) {
            explorePaths(state, input, 0, "");
        }

        if (!foundFinalState) {
            cout << "Nu am ajuns in nicio stare finala." << endl;
        }
    }
};

int main() {
    NFA nfa;

    nfa.states = { 0, 1, 2, 3, 4 };
    nfa.alphabet = { 'a', 'b' };
    nfa.addInitialState(0);
    nfa.addFinalState(4);

    nfa.addTransition(0, 'a', 1);
    nfa.addTransition(1, 'a', 1);
    nfa.addTransition(1, 'b', 2);
    nfa.addTransition(1, 'a', 2);
    nfa.addTransition(2, 'b', 2);
    nfa.addTransition(2, 'b', 3);
    nfa.addTransition(2, 'a', 3);
    nfa.addTransition(3, 'a', 3);
    nfa.addTransition(3, 'b', 1);
    nfa.addTransition(3, 'a', 4);
    nfa.addTransition(3, 'b', 4);

    string input;
    cout << "Introduceți cuvântul pentru verificare: ";
    cin >> input;

    nfa.processWord(input);

    return 0;
}
