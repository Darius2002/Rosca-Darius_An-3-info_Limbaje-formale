#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include <algorithm> 

using namespace std;

void splitWords(const string& sir, vector<string>& vec) {
    stringstream ss(sir);
    string cuvant;
    while (ss >> cuvant) {
        vec.push_back(cuvant);
    }
}

void afisareVector(const vector<string>& vec, const string& mesaj) {
    cout << mesaj << ":\n";
    for (const string& s : vec) {
        cout << s << ' ';
    }
    cout << "\n";
}

void afisareInversaVector(const vector<string>& vec, const string& mesaj) {
    cout << mesaj << " (inversat):\n";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << ' ';
    }
    cout << "\n";
}

void afisareLungimeVector(const vector<string>& vec, const string& mesaj) {
    cout << mesaj << " are lungimea: " << vec.size() << "\n";
}

vector<string> reuniune(const vector<string>& v1, const vector<string>& v2) {
    set<string> rezultat(v1.begin(), v1.end());
    rezultat.insert(v2.begin(), v2.end());
    return vector<string>(rezultat.begin(), rezultat.end());
}

vector<string> intersectie(const vector<string>& v1, const vector<string>& v2) {
    set<string> set1(v1.begin(), v1.end());
    set<string> set2(v2.begin(), v2.end());
    vector<string> rezultat;

    for (const string& elem : set1) {
        if (set2.find(elem) != set2.end()) {
            rezultat.push_back(elem);
        }
    }
    return rezultat;
}

vector<string> diferenta(const vector<string>& v1, const vector<string>& v2) {
    set<string> set1(v1.begin(), v1.end());
    set<string> set2(v2.begin(), v2.end());
    vector<string> rezultat;

    for (const string& elem : set1) {
        if (set2.find(elem) == set2.end()) {
            rezultat.push_back(elem);
        }
    }
    return rezultat;
}

int main() {
    string L1, L2;
    vector<string> v1, v2;

    cout << "Introdu primul sir (L1): ";
    getline(cin, L1);

    cout << "Introdu al doilea sir (L2): ";
    getline(cin, L2);

    splitWords(L1, v1);
    splitWords(L2, v2);

    int optiune;
    do {
        cout << "1. Reuniunea L1 U L2\n";
        cout << "2. Intersectia L1 n L2\n";
        cout << "3. Diferenta L1 - L2\n";
        cout << "4. Diferenta L2 - L1\n";
        cout << "5. Afisare vectori\n";
        cout << "6. Afisare vectori inversa\n";
        cout << "7. Afisare lungime vectori\n"; 
        cout << "0. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;
        cout << "\n";
        cin.ignore();

        switch (optiune) {
        case 1:
            afisareVector(reuniune(v1, v2), "Reuniunea L1 U L2");
            break;
        case 2:
            afisareVector(intersectie(v1, v2), "Intersectia L1 n L2");
            break;
        case 3:
            afisareVector(diferenta(v1, v2), "Diferenta L1 - L2");
            break;
        case 4:
            afisareVector(diferenta(v2, v1), "Diferenta L2 - L1");
            break;
        case 5:
            afisareVector(v1, "Vector L1");
            afisareVector(v2, "Vector L2");
            break;
        case 6:
            afisareInversaVector(v1, "Vector L1");
            afisareInversaVector(v2, "Vector L2");
            break;
        case 7:
            afisareLungimeVector(v1, "Lungimea vectorului L1");
            afisareLungimeVector(v2, "Lungimea vectorului L2");
            break;
        case 0:
            cout << "Iesire din program.\n";
            break;
        default:
            cout << "Optiune invalida! Alege din nou.\n";
            break;
        }
        cout << "\n";
    } while (optiune != 0);

    return 0;
}
